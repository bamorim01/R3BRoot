#pragma once

#include <FairTask.h>
#include <Rtypes.h>
#include <cstdint>

class TClonesArray;

class R3BNeulosMapped2Cal : public FairTask
{
  public:
    R3BNeulosMapped2Cal();
    R3BNeulosMapped2Cal(const TString& name, Int_t iVerbose = 1);
    ~R3BNeulosMapped2Cal() override;

    InitStatus Init() override;
    void Exec(Option_t*) override;
    void Reset() ;

    void SetOnline(bool option = true) { fOnline = option; }

  private:
    double BuildTimeNs(uint16_t side, uint16_t type, uint16_t edge, uint16_t channel, uint16_t coarse, uint16_t fine) const;
    double GetFineTimeNs(uint16_t side, uint16_t type, uint16_t edge, uint16_t channel, uint16_t fine) const;
    class R3BNeulosCalData* AddCalData(uint16_t side, uint16_t type, uint16_t channel, double leadingTimeNs, double trailingTimeNs, double totNs);

    bool fOnline = false;
    TClonesArray* fMappedData = nullptr;
    TClonesArray* fCalData = nullptr;
    double fCoarseClockNs = 5.;

  public:
    ClassDefOverride(R3BNeulosMapped2Cal, 1)
};
