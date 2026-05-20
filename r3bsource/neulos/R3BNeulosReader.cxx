#include "FairLogger.h"
#include "FairRootManager.h"

#include "R3BLogger.h"
#include "R3BNeulosMappedData.h"
#include "R3BNeulosReader.h"

#include "TClonesArray.h"
#include "ext_data_struct_info.hh"

#include <cstring>

/**
 ** Adjust this include if your generated UCESB header has a different name.
 **
 ** Example generation command might have used:
 **   id=h101_NEULOS
 **/

extern "C"
{
#include "ext_data_client.h"
#include "ext_h101_neulos.h"
}

R3BNeulosReader::R3BNeulosReader(EXT_STR_h101_NEULOS_onion* data, size_t offset)
    : R3BReader("R3BNeulosReader")
    , fNEvent(1)
    , fData(data)
    , fOffset(offset)
    , fOnline(kFALSE)
    , fArray(new TClonesArray("R3BNeulosMappedData"))
{
}

R3BNeulosReader::~R3BNeulosReader()
{
    R3BLOG(debug1, "");

    if (fArray)
    {
        delete fArray;
    }
}

Bool_t R3BNeulosReader::Init(ext_data_struct_info* a_struct_info)
{
    Int_t ok;

    R3BLOG(info, "");

    EXT_STR_h101_NEULOS_ITEMS_INFO(ok, *a_struct_info, fOffset, EXT_STR_h101_NEULOS, 0);

    R3BLOG_IF(fatal, !ok, "Failed to setup NEULOS structure information.");

    FairRootManager::Instance()->Register("NeulosMappedData", "NEULOS_Map", fArray, !fOnline);

    Reset();

    memset(fData, 0, sizeof(*fData));

    return kTRUE;
}

Bool_t R3BNeulosReader::R3BRead()
{
    R3BLOG(debug1, "Event data: " << fNEvent);

    /*
     * Mapped format:
     *
     * side:
     *   0 = TF
     *   1 = TS
     *
     * type:
     *   0 = normal signal
     *   1 = trigger signal
     *
     * edge:
     *   0 = leading edge
     *   1 = trailing edge
     *
     * UCESB grouped layout:
     *
     *   M   = number of channel groups
     *   MI  = channel index, 1-based
     *   ME  = end index into value arrays
     *   v   = value array
     *
     * For group c:
     *
     *   start = c > 0 ? ME[c - 1] : 0
     *   end   = ME[c]
     */

    auto AddLeadingEdges = [this](UInt_t side,
                                  UInt_t type,
                                  UInt_t nChan,
                                  const UInt_t* chanMI,
                                  const UInt_t* chanME,
                                  const UInt_t* coarseV,
                                  const UInt_t* fineV) {
        for (UInt_t c = 0; c < nChan; c++)
        {
            if (chanMI[c] == 0)
            {
                R3BLOG(warn,
                       "NEULOS leading edge has zero channel index for side " << side
                                                                              << ", type " << type
                                                                              << ", group " << c);
                continue;
            }

            const UInt_t channel = chanMI[c] - 1;
            const UInt_t start = c > 0 ? chanME[c - 1] : 0;
            const UInt_t end = chanME[c];

            if (end < start)
            {
                R3BLOG(error,
                       "NEULOS leading edge invalid ME ordering for side " << side
                                                                           << ", type " << type
                                                                           << ", group " << c
                                                                           << " : start=" << start
                                                                           << " end=" << end);
                continue;
            }

            for (UInt_t m = start; m < end; m++)
            {
                const UInt_t coarse = coarseV[m];
                const UInt_t fine = fineV[m];

                new ((*fArray)[fArray->GetEntriesFast()])
                    R3BNeulosMappedData(side, type, channel, 0, coarse, fine);
            }
        }
    };

    auto AddTrailingEdges = [this](UInt_t side,
                                   UInt_t type,
                                   UInt_t nChan,
                                   const UInt_t* chanMI,
                                   const UInt_t* chanME,
                                   const UInt_t* coarseV,
                                   const UInt_t* fineV) {
        for (UInt_t c = 0; c < nChan; c++)
        {
            if (chanMI[c] == 0)
            {
                R3BLOG(warn,
                       "NEULOS trailing edge has zero channel index for side " << side
                                                                               << ", type " << type
                                                                               << ", group " << c);
                continue;
            }

            const UInt_t channel = chanMI[c] - 1;
            const UInt_t start = c > 0 ? chanME[c - 1] : 0;
            const UInt_t end = chanME[c];

            if (end < start)
            {
                R3BLOG(error,
                       "NEULOS trailing edge invalid ME ordering for side " << side
                                                                            << ", type " << type
                                                                            << ", group " << c
                                                                            << " : start=" << start
                                                                            << " end=" << end);
                continue;
            }

            for (UInt_t m = start; m < end; m++)
            {
                const UInt_t coarse = coarseV[m];
                const UInt_t fine = fineV[m];

                new ((*fArray)[fArray->GetEntriesFast()])
                    R3BNeulosMappedData(side, type, channel, 1, coarse, fine);
            }
        }
    };

    // ------------------------------------------------------------------
    // TF normal
    // side = 0, type = 0
    // ------------------------------------------------------------------

    AddLeadingEdges(0,
                    0,
                    fData->tamex_four_TFLFM,
                    fData->tamex_four_TFLFMI,
                    fData->tamex_four_TFLFME,
                    fData->tamex_four_TFLCv,
                    fData->tamex_four_TFLFv);

    AddTrailingEdges(0,
                     0,
                     fData->tamex_four_TFTFM,
                     fData->tamex_four_TFTFMI,
                     fData->tamex_four_TFTFME,
                     fData->tamex_four_TFTCv,
                     fData->tamex_four_TFTFv);

    // ------------------------------------------------------------------
    // TS normal
    // side = 1, type = 0
    // ------------------------------------------------------------------

    AddLeadingEdges(1,
                    0,
                    fData->tamex_four_TSLFM,
                    fData->tamex_four_TSLFMI,
                    fData->tamex_four_TSLFME,
                    fData->tamex_four_TSLCv,
                    fData->tamex_four_TSLFv);

    AddTrailingEdges(1,
                     0,
                     fData->tamex_four_TSTFM,
                     fData->tamex_four_TSTFMI,
                     fData->tamex_four_TSTFME,
                     fData->tamex_four_TSTCv,
                     fData->tamex_four_TSTFv);

    // ------------------------------------------------------------------
    // TF trigger
    // side = 0, type = 1
    //
    // Your dump only showed:
    //   tamex_four_TRIGTFLCM
    //   tamex_four_TRIGTFLC
    //   tamex_four_TRIGTFLFM
    //   tamex_four_TRIGTFLF
    //
    // This assumes the generated header also has:
    //   tamex_four_TRIGTFLFMI
    //   tamex_four_TRIGTFLFME
    //   tamex_four_TRIGTFLCv
    //   tamex_four_TRIGTFLFv
    //
    // No trigger trailing edge was shown in your list, so only leading
    // trigger edges are read here.
    // ------------------------------------------------------------------

    AddLeadingEdges(0,
                    1,
                    fData->tamex_four_TRIGTFLFM,
                    fData->tamex_four_TRIGTFLFMI,
                    fData->tamex_four_TRIGTFLFME,
                    fData->tamex_four_TRIGTFLCv,
                    fData->tamex_four_TRIGTFLFv);

    fNEvent++;

    return kTRUE;
}

void R3BNeulosReader::Reset()
{
    if (fArray)
    {
        fArray->Clear();
    }
}

ClassImp(R3BNeulosReader)
