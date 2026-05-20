// Generated starter implementation from the old online hit.C logic.
// Calibration placeholders:
//   - fine time correction currently uses either zero for triggers or linear fallback.
//   - gain and timing offsets are hard-coded defaults.
// Replace these with FairRuntimeDb parameter containers when constants are available.

#include "R3BNeulosMapped2Cal.h"
#include "R3BNeulosCalData.h"
#include "R3BNeulosMappedData.h"
#include "R3BLogger.h"

#include <FairRootManager.h>
#include <TClonesArray.h>

#include <algorithm>
#include <cstdint>
#include <map>
#include <vector>

namespace
{
struct EdgeKey
{
    uint16_t side = 0;
    uint16_t type = 0;
    uint16_t channel = 0;

    bool operator<(const EdgeKey& other) const
    {
        if (side != other.side) return side < other.side;
        if (type != other.type) return type < other.type;
        return channel < other.channel;
    }
};
}

R3BNeulosMapped2Cal::R3BNeulosMapped2Cal()
    : R3BNeulosMapped2Cal("R3BNeulosMapped2Cal", 1)
{
}

R3BNeulosMapped2Cal::R3BNeulosMapped2Cal(const TString& name, Int_t iVerbose)
    : FairTask(name, iVerbose)
{
}

R3BNeulosMapped2Cal::~R3BNeulosMapped2Cal()
{
    if (fCalData) delete fCalData;
}

InitStatus R3BNeulosMapped2Cal::Init()
{
    auto* mgr = FairRootManager::Instance();
    if (!mgr)
    {
        R3BLOG(fatal, "FairRootManager not found");
        return kFATAL;
    }

    fMappedData = dynamic_cast<TClonesArray*>(mgr->GetObject("NeulosMappedData"));
    if (!fMappedData)
    {
        R3BLOG(fatal, "NeulosMappedData not found");
        return kFATAL;
    }

    fCalData = new TClonesArray("R3BNeulosCalData");
    mgr->Register("NeulosCalData", "Neulos_Cal", fCalData, !fOnline);
    Reset();

    return kSUCCESS;
}

void R3BNeulosMapped2Cal::Exec(Option_t*)
{
    Reset();
    if (!fMappedData || fMappedData->GetEntriesFast() == 0) return;

    std::map<EdgeKey, std::vector<double>> leadingTimes;
    std::map<EdgeKey, std::vector<double>> trailingTimes;

    for (auto* obj : *fMappedData)
    {
        auto const* mapped = dynamic_cast<R3BNeulosMappedData const*>(obj);
        if (!mapped) continue;

        EdgeKey key;
        key.side = mapped->GetSide();
        key.type = mapped->GetType();
        key.channel = mapped->GetChannel();

        const double t = BuildTimeNs(key.side, key.type, mapped->GetEdge(), key.channel, mapped->GetCoarse(), mapped->GetFine());

        if (mapped->IsLeading())
        {
            leadingTimes[key].push_back(t);
        }
        else if (mapped->IsTrailing())
        {
            trailingTimes[key].push_back(t);
        }
    }

    for (auto& item : leadingTimes)
    {
        const EdgeKey& key = item.first;
        auto trailIt = trailingTimes.find(key);
        if (trailIt == trailingTimes.end()) continue;

        auto& leads = item.second;
        auto& trails = trailIt->second;
        const std::size_t nPairs = std::min(leads.size(), trails.size());

        for (std::size_t i = 0; i < nPairs; i++)
        {
            const double lead = leads[i];
            const double trail = trails[i];
            const double tot = trail - lead;
            if (tot <= 0.) continue;
            AddCalData(key.side, key.type, key.channel, lead, trail, tot);
        }
    }
}

void R3BNeulosMapped2Cal::Reset()
{
    if (fCalData) fCalData->Clear();
}

double R3BNeulosMapped2Cal::BuildTimeNs(uint16_t side, uint16_t type, uint16_t edge, uint16_t channel, uint16_t coarse, uint16_t fine) const
{
    return static_cast<double>(coarse) * fCoarseClockNs - GetFineTimeNs(side, type, edge, channel, fine);
}

double R3BNeulosMapped2Cal::GetFineTimeNs(uint16_t, uint16_t type, uint16_t, uint16_t, uint16_t fine) const
{
    // In hit.C, SFRS/PAS use coarse*1000/150 - side-specific fine tables.
    // TAMEX/Neulos uses coarse*5 - fine tables.
    // Trigger fine corrections were not used for SFRS/PAS triggers in the uploaded macro.
    if (type == 1) return 0.;
    constexpr double nFineBinsFallback = 1024.;
    return static_cast<double>(fine) * fCoarseClockNs / nFineBinsFallback;
}

R3BNeulosCalData* R3BNeulosMapped2Cal::AddCalData(uint16_t side, uint16_t type, uint16_t channel, double leadingTimeNs, double trailingTimeNs, double totNs)
{
    TClonesArray& clref = *fCalData;
    const auto size = clref.GetEntriesFast();
    return new (clref[size]) R3BNeulosCalData(side, type, channel, leadingTimeNs, trailingTimeNs, totNs);
}

ClassImp(R3BNeulosMapped2Cal)
