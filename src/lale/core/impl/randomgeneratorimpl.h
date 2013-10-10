#ifndef LALE_CORE_IMPL_RANDOMGENERATOR_H
#define LALE_CORE_IMPL_RANDOMGENERATOR_H

#include "app/libs.h"
#include <boost/random/mersenne_twister.hpp>

namespace lale { namespace core { namespace impl {

class RandomGeneratorImpl
{
protected:
    boost::shared_ptr<boost::mt19937> seed;
    int getSeedInput();

public:
    RandomGeneratorImpl();
    virtual ~RandomGeneratorImpl();

    double getRandomDouble(double min = 0, double max = 1);
    double getRandomInt(int min = std::numeric_limits<int>::min(), int max = std::numeric_limits<int>::max());
};

}}}

#endif // LALE_CORE_IMPL_RANDOMGENERATOR_H
