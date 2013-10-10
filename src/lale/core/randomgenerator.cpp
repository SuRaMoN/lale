#include "randomgenerator.h"

#include "impl/randomgeneratorimpl.h"

using namespace lale::core;

RandomGenerator::RandomGenerator() :
    impl(new impl::RandomGeneratorImpl())
{
}

double RandomGenerator::getRandomDouble(double min, double max)
{
    return impl->getRandomDouble(min, max);
}

double RandomGenerator::getRandomInt(int min, int max)
{
    return impl->getRandomInt(min, max);
}

RandomGenerator::~RandomGenerator()
{
}
