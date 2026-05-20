#pragma once

#include <TObject.h>
#include <cstdint>
#include <iostream>
#include <string>

class R3BSfrsFibOneCalData : public TObject
{
  public:
    R3BSfrsFibOneCalData() = default;

    explicit R3BSfrsFibOneCalData(uint16_t side,
                          uint16_t type,
                          uint16_t channel,
                          double leadingTimeNs,
                          double trailingTimeNs,
                          double totNs)
        : fSide(side)
        , fType(type)
        , fChannel(channel)
        , fLeadingTimeNs(leadingTimeNs)
        , fTrailingTimeNs(trailingTimeNs)
        , fTotNs(totNs)
    {
    }

    virtual ~R3BSfrsFibOneCalData() = default;

    [[nodiscard]] uint16_t GetSide() const { return fSide; }
    [[nodiscard]] uint16_t GetType() const { return fType; }
    [[nodiscard]] uint16_t GetChannel() const { return fChannel; }
    [[nodiscard]] double GetLeadingTimeNs() const { return fLeadingTimeNs; }
    [[nodiscard]] double GetTrailingTimeNs() const { return fTrailingTimeNs; }
    [[nodiscard]] double GetTotNs() const { return fTotNs; }

    [[nodiscard]] bool IsTrigger() const { return fType == 1; }
    [[nodiscard]] bool IsNormalSignal() const { return fType == 0; }

    [[nodiscard]] std::string toString() const;
    void Print(const Option_t*) const override;

  private:
    uint16_t fSide = 0;
    uint16_t fType = 0;
    uint16_t fChannel = 0;

    double fLeadingTimeNs = 0.;
    double fTrailingTimeNs = 0.;
    double fTotNs = 0.;

  public:
    ClassDefOverride(R3BSfrsFibOneCalData, 1)
};

std::ostream& operator<<(std::ostream& os, const R3BSfrsFibOneCalData& data);
