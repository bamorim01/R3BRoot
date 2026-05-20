// -------------------------------------------------------------------------
// -----              R3BPasMapped2Cal source file                    -----
// -------------------------------------------------------------------------

// ROOT headers
#include <TClonesArray.h>
#include <TMath.h>

// FAIR headers
#include <FairLogger.h>
#include <FairRootManager.h>

// PAS headers
#include "R3BLogger.h"
#include "R3BPasCalData.h"
#include "R3BPasMapped2Cal.h"
#include "R3BPasMappedData.h"

#include <algorithm>
#include <cstdint>
#include <map>
#include <vector>

namespace
{
struct PasEdgeKey
{
    uint16_t side = 0;    // 0 = DOWN, 1 = UP
    uint16_t type = 0;    // 0 = normal PAS, 1 = trigger
    uint16_t channel = 0; // zero-based SiPM/fiber channel

    bool operator<(const PasEdgeKey& other) const
    {
        if (side != other.side)
        {
            return side < other.side;
        }

        if (type != other.type)
        {
            return type < other.type;
        }

        return channel < other.channel;
    }
};
} // namespace

// R3BPasMapped2Cal::Default Constructor ------------------------------------
R3BPasMapped2Cal::R3BPasMapped2Cal()
    : R3BPasMapped2Cal("R3BPasMapped2Cal", 1)
{
}

// R3BPasMapped2Cal::Standard Constructor -----------------------------------
R3BPasMapped2Cal::R3BPasMapped2Cal(const TString& name, Int_t iVerbose)
    : FairTask(name, iVerbose)
{
}

// Virtual R3BPasMapped2Cal::Destructor -------------------------------------
R3BPasMapped2Cal::~R3BPasMapped2Cal()
{
    R3BLOG(debug1, "");

    if (fPasCalData)
    {
        delete fPasCalData;
    }
}

// -----   Public method Init   ---------------------------------------------
InitStatus R3BPasMapped2Cal::Init()
{
    R3BLOG(info, "");

    auto* mgr = FairRootManager::Instance();
    if (!mgr)
    {
        R3BLOG(fatal, "FairRootManager not found");
        return kFATAL;
    }

    // INPUT DATA
    fPasMappedData = dynamic_cast<TClonesArray*>(mgr->GetObject("PasMappedData"));
    if (!fPasMappedData)
    {
        R3BLOG(fatal, "PasMappedData not found");
        return kFATAL;
    }

    // OUTPUT DATA
    fPasCalData = new TClonesArray("R3BPasCalData");
    mgr->Register("PasCalData", "PAS_Cal", fPasCalData, !fOnline);

    Reset();

    return kSUCCESS;
}

// -----   Public method Execution   ----------------------------------------
void R3BPasMapped2Cal::Exec(Option_t*)
{
    Reset();

    if (!fPasMappedData || fPasMappedData->GetEntriesFast() == 0)
    {
        return;
    }

    /*
     * The mapped reader stores one edge per R3BPasMappedData object:
     *
     *   side    = 0 DOWN, 1 UP
     *   type    = 0 normal PAS, 1 trigger
     *   channel = zero-based SiPM/fiber channel
     *   edge    = 0 leading, 1 trailing
     *   coarse  = raw coarse counter
     *   fine    = raw fine bin
     *
     * Here we group edges by side/type/channel, convert each edge to ns,
     * and pair leading/trailing edges in order.
     */
    std::map<PasEdgeKey, std::vector<double>> leadingTimes;
    std::map<PasEdgeKey, std::vector<double>> trailingTimes;

    for (auto* obj : *fPasMappedData)
    {
        auto const* mappedData = dynamic_cast<R3BPasMappedData const*>(obj);
        if (!mappedData)
        {
            continue;
        }

        const uint16_t side = mappedData->GetSide();
        const uint16_t type = mappedData->GetType();
        const uint16_t channel = mappedData->GetChannel();
        const uint16_t edge = mappedData->GetEdge();
        const uint16_t coarse = mappedData->GetCoarse();
        const uint16_t fine = mappedData->GetFine();

        const double timeNs = BuildTimeNs(side, type, edge, channel, coarse, fine);

        PasEdgeKey key;
        key.side = side;
        key.type = type;
        key.channel = channel;

        if (mappedData->IsLeading())
        {
            leadingTimes[key].push_back(timeNs);
        }
        else if (mappedData->IsTrailing())
        {
            trailingTimes[key].push_back(timeNs);
        }
        else
        {
            R3BLOG(warn,
                   "PAS mapped data has unknown edge type: side=" << side
                                                                  << " type=" << type
                                                                  << " channel=" << channel
                                                                  << " edge=" << edge);
        }
    }

    for (auto& item : leadingTimes)
    {
        const PasEdgeKey& key = item.first;

        auto& leads = item.second;
        auto trailIt = trailingTimes.find(key);

        if (trailIt == trailingTimes.end())
        {
            R3BLOG(debug1,
                   "PAS has leading edges but no trailing edges for side=" << key.side
                                                                           << " type=" << key.type
                                                                           << " channel=" << key.channel);
            continue;
        }

        auto& trails = trailIt->second;

        const std::size_t nPairs = std::min(leads.size(), trails.size());

        if (leads.size() != trails.size())
        {
            R3BLOG(debug1,
                   "PAS leading/trailing multiplicity mismatch for side=" << key.side
                                                                          << " type=" << key.type
                                                                          << " channel=" << key.channel
                                                                          << " leading=" << leads.size()
                                                                          << " trailing=" << trails.size());
        }

        for (std::size_t i = 0; i < nPairs; i++)
        {
            const double leadingTimeNs = leads[i];
            const double trailingTimeNs = trails[i];
            const double totNs = trailingTimeNs - leadingTimeNs;

            /*
             * ToT should normally be positive.
             * If you later need rollover correction, add it here.
             */
            if (totNs <= 0.)
            {
                R3BLOG(debug1,
                       "PAS non-positive ToT rejected for side=" << key.side
                                                                 << " type=" << key.type
                                                                 << " channel=" << key.channel
                                                                 << " leading=" << leadingTimeNs
                                                                 << " trailing=" << trailingTimeNs
                                                                 << " ToT=" << totNs);
                continue;
            }

            AddCalData(key.side, key.type, key.channel, leadingTimeNs, trailingTimeNs, totNs);
        }
    }
}

// -----   Public method Reset   --------------------------------------------
void R3BPasMapped2Cal::Reset()
{
    R3BLOG(debug1, "Clearing PasCalData structure");

    if (fPasCalData)
    {
        fPasCalData->Clear();
    }
}

// --------------------------------------------------------------------------
double R3BPasMapped2Cal::BuildTimeNs(uint16_t side,
                                     uint16_t type,
                                     uint16_t edge,
                                     uint16_t channel,
                                     uint16_t coarse,
                                     uint16_t fine) const
{
    /*
     * From the old PAS online code:
     *
     *   t = coarse * 1000. / 150. - fine_cal[channel][fine]
     *
     * The coarse clock is therefore:
     *
     *   1000 / 150 ns = 6.666666... ns
     */
    const double coarseTimeNs = static_cast<double>(coarse) * fCoarseClockNs;
    const double fineTimeNs = GetFineTimeNs(side, type, edge, channel, fine);

    return coarseTimeNs - fineTimeNs;
}

// --------------------------------------------------------------------------
double R3BPasMapped2Cal::GetFineTimeNs(uint16_t side,
                                       uint16_t type,
                                       uint16_t edge,
                                       uint16_t channel,
                                       uint16_t fine) const
{
    /*
     * Temporary fallback calibration.
     *
     * Replace this with the real PAS fine-time lookup tables:
     *
     *   side = 0, edge = 0:
     *      pas_DLt_ns[channel][fine]
     *
     *   side = 0, edge = 1:
     *      pas_DTt_ns[channel][fine]
     *
     *   side = 1, edge = 0:
     *      pas_ULt_ns[channel][fine]
     *
     *   side = 1, edge = 1:
     *      pas_UTt_ns[channel][fine]
     *
     * Trigger times in the old code used only:
     *
     *   PAS_*_TRIGLCv[m] * 1000. / 150.
     *
     * so for trigger edges this currently returns zero fine correction.
     */
    if (type == 1)
    {
        return 0.;
    }

    constexpr double fallbackFineBinNs = (1000. / 150.) / 1024.;

    return static_cast<double>(fine) * fallbackFineBinNs;
}

// -----   Private method AddCalData  ---------------------------------------
R3BPasCalData* R3BPasMapped2Cal::AddCalData(uint16_t side,
                                            uint16_t type,
                                            uint16_t channel,
                                            double leadingTimeNs,
                                            double trailingTimeNs,
                                            double totNs)
{
    TClonesArray& clref = *fPasCalData;
    const auto size = clref.GetEntriesFast();

    return new (clref[size]) R3BPasCalData(side, type, channel, leadingTimeNs, trailingTimeNs, totNs);
}

ClassImp(R3BPasMapped2Cal)
