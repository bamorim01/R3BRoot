#pragma once

#include <TObject.h>

#include <cstdint>
#include <iostream>
#include <string>

class R3BNeulosMappedData : public TObject
{
  public:
    R3BNeulosMappedData() = default;

    /**
     * Mapped edge data for NEULOS.
     *
     * @param side     0 = TF, 1 = TS
     * @param type     0 = normal signal, 1 = trigger signal
     * @param channel  zero-based channel index
     * @param edge     0 = leading edge, 1 = trailing edge
     * @param coarse   raw coarse time
     * @param fine     raw fine time bin
     */
    explicit R3BNeulosMappedData(uint16_t side,
                                 uint16_t type,
                                 uint16_t channel,
                                 uint16_t edge,
                                 uint16_t coarse,
                                 uint16_t fine);

    virtual ~R3BNeulosMappedData() = default;

    [[nodiscard]] inline uint16_t GetSide() const { return fSide; }
    [[nodiscard]] inline uint16_t GetType() const { return fType; }
    [[nodiscard]] inline uint16_t GetChannel() const { return fChannel; }
    [[nodiscard]] inline uint16_t GetEdge() const { return fEdge; }
    [[nodiscard]] inline uint16_t GetCoarse() const { return fCoarse; }
    [[nodiscard]] inline uint16_t GetFine() const { return fFine; }

    [[nodiscard]] inline bool IsTF() const { return fSide == 0; }
    [[nodiscard]] inline bool IsTS() const { return fSide == 1; }

    [[nodiscard]] inline bool IsNormalSignal() const { return fType == 0; }
    [[nodiscard]] inline bool IsTrigger() const { return fType == 1; }

    [[nodiscard]] inline bool IsLeading() const { return fEdge == 0; }
    [[nodiscard]] inline bool IsTrailing() const { return fEdge == 1; }

    [[nodiscard]] std::string toString() const;
    void Print(const Option_t*) const override;

  protected:
    uint16_t fSide = 0;    // 0 = TF, 1 = TS
    uint16_t fType = 0;    // 0 = normal signal, 1 = trigger signal
    uint16_t fChannel = 0; // zero-based channel index
    uint16_t fEdge = 0;    // 0 = leading, 1 = trailing

    uint16_t fCoarse = 0;
    uint16_t fFine = 0;

  public:
    ClassDefOverride(R3BNeulosMappedData, 1)
};

std::ostream& operator<<(std::ostream& os, const R3BNeulosMappedData& data);
