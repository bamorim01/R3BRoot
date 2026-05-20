#pragma once

#include <TObject.h>

#include <cstdint>
#include <iostream>
#include <string>

class R3BPasCalData : public TObject
{
  public:
    // Default constructor
    R3BPasCalData() = default;

    /**
     * Standard constructor for PAS calibrated timing data.
     *
     * @param side             PAS side: 0 = DOWN, 1 = UP
     * @param type             Hit type: 0 = normal PAS signal, 1 = PAS trigger signal
     * @param channel          Zero-based SiPM/fiber channel
     * @param leadingTimeNs    Leading-edge time in ns
     * @param trailingTimeNs   Trailing-edge time in ns
     * @param totNs            Time-over-threshold in ns
     */
    explicit R3BPasCalData(uint16_t side,
                           uint16_t type,
                           uint16_t channel,
                           double leadingTimeNs,
                           double trailingTimeNs,
                           double totNs);

    // Destructor
    virtual ~R3BPasCalData() = default;

    // Accessors
    [[nodiscard]] inline uint16_t GetSide() const { return fSide; }
    [[nodiscard]] inline uint16_t GetType() const { return fType; }
    [[nodiscard]] inline uint16_t GetChannel() const { return fChannel; }

    [[nodiscard]] inline double GetLeadingTimeNs() const { return fLeadingTimeNs; }
    [[nodiscard]] inline double GetTrailingTimeNs() const { return fTrailingTimeNs; }
    [[nodiscard]] inline double GetTotNs() const { return fTotNs; }

    // Short aliases
    [[nodiscard]] inline double GetLT() const { return fLeadingTimeNs; }
    [[nodiscard]] inline double GetTT() const { return fTrailingTimeNs; }
    [[nodiscard]] inline double GetToT() const { return fTotNs; }

    // Convenience checks
    [[nodiscard]] inline bool IsDown() const { return fSide == 0; }
    [[nodiscard]] inline bool IsUp() const { return fSide == 1; }

    [[nodiscard]] inline bool IsNormalSignal() const { return fType == 0; }
    [[nodiscard]] inline bool IsTrigger() const { return fType == 1; }

    // Support for printing
    [[nodiscard]] std::string toString() const;
    void Print(const Option_t*) const override;

  protected:
    uint16_t fSide = 0;    // 0 = DOWN, 1 = UP
    uint16_t fType = 0;    // 0 = normal PAS signal, 1 = trigger signal
    uint16_t fChannel = 0; // zero-based SiPM/fiber channel

    double fLeadingTimeNs = 0.;
    double fTrailingTimeNs = 0.;
    double fTotNs = 0.;

  public:
    ClassDefOverride(R3BPasCalData, 3)
};

std::ostream& operator<<(std::ostream& os, const R3BPasCalData& data);
