#include "R3BSfrsFibOneHitData.h"

#include <fmt/core.h>

std::string R3BSfrsFibOneHitData::toString() const
{
    return fmt::format("XFib: {}, YFib: {}, Xmm: {:.6f}, Ymm: {:.6f}, TimeNs: {:.6f}, TotX: {:.6f}, TotY: {:.6f}", GetXFib(), GetYFib(), GetXmm(), GetYmm(), GetTimeNs(), GetTotX(), GetTotY());
}

void R3BSfrsFibOneHitData::Print(const Option_t*) const
{
    std::cout << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const R3BSfrsFibOneHitData& data)
{
    os << data.toString();
    return os;
}

ClassImp(R3BSfrsFibOneHitData)
