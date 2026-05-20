#include "R3BNeulosCal2Hit.h"
#include "R3BNeulosCalData.h"
#include "R3BNeulosHitData.h"
#include "R3BLogger.h"

#include <FairRootManager.h>
#include <TClonesArray.h>

R3BNeulosCal2Hit::R3BNeulosCal2Hit() : R3BNeulosCal2Hit("R3BNeulosCal2Hit", 1) {}
R3BNeulosCal2Hit::R3BNeulosCal2Hit(const TString& name, Int_t iVerbose) : FairTask(name, iVerbose) {}
R3BNeulosCal2Hit::~R3BNeulosCal2Hit() { if (fHitData) delete fHitData; }

InitStatus R3BNeulosCal2Hit::Init()
{
    auto* mgr = FairRootManager::Instance();
    if (!mgr) { R3BLOG(fatal, "FairRootManager not found"); return kFATAL; }

    fCalData = dynamic_cast<TClonesArray*>(mgr->GetObject("NeulosCalData"));
    if (!fCalData) { R3BLOG(fatal, "NeulosCalData not found"); return kFATAL; }

    fHitData = new TClonesArray("R3BNeulosHitData");
    mgr->Register("NeulosHitData", "Neulos_Hit", fHitData, !fOnline);
    Reset();
    return kSUCCESS;
}

void R3BNeulosCal2Hit::Exec(Option_t*)
{
    Reset();
    if (!fCalData || fCalData->GetEntriesFast() == 0) return;

    for (auto* obj : *fCalData)
    {
        auto const* cal = dynamic_cast<R3BNeulosCalData const*>(obj);
        if (!cal || cal->IsTrigger()) continue;
        AddHitData(cal->GetChannel(), cal->GetLeadingTimeNs(), cal->GetTotNs());
    }
}

void R3BNeulosCal2Hit::Reset() { if (fHitData) fHitData->Clear(); }

R3BNeulosHitData* R3BNeulosCal2Hit::AddHitData(uint16_t channel, double timeNs, double totNs)
{
    TClonesArray& clref = *fHitData;
    const auto size = clref.GetEntriesFast();
    return new (clref[size]) R3BNeulosHitData(channel, timeNs, totNs);
}

ClassImp(R3BNeulosCal2Hit)
