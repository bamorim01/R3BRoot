// -----------------------------------------------------------------------
// -----              R3BPasCalData source file                     -----
// -----------------------------------------------------------------------

#include "R3BPasCalData.h"

#include <fmt/core.h>

R3BPasCalData::R3BPasCalData(uint16_t side,
                             uint16_t type,
                             uint16_t channel,
                             double leadingTimeNs,
                             double trailingTimeNs,
                             double totNs)
    : fSide(side)
    , fType(type)
    , fChannel(channel)
    , fLeadingTimeNs(leadingTimeNs)
    , fTrailingTimeNs(trailingTimeNs)
    , fTotNs(totNs)
{
}

std::string R3BPasCalData::toString() const
{
    return fmt::format("Side: {}, Type: {}, Channel: {}, LeadingTimeNs: {:.6f}, TrailingTimeNs: {:.6f}, ToTNs: {:.6f}",
                       GetSide(),
                       GetType(),
                       GetChannel(),
                       GetLeadingTimeNs(),
                       GetTrailingTimeNs(),
                       GetTotNs());
}

void R3BPasCalData::Print(const Option_t*) const
{
    std::cout << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const R3BPasCalData& data)
{
    os << data.toString();
    return os;
}

ClassImp(R3BPasCalData)
