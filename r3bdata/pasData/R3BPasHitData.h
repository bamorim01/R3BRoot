#pragma once

#include <TObject.h>
#include <cstdint>
#include <iostream>
#include <string>

class R3BPasHitData : public TObject
{
  public:
    R3BPasHitData() = default;
    explicit R3BPasHitData(double xFib, double xMm, double timeNs, double tot, uint16_t downChannel, uint16_t upChannel) : fXFib(xFib), fXmm(xMm), fTimeNs(timeNs), fTot(tot), fDownChannel(downChannel), fUpChannel(upChannel) {}
    virtual ~R3BPasHitData() = default;

    [[nodiscard]] double GetXFib() const { return fXFib; }
    [[nodiscard]] double GetXmm() const { return fXmm; }
    [[nodiscard]] double GetTimeNs() const { return fTimeNs; }
    [[nodiscard]] double GetTot() const { return fTot; }
    [[nodiscard]] uint16_t GetDownChannel() const { return fDownChannel; }
    [[nodiscard]] uint16_t GetUpChannel() const { return fUpChannel; }

    [[nodiscard]] std::string toString() const;
    void Print(const Option_t*) const override;

  private:

    double fXFib = -1000.;
    double fXmm = -1000.;
    double fTimeNs = -10000.;
    double fTot = 0.;
    uint16_t fDownChannel = 0;
    uint16_t fUpChannel = 0;

  public:
    ClassDefOverride(R3BPasHitData, 1)
};

std::ostream& operator<<(std::ostream& os, const R3BPasHitData& data);
