// Generated starter implementation from the old online hit.C logic.
// Calibration placeholders:
//   - fine time correction currently uses either zero for triggers or linear fallback.
//   - gain and timing offsets are hard-coded defaults.
// Replace these with FairRuntimeDb parameter containers when constants are available.

#include "R3BSfrsFibOneCal2Hit.h"
#include "R3BSfrsFibOneCalData.h"
#include "R3BSfrsFibOneHitData.h"
#include "R3BLogger.h"

#include <FairRootManager.h>
#include <TClonesArray.h>

#include <cmath>
#include <map>

namespace { struct SideHit { uint16_t channel = 0; double lead = -10000.; double tot = 0.; }; }

R3BSfrsFibOneCal2Hit::R3BSfrsFibOneCal2Hit() : R3BSfrsFibOneCal2Hit("R3BSfrsFibOneCal2Hit", 1) {}
R3BSfrsFibOneCal2Hit::R3BSfrsFibOneCal2Hit(const TString& name, Int_t iVerbose) : FairTask(name, iVerbose) {}
R3BSfrsFibOneCal2Hit::~R3BSfrsFibOneCal2Hit() { if (fHitData) delete fHitData; }

InitStatus R3BSfrsFibOneCal2Hit::Init()
{
    auto* mgr = FairRootManager::Instance();
    if (!mgr) { R3BLOG(fatal, "FairRootManager not found"); return kFATAL; }

    fCalData = dynamic_cast<TClonesArray*>(mgr->GetObject("SfrsFibOneCalData"));
    if (!fCalData) { R3BLOG(fatal, "SfrsFibOneCalData not found"); return kFATAL; }

    fHitData = new TClonesArray("R3BSfrsFibOneHitData");
    mgr->Register("SfrsFibOneHitData", "SfrsFibOne_Hit", fHitData, !fOnline);
    Reset();
    return kSUCCESS;
}

void R3BSfrsFibOneCal2Hit::Exec(Option_t*)
{
    Reset();
    if (!fCalData || fCalData->GetEntriesFast() == 0) return;

    std::map<uint16_t, SideHit> down, up, right, left;

    for (auto* obj : *fCalData)
    {
        auto const* cal = dynamic_cast<R3BSfrsFibOneCalData const*>(obj);
        if (!cal || cal->IsTrigger()) continue;

        const double totGain = (cal->GetTotNs() - fTotOffsetNs) / fGainDefault * 30.;
        if (totGain <= 0.) continue;

        SideHit h{cal->GetChannel(), cal->GetLeadingTimeNs(), totGain};
        std::map<uint16_t, SideHit>* target = nullptr;

        if (cal->GetSide() == 0) target = &down;
        else if (cal->GetSide() == 1) target = &up;
        else if (cal->GetSide() == 2) target = &right;
        else if (cal->GetSide() == 3) target = &left;

        if (!target) continue;
        auto it = target->find(h.channel);
        if (it == target->end() || h.tot > it->second.tot) (*target)[h.channel] = h;
    }

    double bestTotX = -1.;
    double bestTotY = -1.;
    SideHit bestD, bestU, bestR, bestL;
    bool foundX = false;
    bool foundY = false;

    for (const auto& d : down)
    {
        auto uit = up.find(d.first);
        if (uit == up.end()) continue;
        const double combTot = std::sqrt(d.second.tot * uit->second.tot);
        if (combTot > bestTotX)
        {
            bestTotX = combTot;
            bestD = d.second;
            bestU = uit->second;
            foundX = true;
        }
    }

    for (const auto& r : right)
    {
        auto lit = left.find(r.first);
        if (lit == left.end()) continue;
        const double combTot = std::sqrt(r.second.tot * lit->second.tot);
        if (combTot > bestTotY)
        {
            bestTotY = combTot;
            bestR = r.second;
            bestL = lit->second;
            foundY = true;
        }
    }

    if (!foundX || !foundY) return;
    if (std::abs(static_cast<double>(bestD.channel) - static_cast<double>(bestU.channel)) > fCoincidenceChannels) return;
    if (std::abs(static_cast<double>(bestR.channel) - static_cast<double>(bestL.channel)) > fCoincidenceChannels) return;

    const double xFib = 0.5 * (static_cast<double>(bestD.channel) + static_cast<double>(bestU.channel));
    const double yFib = 0.5 * (static_cast<double>(bestR.channel) + static_cast<double>(bestL.channel));
    const double xMm = (xFib - fCenterXChannel) * fPitchMm;
    const double yMm = (yFib - fCenterYChannel) * fPitchMm;
    const double timeNs = 0.25 * (bestD.lead + bestU.lead + bestR.lead + bestL.lead);

    AddHitData(xFib, yFib, xMm, yMm, timeNs, bestTotX, bestTotY, bestD.channel, bestU.channel, bestR.channel, bestL.channel);
}

void R3BSfrsFibOneCal2Hit::Reset() { if (fHitData) fHitData->Clear(); }

R3BSfrsFibOneHitData* R3BSfrsFibOneCal2Hit::AddHitData(double xFib, double yFib, double xMm, double yMm, double timeNs, double totX, double totY, uint16_t d, uint16_t u, uint16_t r, uint16_t l)
{
    TClonesArray& clref = *fHitData;
    const auto size = clref.GetEntriesFast();
    return new (clref[size]) R3BSfrsFibOneHitData(xFib, yFib, xMm, yMm, timeNs, totX, totY, d, u, r, l);
}

ClassImp(R3BSfrsFibOneCal2Hit)
