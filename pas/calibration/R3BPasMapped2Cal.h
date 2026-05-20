#pragma once

#include <FairTask.h>

#include "R3BPasCalData.h"

#include <Rtypes.h>
#include <cstdint>

class TClonesArray;

class R3BPasMapped2Cal : public FairTask
{
  public:
    /** Default constructor **/
    R3BPasMapped2Cal();

    /** Standard constructor **/
    R3BPasMapped2Cal(const TString& name, Int_t iVerbose = 1);

    /** Destructor **/
    ~R3BPasMapped2Cal() override;

    /** Method Exec **/
    void Exec(Option_t*) override;

    /** Method Reset **/
    virtual void Reset();

    /** Method Init **/
    InitStatus Init() override;

    /** Method to setup online mode **/
    void SetOnline(bool option = true) { fOnline = option; }

  private:
    double BuildTimeNs(uint16_t side,
                       uint16_t type,
                       uint16_t edge,
                       uint16_t channel,
                       uint16_t coarse,
                       uint16_t fine) const;

    double GetFineTimeNs(uint16_t side,
                         uint16_t type,
                         uint16_t edge,
                         uint16_t channel,
                         uint16_t fine) const;

    R3BPasCalData* AddCalData(uint16_t side,
                              uint16_t type,
                              uint16_t channel,
                              double leadingTimeNs,
                              double trailingTimeNs,
                              double totNs);

  private:
    bool fOnline = false;

    TClonesArray* fPasMappedData = nullptr;
    TClonesArray* fPasCalData = nullptr;

    /*
     * From the old PAS online code:
     *
     *   t = coarse * 1000. / 150. - fine_cal[channel][fine]
     */
    double fCoarseClockNs = 1000. / 150.;

  public:
    ClassDefOverride(R3BPasMapped2Cal, 1); // NOLINT
};
