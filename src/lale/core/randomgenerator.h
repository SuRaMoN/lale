#ifndef LALE_CORE_RANDOMGENERATOR_H
#define LALE_CORE_RANDOMGENERATOR_H

#include "app/libs.h"

namespace lale { namespace core {

namespace impl { class RandomGeneratorImpl; }

class RandomGenerator
{
protected:
    boost::shared_ptr<impl::RandomGeneratorImpl> impl;

public:
    RandomGenerator();
    virtual ~RandomGenerator();

    double getRandomDouble(double min = 0, double max = 1);
    double getRandomInt(int min = std::numeric_limits<int>::min(), int max = std::numeric_limits<int>::max());
};

}}

#endif // LALE_CORE_RANDOMGENERATOR_H
