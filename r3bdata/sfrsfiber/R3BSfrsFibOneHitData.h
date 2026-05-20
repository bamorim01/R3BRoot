#pragma once

#include <TObject.h>
#include <cstdint>
#include <iostream>
#include <string>

class R3BSfrsFibOneHitData : public TObject
{
  public:
    R3BSfrsFibOneHitData() = default;
    explicit R3BSfrsFibOneHitData(double xFib, double yFib, double xMm, double yMm, double timeNs, double totX, double totY, uint16_t downChannel, uint16_t upChannel, uint16_t rightChannel, uint16_t leftChannel) : fXFib(xFib), fYFib(yFib), fXmm(xMm), fYmm(yMm), fTimeNs(timeNs), fTotX(totX), fTotY(totY), fDownChannel(downChannel), fUpChannel(upChannel), fRightChannel(rightChannel), fLeftChannel(leftChannel) {}
    virtual ~R3BSfrsFibOneHitData() = default;

    [[nodiscard]] double GetXFib() const { return fXFib; }
    [[nodiscard]] double GetYFib() const { return fYFib; }
    [[nodiscard]] double GetXmm() const { return fXmm; }
    [[nodiscard]] double GetYmm() const { return fYmm; }
    [[nodiscard]] double GetTimeNs() const { return fTimeNs; }
    [[nodiscard]] double GetTotX() const { return fTotX; }
    [[nodiscard]] double GetTotY() const { return fTotY; }
    [[nodiscard]] uint16_t GetDownChannel() const { return fDownChannel; }
    [[nodiscard]] uint16_t GetUpChannel() const { return fUpChannel; }
    [[nodiscard]] uint16_t GetRightChannel() const { return fRightChannel; }
    [[nodiscard]] uint16_t GetLeftChannel() const { return fLeftChannel; }

    [[nodiscard]] std::string toString() const;
    void Print(const Option_t*) const override;

  private:

    double fXFib = -1000.;
    double fYFib = -1000.;
    double fXmm = -1000.;
    double fYmm = -1000.;
    double fTimeNs = -10000.;
    double fTotX = 0.;
    double fTotY = 0.;
    uint16_t fDownChannel = 0;
    uint16_t fUpChannel = 0;
    uint16_t fRightChannel = 0;
    uint16_t fLeftChannel = 0;

  public:
    ClassDefOverride(R3BSfrsFibOneHitData, 1)
};

std::ostream& operator<<(std::ostream& os, const R3BSfrsFibOneHitData& data);
