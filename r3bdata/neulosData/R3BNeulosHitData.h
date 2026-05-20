#pragma once

#include <TObject.h>
#include <cstdint>
#include <iostream>
#include <string>

class R3BNeulosHitData : public TObject
{
  public:
    R3BNeulosHitData() = default;
    explicit R3BNeulosHitData(uint16_t channel, double timeNs, double totNs) : fChannel(channel), fTimeNs(timeNs), fTotNs(totNs) {}
    virtual ~R3BNeulosHitData() = default;

    [[nodiscard]] uint16_t GetChannel() const { return fChannel; }
    [[nodiscard]] double GetTimeNs() const { return fTimeNs; }
    [[nodiscard]] double GetTotNs() const { return fTotNs; }

    [[nodiscard]] std::string toString() const;
    void Print(const Option_t*) const override;

  private:

    uint16_t fChannel = 0;
    double fTimeNs = -10000.;
    double fTotNs = 0.;

  public:
    ClassDefOverride(R3BNeulosHitData, 1)
};

std::ostream& operator<<(std::ostream& os, const R3BNeulosHitData& data);
