#include "R3BPasHitData.h"

#include <fmt/core.h>

std::string R3BPasHitData::toString() const
{
    return fmt::format("XFib: {}, Xmm: {:.6f}, TimeNs: {:.6f}, ToT: {:.6f}", GetXFib(), GetXmm(), GetTimeNs(), GetTot());
}

void R3BPasHitData::Print(const Option_t*) const
{
    std::cout << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const R3BPasHitData& data)
{
    os << data.toString();
    return os;
}

ClassImp(R3BPasHitData)
