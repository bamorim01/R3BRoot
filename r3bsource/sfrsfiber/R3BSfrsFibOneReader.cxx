#include "FairLogger.h"
#include "FairRootManager.h"

#include "R3BLogger.h"
#include "R3BSfrsFibOneMappedData.h"
#include "R3BSfrsFibOneReader.h"

#include "TClonesArray.h"
#include "ext_data_struct_info.hh"

#include <cstring>

/**
 ** ext_h101_sfrs_fib_one.h should be generated with the matching id/name.
 ** Adjust the include name if your generated header has a different filename.
 **/

extern "C"
{
#include "ext_data_client.h"
#include "ext_h101_sfrs_fib_one.h"
}

R3BSfrsFibOneReader::R3BSfrsFibOneReader(EXT_STR_h101_SFRS_FIB_ONE_onion* data, size_t offset)
    : R3BReader("R3BSfrsFibOneReader")
    , fNEvent(1)
    , fData(data)
    , fOffset(offset)
    , fOnline(kFALSE)
    , fArray(new TClonesArray("R3BSfrsFibOneMappedData"))
{
}

R3BSfrsFibOneReader::~R3BSfrsFibOneReader()
{
    R3BLOG(debug1, "");

    if (fArray)
    {
        delete fArray;
    }
}

Bool_t R3BSfrsFibOneReader::Init(ext_data_struct_info* a_struct_info)
{
    Int_t ok;

    R3BLOG(info, "");

    EXT_STR_h101_SFRS_FIB_ONE_ITEMS_INFO(ok, *a_struct_info, fOffset, EXT_STR_h101_SFRS_FIB_ONE, 0);

    R3BLOG_IF(fatal, !ok, "Failed to setup SFRS_FIB_ONE structure information.");

    FairRootManager::Instance()->Register("SfrsFibOneMappedData", "SFRS_FIB_ONE_Map", fArray, !fOnline);

    Reset();

    memset(fData, 0, sizeof(*fData));

    return kTRUE;
}

Bool_t R3BSfrsFibOneReader::R3BRead()
{
    R3BLOG(debug1, "Event data: " << fNEvent);

    /*
     * Mapped format:
     *
     * side:
     *   0 = DOWN
     *   1 = UP
     *   2 = RIGHT
     *   3 = LEFT
     *
     * type:
     *   0 = normal signal
     *   1 = trigger signal
     *
     * edge:
     *   0 = leading
     *   1 = trailing
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
                       "SFRS_FIB_ONE leading edge has zero channel index for side " << side
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
                       "SFRS_FIB_ONE leading edge invalid ME ordering for side " << side
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
                    R3BSfrsFibOneMappedData(side, type, channel, 0, coarse, fine);
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
                       "SFRS_FIB_ONE trailing edge has zero channel index for side " << side
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
                       "SFRS_FIB_ONE trailing edge invalid ME ordering for side " << side
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
                    R3BSfrsFibOneMappedData(side, type, channel, 1, coarse, fine);
            }
        }
    };

    // ------------------------------------------------------------------
    // DOWN normal
    // side = 0, type = 0
    // ------------------------------------------------------------------

    AddLeadingEdges(0,
                    0,
                    fData->SFRS_FIB_ONE_DOWN_LFM,
                    fData->SFRS_FIB_ONE_DOWN_LFMI,
                    fData->SFRS_FIB_ONE_DOWN_LFME,
                    fData->SFRS_FIB_ONE_DOWN_LCv,
                    fData->SFRS_FIB_ONE_DOWN_LFv);

    AddTrailingEdges(0,
                     0,
                     fData->SFRS_FIB_ONE_DOWN_TFM,
                     fData->SFRS_FIB_ONE_DOWN_TFMI,
                     fData->SFRS_FIB_ONE_DOWN_TFME,
                     fData->SFRS_FIB_ONE_DOWN_TCv,
                     fData->SFRS_FIB_ONE_DOWN_TFv);

    // ------------------------------------------------------------------
    // UP normal
    // side = 1, type = 0
    // ------------------------------------------------------------------

    AddLeadingEdges(1,
                    0,
                    fData->SFRS_FIB_ONE_UP_LFM,
                    fData->SFRS_FIB_ONE_UP_LFMI,
                    fData->SFRS_FIB_ONE_UP_LFME,
                    fData->SFRS_FIB_ONE_UP_LCv,
                    fData->SFRS_FIB_ONE_UP_LFv);

    AddTrailingEdges(1,
                     0,
                     fData->SFRS_FIB_ONE_UP_TFM,
                     fData->SFRS_FIB_ONE_UP_TFMI,
                     fData->SFRS_FIB_ONE_UP_TFME,
                     fData->SFRS_FIB_ONE_UP_TCv,
                     fData->SFRS_FIB_ONE_UP_TFv);

    // ------------------------------------------------------------------
    // RIGHT normal
    // side = 2, type = 0
    // ------------------------------------------------------------------

    AddLeadingEdges(2,
                    0,
                    fData->SFRS_FIB_ONE_RIGHT_LFM,
                    fData->SFRS_FIB_ONE_RIGHT_LFMI,
                    fData->SFRS_FIB_ONE_RIGHT_LFME,
                    fData->SFRS_FIB_ONE_RIGHT_LCv,
                    fData->SFRS_FIB_ONE_RIGHT_LFv);

    AddTrailingEdges(2,
                     0,
                     fData->SFRS_FIB_ONE_RIGHT_TFM,
                     fData->SFRS_FIB_ONE_RIGHT_TFMI,
                     fData->SFRS_FIB_ONE_RIGHT_TFME,
                     fData->SFRS_FIB_ONE_RIGHT_TCv,
                     fData->SFRS_FIB_ONE_RIGHT_TFv);

    // ------------------------------------------------------------------
    // LEFT normal
    // side = 3, type = 0
    // ------------------------------------------------------------------

    AddLeadingEdges(3,
                    0,
                    fData->SFRS_FIB_ONE_LEFT_LFM,
                    fData->SFRS_FIB_ONE_LEFT_LFMI,
                    fData->SFRS_FIB_ONE_LEFT_LFME,
                    fData->SFRS_FIB_ONE_LEFT_LCv,
                    fData->SFRS_FIB_ONE_LEFT_LFv);

    AddTrailingEdges(3,
                     0,
                     fData->SFRS_FIB_ONE_LEFT_TFM,
                     fData->SFRS_FIB_ONE_LEFT_TFMI,
                     fData->SFRS_FIB_ONE_LEFT_TFME,
                     fData->SFRS_FIB_ONE_LEFT_TCv,
                     fData->SFRS_FIB_ONE_LEFT_TFv);

    // ------------------------------------------------------------------
    // DOWN trigger
    // side = 0, type = 1
    // ------------------------------------------------------------------

    AddLeadingEdges(0,
                    1,
                    fData->SFRS_FIB_ONE_DOWN_TRIGLFM,
                    fData->SFRS_FIB_ONE_DOWN_TRIGLFMI,
                    fData->SFRS_FIB_ONE_DOWN_TRIGLFME,
                    fData->SFRS_FIB_ONE_DOWN_TRIGLCv,
                    fData->SFRS_FIB_ONE_DOWN_TRIGLFv);

    AddTrailingEdges(0,
                     1,
                     fData->SFRS_FIB_ONE_DOWN_TRIGTFM,
                     fData->SFRS_FIB_ONE_DOWN_TRIGTFMI,
                     fData->SFRS_FIB_ONE_DOWN_TRIGTFME,
                     fData->SFRS_FIB_ONE_DOWN_TRIGTCv,
                     fData->SFRS_FIB_ONE_DOWN_TRIGTFv);

    // ------------------------------------------------------------------
    // UP trigger
    // side = 1, type = 1
    // ------------------------------------------------------------------

    AddLeadingEdges(1,
                    1,
                    fData->SFRS_FIB_ONE_UP_TRIGLFM,
                    fData->SFRS_FIB_ONE_UP_TRIGLFMI,
                    fData->SFRS_FIB_ONE_UP_TRIGLFME,
                    fData->SFRS_FIB_ONE_UP_TRIGLCv,
                    fData->SFRS_FIB_ONE_UP_TRIGLFv);

    AddTrailingEdges(1,
                     1,
                     fData->SFRS_FIB_ONE_UP_TRIGTFM,
                     fData->SFRS_FIB_ONE_UP_TRIGTFMI,
                     fData->SFRS_FIB_ONE_UP_TRIGTFME,
                     fData->SFRS_FIB_ONE_UP_TRIGTCv,
                     fData->SFRS_FIB_ONE_UP_TRIGTFv);

    // ------------------------------------------------------------------
    // RIGHT trigger
    // side = 2, type = 1
    // ------------------------------------------------------------------

    AddLeadingEdges(2,
                    1,
                    fData->SFRS_FIB_ONE_RIGHT_TRIGLFM,
                    fData->SFRS_FIB_ONE_RIGHT_TRIGLFMI,
                    fData->SFRS_FIB_ONE_RIGHT_TRIGLFME,
                    fData->SFRS_FIB_ONE_RIGHT_TRIGLCv,
                    fData->SFRS_FIB_ONE_RIGHT_TRIGLFv);

    AddTrailingEdges(2,
                     1,
                     fData->SFRS_FIB_ONE_RIGHT_TRIGTFM,
                     fData->SFRS_FIB_ONE_RIGHT_TRIGTFMI,
                     fData->SFRS_FIB_ONE_RIGHT_TRIGTFME,
                     fData->SFRS_FIB_ONE_RIGHT_TRIGTCv,
                     fData->SFRS_FIB_ONE_RIGHT_TRIGTFv);

    // ------------------------------------------------------------------
    // LEFT trigger
    // side = 3, type = 1
    // ------------------------------------------------------------------

    AddLeadingEdges(3,
                    1,
                    fData->SFRS_FIB_ONE_LEFT_TRIGLFM,
                    fData->SFRS_FIB_ONE_LEFT_TRIGLFMI,
                    fData->SFRS_FIB_ONE_LEFT_TRIGLFME,
                    fData->SFRS_FIB_ONE_LEFT_TRIGLCv,
                    fData->SFRS_FIB_ONE_LEFT_TRIGLFv);

    AddTrailingEdges(3,
                     1,
                     fData->SFRS_FIB_ONE_LEFT_TRIGTFM,
                     fData->SFRS_FIB_ONE_LEFT_TRIGTFMI,
                     fData->SFRS_FIB_ONE_LEFT_TRIGTFME,
                     fData->SFRS_FIB_ONE_LEFT_TRIGTCv,
                     fData->SFRS_FIB_ONE_LEFT_TRIGTFv);

    fNEvent++;

    return kTRUE;
}

void R3BSfrsFibOneReader::Reset()
{
    if (fArray)
    {
        fArray->Clear();
    }
}

ClassImp(R3BSfrsFibOneReader)
