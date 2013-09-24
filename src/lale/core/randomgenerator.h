#ifndef LALE_CORE_RANDOMGENERATOR_H
#define LALE_CORE_RANDOMGENERATOR_H

#include "app/libs.h"

namespace lale { namespace core {

class RandomGenerator
{
protected:
    boost::shared_ptr<boost::mt19937> seed;
    int getSeedInput();

public:
    RandomGenerator();
    virtual ~RandomGenerator();

    double getRandomDouble(double min = 0, double max = 1);
    double getRandomInt(int min = std::numeric_limits<int>::min(), int max = std::numeric_limits<int>::max());
};

}}

#endif // LALE_CORE_RANDOMGENERATOR_H
