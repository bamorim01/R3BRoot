// -----------------------------------------------------------------------
// -----          R3BSfrsFibOneMappedData source file               -----
// -----------------------------------------------------------------------

#include "R3BSfrsFibOneMappedData.h"

#include <fmt/core.h>

R3BSfrsFibOneMappedData::R3BSfrsFibOneMappedData(uint16_t side,
                                                 uint16_t type,
                                                 uint16_t channel,
                                                 uint16_t edge,
                                                 uint16_t coarse,
                                                 uint16_t fine)
    : fSide(side)
    , fType(type)
    , fChannel(channel)
    , fEdge(edge)
    , fCoarse(coarse)
    , fFine(fine)
{
}

std::string R3BSfrsFibOneMappedData::toString() const
{
    return fmt::format("Side: {}, Type: {}, Channel: {}, Edge: {}, Coarse: {}, Fine: {}",
                       GetSide(),
                       GetType(),
                       GetChannel(),
                       GetEdge(),
                       GetCoarse(),
                       GetFine());
}

void R3BSfrsFibOneMappedData::Print(const Option_t*) const
{
    std::cout << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const R3BSfrsFibOneMappedData& data)
{
    os << data.toString();
    return os;
}

ClassImp(R3BSfrsFibOneMappedData)
