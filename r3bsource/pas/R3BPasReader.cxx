/******************************************************************************
 *   Copyright (C) 2019 GSI Helmholtzzentrum für Schwerionenforschung GmbH    *
 *   Copyright (C) 2019-2025 Members of R3B Collaboration                     *
 *                                                                            *
 *             This software is distributed under the terms of the            *
 *                 GNU General Public Licence (GPL) version 3,                *
 *                    copied verbatim in the file "LICENSE".                  *
 *                                                                            *
 * In applying this license GSI does not waive the privileges and immunities  *
 * granted to it by virtue of its status as an Intergovernmental Organization *
 * or submit itself to any jurisdiction.                                      *
 ******************************************************************************/

#include "FairLogger.h"
#include "FairRootManager.h"

#include "R3BPasMappedData.h"
#include "R3BPasReader.h"
#include "R3BLogger.h"

#include "TClonesArray.h"
#include "ext_data_struct_info.hh"

#include <cstring>
#include <algorithm>


/**
 ** ext_h101_pas.h was created by running something like:
 ** $unpacker --ntuple=STRUCT_HH,RAW:PAS,id=h101_PAS,NOTRIGEVENTNO,ext_h101_pas.h
 **/

extern "C"
{
#include "ext_data_client.h"
#include "ext_h101_pas.h"
}

R3BPasReader::R3BPasReader(EXT_STR_h101_PAS_onion* data, size_t offset)
    : R3BReader("R3BPasReader")
    , fNEvent(1)
    , fData(data)
    , fOffset(offset)
    , fOnline(kFALSE)
    , fArray(new TClonesArray("R3BPasMappedData"))
{
}

R3BPasReader::~R3BPasReader()
{
    R3BLOG(debug1, "");

    if (fArray)
    {
        delete fArray;
    }
}

Bool_t R3BPasReader::Init(ext_data_struct_info* a_struct_info)
{
    Int_t ok;

    R3BLOG(info, "");

    EXT_STR_h101_PAS_ITEMS_INFO(ok, *a_struct_info, fOffset, EXT_STR_h101_PAS, 0);

    R3BLOG_IF(fatal, !ok, "Failed to setup structure information.");

    FairRootManager::Instance()->Register("PasMappedData", "PAS_Map", fArray, !fOnline);

    Reset();

    memset(fData, 0, sizeof(*fData));

    return kTRUE;
}

Bool_t R3BPasReader::R3BRead()
{
    R3BLOG(debug1, "Event data: " << fNEvent);

    /*
     * PAS mapped format used here:
     *
     *   side:
     *      0 = DOWN
     *      1 = UP
     *
     *   type:
     *      0 = normal PAS signal
     *      1 = PAS trigger signal
     *
     *   edge:
     *      0 = leading edge
     *      1 = trailing edge
     *
     *   channel:
     *      zero-based SiPM/fiber channel from the MI array:
     *        channel = MI[c] - 1
     *
     * The UCESB grouped layout is interpreted as:
     *
     *   M   = number of channels with data
     *   MI  = channel index, 1-based
     *   ME  = end index into the value arrays
     *   v   = value array
     *
     * For channel group c:
     *
     *   start = c > 0 ? ME[c - 1] : 0
     *   end   = ME[c]
     *
     * and values are read for m = start ... end - 1.
     */

    auto AddLeadingEdges = [this](UInt_t side,
                                  UInt_t type,
                                  UInt_t nChan,
                                  const UInt_t* chanMI,
                                  const UInt_t* chanME,
                                  const UInt_t* coarseV,
                                  const UInt_t* fineV) {
        UInt_t start = 0;

        for (UInt_t c = 0; c < nChan; c++)
        {
            if (chanMI[c] == 0)
            {
                R3BLOG(warn,
                       "PAS leading edge has zero channel index for side " << side << ", type " << type
                                                                            << ", group " << c);
                continue;
            }

            const UInt_t channel = chanMI[c] - 1;

            if (c > 0)
            {
                start = chanME[c - 1];
            }
            else
            {
                start = 0;
            }

            const UInt_t end = chanME[c];

            if (end < start)
            {
                R3BLOG(error,
                       "PAS leading edge invalid ME ordering for side " << side << ", type " << type
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
                    R3BPasMappedData(side, type, channel, 0, coarse, fine);
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
        UInt_t start = 0;

        for (UInt_t c = 0; c < nChan; c++)
        {
            if (chanMI[c] == 0)
            {
                R3BLOG(warn,
                       "PAS trailing edge has zero channel index for side " << side << ", type " << type
                                                                             << ", group " << c);
                continue;
            }

            const UInt_t channel = chanMI[c] - 1;

            if (c > 0)
            {
                start = chanME[c - 1];
            }
            else
            {
                start = 0;
            }

            const UInt_t end = chanME[c];

            if (end < start)
            {
                R3BLOG(error,
                       "PAS trailing edge invalid ME ordering for side " << side << ", type " << type
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
                    R3BPasMappedData(side, type, channel, 1, coarse, fine);
            }
        }
    };

    // ------------------------------------------------------------------
    // Normal PAS DOWN
    //
    // Leading edge:
    //   channel groups: PAS_DOWN_LFM / PAS_DOWN_LFMI / PAS_DOWN_LFME
    //   values:         PAS_DOWN_LCv / PAS_DOWN_LFv
    //
    // Trailing edge:
    //   channel groups: PAS_DOWN_TFM / PAS_DOWN_TFMI / PAS_DOWN_TFME
    //   values:         PAS_DOWN_TCv / PAS_DOWN_TFv
    // ------------------------------------------------------------------

    AddLeadingEdges(0,
                    0,
                    fData->PAS_DOWN_LFM,
                    fData->PAS_DOWN_LFMI,
                    fData->PAS_DOWN_LFME,
                    fData->PAS_DOWN_LCv,
                    fData->PAS_DOWN_LFv);

    AddTrailingEdges(0,
                     0,
                     fData->PAS_DOWN_TFM,
                     fData->PAS_DOWN_TFMI,
                     fData->PAS_DOWN_TFME,
                     fData->PAS_DOWN_TCv,
                     fData->PAS_DOWN_TFv);

    // ------------------------------------------------------------------
    // Normal PAS UP
    // ------------------------------------------------------------------

    AddLeadingEdges(1,
                    0,
                    fData->PAS_UP_LFM,
                    fData->PAS_UP_LFMI,
                    fData->PAS_UP_LFME,
                    fData->PAS_UP_LCv,
                    fData->PAS_UP_LFv);

    AddTrailingEdges(1,
                     0,
                     fData->PAS_UP_TFM,
                     fData->PAS_UP_TFMI,
                     fData->PAS_UP_TFME,
                     fData->PAS_UP_TCv,
                     fData->PAS_UP_TFv);

    // ------------------------------------------------------------------
    // Trigger PAS DOWN
    //
    // Leading trigger:
    //   channel groups: PAS_DOWN_TRIGLFM / PAS_DOWN_TRIGLFMI / PAS_DOWN_TRIGLFME
    //   values:         PAS_DOWN_TRIGLCv / PAS_DOWN_TRIGLFv
    //
    // Trailing trigger:
    //   channel groups: PAS_DOWN_TRIGTFM / PAS_DOWN_TRIGTFMI / PAS_DOWN_TRIGTFME
    //   values:         PAS_DOWN_TRIGTCv / PAS_DOWN_TRIGTFv
    //
    // The old online code only used the leading trigger coarse time:
    //   pas_trigdl[ch] = PAS_DOWN_TRIGLCv[m] * 1000. / 150.;
    //
    // Here we preserve both leading and trailing trigger edges if present.
    // ------------------------------------------------------------------

    AddLeadingEdges(0,
                    1,
                    fData->PAS_DOWN_TRIGLFM,
                    fData->PAS_DOWN_TRIGLFMI,
                    fData->PAS_DOWN_TRIGLFME,
                    fData->PAS_DOWN_TRIGLCv,
                    fData->PAS_DOWN_TRIGLFv);

    AddTrailingEdges(0,
                     1,
                     fData->PAS_DOWN_TRIGTFM,
                     fData->PAS_DOWN_TRIGTFMI,
                     fData->PAS_DOWN_TRIGTFME,
                     fData->PAS_DOWN_TRIGTCv,
                     fData->PAS_DOWN_TRIGTFv);

    // ------------------------------------------------------------------
    // Trigger PAS UP
    // ------------------------------------------------------------------

    AddLeadingEdges(1,
                    1,
                    fData->PAS_UP_TRIGLFM,
                    fData->PAS_UP_TRIGLFMI,
                    fData->PAS_UP_TRIGLFME,
                    fData->PAS_UP_TRIGLCv,
                    fData->PAS_UP_TRIGLFv);

    AddTrailingEdges(1,
                     1,
                     fData->PAS_UP_TRIGTFM,
                     fData->PAS_UP_TRIGTFMI,
                     fData->PAS_UP_TRIGTFME,
                     fData->PAS_UP_TRIGTCv,
                     fData->PAS_UP_TRIGTFv);

    fNEvent++;

    return kTRUE;
}

void R3BPasReader::Reset()
{
    if (fArray)
    {
        fArray->Clear();
    }
}

ClassImp(R3BPasReader)


