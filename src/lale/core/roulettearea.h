#ifndef LALE_CORE_ROULETTEAREA_H
#define LALE_CORE_ROULETTEAREA_H

#include "app/libs.h"

namespace lale { namespace core {

template<typename T>
class RouletteArea
{
public:
    typedef T Property;

    boost::optional<Property> property;
    double areaSize;

    RouletteArea(const boost::optional<Property> & property, double areaSize)
    {
        this->property = property;
        this->areaSize = areaSize;
    }

    virtual ~RouletteArea()
    {
    }
};

}}

#endif // LALE_CORE_ROULETTEAREA_H
