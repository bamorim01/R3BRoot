/******************************************************************************
 *   Copyright (C) 2022 GSI Helmholtzzentrum für Schwerionenforschung GmbH    *
 *   Copyright (C) 2022-2023 Members of R3B Collaboration                     *
 *                                                                            *
 *             This software is distributed under the terms of the            *
 *                 GNU General Public Licence (GPL) version 3,                *
 *                    copied verbatim in the file "LICENSE".                  *
 *                                                                            *
 * In applying this license GSI does not waive the privileges and immunities  *
 * granted to it by virtue of its status as an Intergovernmental Organization *
 * or submit itself to any jurisdiction.                                      *
 ******************************************************************************/

// -----------------------------------------------------------------------
// -----            R3BPasMappedData source file                    -----
// -----------------------------------------------------------------------

#include "R3BPasMappedData.h"

#include <fmt/core.h>

R3BPasMappedData::R3BPasMappedData(uint16_t side,
                                   uint16_t type,
                                   uint16_t channel,
                                   uint16_t edge,
                                   uint16_t coarse,
                                   uint16_t fine)
    : fSide(side)
    , fType(type)
    , fChannel(channel)
    , fEdge(edge)
    , fCoarse(coarse)
    , fFine(fine)
{
}

std::string R3BPasMappedData::toString() const
{
    return fmt::format("Side: {}, Type: {}, Channel: {}, Edge: {}, Coarse: {}, Fine: {}",
                       GetSide(),
                       GetType(),
                       GetChannel(),
                       GetEdge(),
                       GetCoarse(),
                       GetFine());
}

void R3BPasMappedData::Print(const Option_t*) const
{
    std::cout << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const R3BPasMappedData& data)
{
    os << data.toString();
    return os;
}

ClassImp(R3BPasMappedData)
