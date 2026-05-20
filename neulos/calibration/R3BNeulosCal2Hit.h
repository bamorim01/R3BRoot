#pragma once
#include <FairTask.h>
#include <Rtypes.h>
class TClonesArray;

class R3BNeulosCal2Hit : public FairTask
{
  public:
    R3BNeulosCal2Hit();
    R3BNeulosCal2Hit(const TString& name, Int_t iVerbose = 1);
    ~R3BNeulosCal2Hit() override;
    InitStatus Init() override;
    void Exec(Option_t*) override;
    void Reset();
    void SetOnline(bool option = true) { fOnline = option; }

  private:
    class R3BNeulosHitData* AddHitData(uint16_t channel, double timeNs, double totNs);
    bool fOnline = false;
    TClonesArray* fCalData = nullptr;
    TClonesArray* fHitData = nullptr;

  public:
    ClassDefOverride(R3BNeulosCal2Hit, 1)
};
