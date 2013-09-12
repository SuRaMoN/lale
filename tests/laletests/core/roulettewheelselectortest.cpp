#include "roulettewheelselectortest.h"

using namespace laletests::core;
using namespace lale::core;

RouletteWheelSelectorTest::RouletteWheelSelectorTest(QObject *parent) :
    TestCase(parent)
{
}


RouletteWheelSelectorTest::~RouletteWheelSelectorTest()
{
}

void RouletteWheelSelectorTest::testSimpleRandomPicks()
{
    typedef RouletteWheelSelector<QString> RandomPicker;

    QList<RandomPicker::Area> list;
    list << RandomPicker::Area(QString("a"), 1.42)
         << RandomPicker::Area(QString("b"), 2.85)
         << RandomPicker::Area(QString("c"), 5.72);

    RandomPicker randomPicker(list.constBegin(), list.constEnd(), RandomGenerator());
    for(int i = 0; i < 10; ++i) {
        QVERIFY(randomPicker.pickRandom() <= "c");
        QVERIFY(randomPicker.pickRandom() >= "a");
    }
}

void RouletteWheelSelectorTest::testFrequency()
{
    const int NUM_ROTATIONS = 5000;
    typedef RouletteWheelSelector<int> RandomPicker;

    QList<RandomPicker::Area> list;
    list << RandomPicker::Area(0, 3.22580645161)
         << RandomPicker::Area(1, 6.45161290323)
         << RandomPicker::Area(2, 12.9032258065)
         << RandomPicker::Area(3, 25.8064516129)
         << RandomPicker::Area(4, 51.6129032258); // sum off areas is 100

    RandomPicker randomPicker(list.constBegin(), list.constEnd(), RandomGenerator());
    int frenquency[] = {0, 0, 0, 0, 0};
    for(int i = 0; i < NUM_ROTATIONS; ++i) {
        frenquency[randomPicker.pickRandom()] += 1;
    }
    QVERIFY(abs(3.22580645161 - (double) frenquency[0] * 100 / NUM_ROTATIONS) < 2);
    QVERIFY(abs(6.45161290323 - (double) frenquency[1] * 100 / NUM_ROTATIONS) < 2);
    QVERIFY(abs(12.9032258065 - (double) frenquency[2] * 100 / NUM_ROTATIONS) < 2);
    QVERIFY(abs(25.8064516129 - (double) frenquency[3] * 100 / NUM_ROTATIONS) < 2);
    QVERIFY(abs(51.6129032258 - (double) frenquency[4] * 100 / NUM_ROTATIONS) < 2);
}
