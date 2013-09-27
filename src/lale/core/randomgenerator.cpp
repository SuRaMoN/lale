#include "randomgenerator.h"

#include <boost/random/uniform_real.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/variate_generator.hpp>
#include <sys/time.h>

using namespace lale::core;

RandomGenerator::RandomGenerator() :
    seed(new boost::mt19937(getSeedInput()))
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
    boost::uniform_real<> dist(min, max);
    boost::variate_generator<boost::mt19937&, boost::uniform_real<double> > random(*seed, dist);
    return random();
}

double RandomGenerator::getRandomInt(int min, int max)
{
    boost::uniform_int<> dist(min, max);
    boost::variate_generator<boost::mt19937&, boost::uniform_int<> > random(*seed, dist);
    return random();
}

RandomGenerator::~RandomGenerator()
{
}
