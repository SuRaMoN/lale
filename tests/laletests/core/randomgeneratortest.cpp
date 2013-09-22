#include "randomgeneratortest.h"

#include "core/randomgenerator.h"

using namespace laletests::core;
using namespace lale::core;

RandomGeneratorTest::RandomGeneratorTest(QObject *parent) :
    TestCase(parent)
{
}

RandomGeneratorTest::~RandomGeneratorTest()
{
}

void RandomGeneratorTest::testGetRandomDouble()
{
    RandomGenerator randomGenerator;
    for(int i = 0; i < 1000; i += 1) {
        double randomNumber = randomGenerator.getRandomDouble(1, 2);
        QVERIFY(randomNumber <= 2);
        QVERIFY(randomNumber >= 1);
    };
}

void RandomGeneratorTest::testSeed()
{
    double randomNumber1, randomNumber2;
    {
        RandomGenerator randomGenerator;
        randomNumber1 = randomGenerator.getRandomDouble(1, 2);
    }
    QTest::qSleep(10);
    {
        RandomGenerator randomGenerator;
        randomNumber2 = randomGenerator.getRandomDouble(1, 2);
    }
    QVERIFY(randomNumber1 != randomNumber2);
}
