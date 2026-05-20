/******************************************************************************
 *   Copyright (C) 2022 GSI Helmholtzzentrum für Schwerionenforschung GmbH    *
 *   Copyright (C) 2022-2026 Members of R3B Collaboration                     *
 *                                                                            *
 *             This software is distributed under the terms of the            *
 *                 GNU General Public Licence (GPL) version 3,                *
 *                    copied verbatim in the file "LICENSE".                  *
 *                                                                            *
 * In applying this license GSI does not waive the privileges and immunities  *
 * granted to it by virtue of its status as an Intergovernmental Organization *
 * or submit itself to any jurisdiction.                                      *
 ******************************************************************************/

// -------------------------------------------------------------------
// -----            R3BAlpideHitDataNB source file                 -----
// -------------------------------------------------------------------

#include "R3BAlpideHitDataNB.h"
#include <fmt/core.h>
R3BAlpideHitDataNB::R3BAlpideHitDataNB(uint16_t sensorId,
                                   uint16_t clustersize,
                                   double posx,
                                   double posy,
                                   double posz,
                                   double locposx,
                                   double locposy)
    : fSensorId(sensorId)
    , fClustersize(clustersize)
    , fX(posx)
    , fY(posy)
    , fZ(posz)
    , fXloc(locposx)
    , fYloc(locposy)
{
    fTrack.SetXYZ(posx, posy, posz);
    fTheta = fTrack.Theta();
    fPhi = fTrack.Phi();
}

std::string R3BAlpideHitDataNB::toString() const
{
    return fmt::format("SensorID: {}, ClusterSize: {}, Xpos: {}, Ypos: {}, Zpos: {}",
                       GetSensorId(),
                       GetClusterSize(),
                       GetX(),
                       GetY(),
                       GetZ());
}

void R3BAlpideHitDataNB::Print(const Option_t*) const { std::cout << *this << std::endl; }

std::ostream& operator<<(std::ostream& os, const R3BAlpideHitDataNB& data)
{
    os << data.toString();
    return os;
}

ClassImp(R3BAlpideHitDataNB)
