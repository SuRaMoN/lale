#ifndef LALE_CORE_RANDOMGENERATOR_H
#define LALE_CORE_RANDOMGENERATOR_H

#include "app/libs.h"

namespace lale { namespace core {

class RandomGenerator
{
protected:
    boost::mt19937 seed;
    int getSeedInput();

public:
    RandomGenerator();
    virtual ~RandomGenerator();

    double getRandomDouble(double min = 0, double max = 1);
};

}}

#endif // LALE_CORE_RANDOMGENERATOR_H
