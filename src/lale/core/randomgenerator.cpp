#include "randomgenerator.h"

#include <boost/random/uniform_real.hpp>
#include <boost/random/variate_generator.hpp>

using namespace lale::core;

RandomGenerator::RandomGenerator() :
    seed(getSeedInput())
{
}

int RandomGenerator::getSeedInput()
{
    timeval t;
    gettimeofday(&t, NULL);
    return t.tv_usec ^ t.tv_sec;
}

double RandomGenerator::getRandomDouble(double min, double max)
{
    boost::uniform_real<> dist(min,max);
    boost::variate_generator<boost::mt19937&, boost::uniform_real<double> > random(seed, dist);
    return random();
}

RandomGenerator::~RandomGenerator()
{
}
