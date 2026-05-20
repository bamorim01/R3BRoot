#pragma once

#include <FairTask.h>
#include <Rtypes.h>
#include <cstdint>

class TClonesArray;

class R3BSfrsFibOneMapped2Cal : public FairTask
{
  public:
    R3BSfrsFibOneMapped2Cal();
    R3BSfrsFibOneMapped2Cal(const TString& name, Int_t iVerbose = 1);
    ~R3BSfrsFibOneMapped2Cal() override;

    InitStatus Init() override;
    void Exec(Option_t*) override;
    void Reset();

    void SetOnline(bool option = true) { fOnline = option; }

  private:
    double BuildTimeNs(uint16_t side, uint16_t type, uint16_t edge, uint16_t channel, uint16_t coarse, uint16_t fine) const;
    double GetFineTimeNs(uint16_t side, uint16_t type, uint16_t edge, uint16_t channel, uint16_t fine) const;
    class R3BSfrsFibOneCalData* AddCalData(uint16_t side, uint16_t type, uint16_t channel, double leadingTimeNs, double trailingTimeNs, double totNs);

    bool fOnline = false;
    TClonesArray* fMappedData = nullptr;
    TClonesArray* fCalData = nullptr;
    double fCoarseClockNs = 1000. / 150.;

  public:
    ClassDefOverride(R3BSfrsFibOneMapped2Cal, 1)
};
