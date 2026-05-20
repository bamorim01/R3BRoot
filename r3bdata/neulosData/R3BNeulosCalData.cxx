#include "R3BNeulosCalData.h"

#include <fmt/core.h>

std::string R3BNeulosCalData::toString() const
{
    return fmt::format("Side: {}, Type: {}, Channel: {}, LeadingTimeNs: {:.6f}, TrailingTimeNs: {:.6f}, ToTNs: {:.6f}",
                       GetSide(),
                       GetType(),
                       GetChannel(),
                       GetLeadingTimeNs(),
                       GetTrailingTimeNs(),
                       GetTotNs());
}

void R3BNeulosCalData::Print(const Option_t*) const
{
    std::cout << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const R3BNeulosCalData& data)
{
    os << data.toString();
    return os;
}

ClassImp(R3BNeulosCalData)
