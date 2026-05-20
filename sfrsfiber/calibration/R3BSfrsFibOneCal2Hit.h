#pragma once
#include <FairTask.h>
#include <Rtypes.h>
class TClonesArray;

class R3BSfrsFibOneCal2Hit : public FairTask
{
  public:
    R3BSfrsFibOneCal2Hit();
    R3BSfrsFibOneCal2Hit(const TString& name, Int_t iVerbose = 1);
    ~R3BSfrsFibOneCal2Hit() override;
    InitStatus Init() override;
    void Exec(Option_t*) override;
    void Reset() ;
    void SetOnline(bool option = true) { fOnline = option; }

  private:
    class R3BSfrsFibOneHitData* AddHitData(double xFib, double yFib, double xMm, double yMm, double timeNs, double totX, double totY, uint16_t d, uint16_t u, uint16_t r, uint16_t l);
    bool fOnline = false;
    TClonesArray* fCalData = nullptr;
    TClonesArray* fHitData = nullptr;
    double fCenterXChannel = 384.;
    double fCenterYChannel = 128.;
    double fPitchMm = 0.5;
    double fCoincidenceChannels = 3.;
    double fTotOffsetNs = 12.;
    double fGainDefault = 30.;

  public:
    ClassDefOverride(R3BSfrsFibOneCal2Hit, 1)
};
