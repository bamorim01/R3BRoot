// Generated starter implementation from the old online hit.C logic.
// Calibration placeholders:
//   - fine time correction currently uses either zero for triggers or linear fallback.
//   - gain and timing offsets are hard-coded defaults.
// Replace these with FairRuntimeDb parameter containers when constants are available.

#include "R3BPasCal2Hit.h"
#include "R3BPasCalData.h"
#include "R3BPasHitData.h"
#include "R3BLogger.h"

#include <FairRootManager.h>
#include <TClonesArray.h>

#include <cmath>
#include <map>
#include <vector>

namespace
{
struct SideHit
{
    uint16_t channel = 0;
    double lead = -10000.;
    double tot = 0.;
};
}

R3BPasCal2Hit::R3BPasCal2Hit() : R3BPasCal2Hit("R3BPasCal2Hit", 1) {}
R3BPasCal2Hit::R3BPasCal2Hit(const TString& name, Int_t iVerbose) : FairTask(name, iVerbose) {}
R3BPasCal2Hit::~R3BPasCal2Hit() { if (fHitData) delete fHitData; }

InitStatus R3BPasCal2Hit::Init()
{
    auto* mgr = FairRootManager::Instance();
    if (!mgr) { R3BLOG(fatal, "FairRootManager not found"); return kFATAL; }

    fCalData = dynamic_cast<TClonesArray*>(mgr->GetObject("PasCalData"));
    if (!fCalData) { R3BLOG(fatal, "PasCalData not found"); return kFATAL; }

    fHitData = new TClonesArray("R3BPasHitData");
    mgr->Register("PasHitData", "Pas_Hit", fHitData, !fOnline);
    Reset();
    return kSUCCESS;
}

void R3BPasCal2Hit::Exec(Option_t*)
{
    Reset();
    if (!fCalData || fCalData->GetEntriesFast() == 0) return;

    std::map<uint16_t, SideHit> down;
    std::map<uint16_t, SideHit> up;

    for (auto* obj : *fCalData)
    {
        auto const* cal = dynamic_cast<R3BPasCalData const*>(obj);
        if (!cal || cal->IsTrigger()) continue;

        // The uploaded hit.C uses the first hit per channel for PAS.
        const double totGain = (cal->GetTotNs() - fTotOffsetNs) / fGainDefault * 30.;
        if (totGain <= 0.) continue;

        SideHit h{cal->GetChannel(), cal->GetLeadingTimeNs(), totGain};

        if (cal->GetSide() == 0)
        {
            auto it = down.find(h.channel);
            if (it == down.end() || h.tot > it->second.tot) down[h.channel] = h;
        }
        else if (cal->GetSide() == 1)
        {
            auto it = up.find(h.channel);
            if (it == up.end() || h.tot > it->second.tot) up[h.channel] = h;
        }
    }

    double bestTot = -1.;
    SideHit bestD, bestU;
    bool found = false;

    for (const auto& d : down)
    {
        auto uit = up.find(d.first);
        if (uit == up.end()) continue;

        const double combTot = std::sqrt(d.second.tot * uit->second.tot);
        if (combTot > bestTot)
        {
            bestTot = combTot;
            bestD = d.second;
            bestU = uit->second;
            found = true;
        }
    }

    if (!found) return;

    const double xFib = 0.5 * (static_cast<double>(bestD.channel) + static_cast<double>(bestU.channel));
    if (std::abs(static_cast<double>(bestD.channel) - static_cast<double>(bestU.channel)) > fCoincidenceChannels) return;

    const double xMm = (xFib - fCenterChannel) * fPitchMm;
    const double timeNs = 0.5 * (bestD.lead + bestU.lead);

    AddHitData(xFib, xMm, timeNs, bestTot, bestD.channel, bestU.channel);
}

void R3BPasCal2Hit::Reset() { if (fHitData) fHitData->Clear(); }

R3BPasHitData* R3BPasCal2Hit::AddHitData(double xFib, double xMm, double timeNs, double tot, uint16_t downChannel, uint16_t upChannel)
{
    TClonesArray& clref = *fHitData;
    const auto size = clref.GetEntriesFast();
    return new (clref[size]) R3BPasHitData(xFib, xMm, timeNs, tot, downChannel, upChannel);
}

ClassImp(R3BPasCal2Hit)
