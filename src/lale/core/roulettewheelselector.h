#ifndef LALE_CORE_ROULETTEWHEELSELECTOR_H
#define LALE_CORE_ROULETTEWHEELSELECTOR_H

#include "app/libs.h"
#include <stdexcept>
#include "core/randomgenerator.h"

namespace lale { namespace core {

template<typename T>
class RouletteWheelSelector : public std::map<T, double>
{
public:
    typedef T AreaProperty;
    typedef std::map<AreaProperty, double> AreaMap;
    typedef typename AreaMap::iterator AreaMapIterator;

protected:
    RandomGenerator randomGenerator;

public:
    RouletteWheelSelector(RandomGenerator aRandomGenerator) : randomGenerator(aRandomGenerator)
    {
    }

    double getTotalAreaSize()
    {
        double totalAreaSize = 0;
        for(AreaMapIterator i = this->begin(); i != this->end(); ++i) {
            totalAreaSize += i->second;
        }
        return totalAreaSize;
    }

    AreaProperty pickRandom()
    {
        if(this->size() == 0) {
            throw std::logic_error("Can not pick a random are from an empty set.");
        }
        double totalAreaSize = getTotalAreaSize();

        double areaSumLimit = randomGenerator.getRandomDouble(0, totalAreaSize);
        double currentAreaSum = 0;
        for(AreaMapIterator i = this->begin(); i != this->end(); ++i) {
            currentAreaSum += i->second;
            if(currentAreaSum >= areaSumLimit) {
                return i->first;
            }
        }

        throw std::logic_error("Random generator creates values that are too large");
    }

    virtual ~RouletteWheelSelector()
    {
    }
};

}}

#endif // LALE_CORE_ROULETTEWHEELSELECTOR_H
