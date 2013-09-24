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

void RandomGeneratorTest::testGetRandomInt()
{
    RandomGenerator randomGenerator;
    int frequenties[] = {0, 0};
    for(int i = 0; i < 1000; i += 1) {
        int randomNumber = randomGenerator.getRandomInt(0, 1);
        frequenties[randomNumber] += 1;
    };
    QVERIFY(abs(frequenties[0] - 500) < 100);
    QVERIFY(abs(frequenties[1] - 500) < 100);
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
