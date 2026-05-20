#pragma once
#include <FairTask.h>
#include <Rtypes.h>
class TClonesArray;

class R3BPasCal2Hit : public FairTask
{
  public:
    R3BPasCal2Hit();
    R3BPasCal2Hit(const TString& name, Int_t iVerbose = 1);
    ~R3BPasCal2Hit() override;
    InitStatus Init() override;
    void Exec(Option_t*) override;
    void Reset();
    void SetOnline(bool option = true) { fOnline = option; }

  private:
    class R3BPasHitData* AddHitData(double xFib, double xMm, double timeNs, double tot, uint16_t downChannel, uint16_t upChannel);
    bool fOnline = false;
    TClonesArray* fCalData = nullptr;
    TClonesArray* fHitData = nullptr;
    double fCenterChannel = 128.;
    double fPitchMm = 0.5;
    double fCoincidenceChannels = 3.;
    double fTotOffsetNs = 12.;
    double fGainDefault = 30.;

  public:
    ClassDefOverride(R3BPasCal2Hit, 1)
};
