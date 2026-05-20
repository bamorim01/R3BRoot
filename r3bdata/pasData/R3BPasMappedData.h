/******************************************************************************
 *   Copyright (C) 2022 GSI Helmholtzzentrum für Schwerionenforschung GmbH    *
 *   Copyright (C) 2022-2024 Members of R3B Collaboration                     *
 *                                                                            *
 *             This software is distributed under the terms of the            *
 *                 GNU General Public Licence (GPL) version 3,                *
 *                    copied verbatim in the file "LICENSE".                  *
 *                                                                            *
 * In applying this license GSI does not waive the privileges and immunities  *
 * granted to it by virtue of its status as an Intergovernmental Organization *
 * or submit itself to any jurisdiction.                                      *
 ******************************************************************************/

// -----------------------------------------------------------------
// -----                   R3BPasMappedData                 -----
// -----          Created 20/05/2026 by L.Rose	            -----
// -----------------------------------------------------------------

#pragma once

#include <TObject.h>
#include <cstdint>
#include <iostream>
#include <string>

class R3BPasMappedData : public TObject
{
  public:
    R3BPasMappedData() = default;

    /**
     * PAS mapped edge data.
     *
     * @param side     0 = DOWN, 1 = UP
     * @param type     0 = normal PAS signal, 1 = trigger signal
     * @param channel  zero-based SiPM/fiber/electronics channel
     * @param edge     0 = leading edge, 1 = trailing edge
     * @param coarse   raw coarse time
     * @param fine     raw fine time bin
     */
    explicit R3BPasMappedData(uint16_t side,
                              uint16_t type,
                              uint16_t channel,
                              uint16_t edge,
                              uint16_t coarse,
                              uint16_t fine);

    virtual ~R3BPasMappedData() = default;

    [[nodiscard]] inline uint16_t GetSide() const { return fSide; }
    [[nodiscard]] inline uint16_t GetType() const { return fType; }
    [[nodiscard]] inline uint16_t GetChannel() const { return fChannel; }
    [[nodiscard]] inline uint16_t GetEdge() const { return fEdge; }
    [[nodiscard]] inline uint16_t GetCoarse() const { return fCoarse; }
    [[nodiscard]] inline uint16_t GetFine() const { return fFine; }

    [[nodiscard]] inline bool IsDown() const { return fSide == 0; }
    [[nodiscard]] inline bool IsUp() const { return fSide == 1; }

    [[nodiscard]] inline bool IsNormalSignal() const { return fType == 0; }
    [[nodiscard]] inline bool IsTrigger() const { return fType == 1; }

    [[nodiscard]] inline bool IsLeading() const { return fEdge == 0; }
    [[nodiscard]] inline bool IsTrailing() const { return fEdge == 1; }

    [[nodiscard]] std::string toString() const;
    void Print(const Option_t*) const override;

  protected:
    uint16_t fSide = 0;    // 0 = DOWN, 1 = UP
    uint16_t fType = 0;    // 0 = normal PAS signal, 1 = trigger signal
    uint16_t fChannel = 0; // zero-based channel index
    uint16_t fEdge = 0;    // 0 = leading, 1 = trailing

    uint16_t fCoarse = 0;
    uint16_t fFine = 0;

  public:
    ClassDefOverride(R3BPasMappedData, 4)
};

std::ostream& operator<<(std::ostream& os, const R3BPasMappedData& data);
