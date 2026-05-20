#include "R3BNeulosHitData.h"

#include <fmt/core.h>

std::string R3BNeulosHitData::toString() const
{
    return fmt::format("Channel: {}, TimeNs: {:.6f}, ToTNs: {:.6f}", GetChannel(), GetTimeNs(), GetTotNs());
}

void R3BNeulosHitData::Print(const Option_t*) const
{
    std::cout << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const R3BNeulosHitData& data)
{
    os << data.toString();
    return os;
}

ClassImp(R3BNeulosHitData)
