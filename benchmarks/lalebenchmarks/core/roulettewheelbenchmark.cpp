#include "roulettewheelbenchmark.h"

#include <boost/format.hpp>

using namespace lalebenchmarks::core;
using namespace lale::core;
using namespace boost;

RouletteWheelBenchmark::RouletteWheelBenchmark(QObject *parent) :
    QObject(parent)
{
}


RouletteWheelBenchmark::~RouletteWheelBenchmark()
{
}

void RouletteWheelBenchmark::testRouletteSpeedWithParams(int numInserts, int numSelects)
{
    typedef RouletteWheelSelector<int> RandomPicker;
    RandomGenerator randomGenerator;

    QList<RandomPicker::Area> areas;
    for(int i = 0; i < numInserts; ++i) {
        areas << RandomPicker::Area(i, randomGenerator.getRandomDouble(0, 1));
    }

    RandomPicker randomPicker(areas.constBegin(), areas.constEnd(), randomGenerator);

    QBENCHMARK {
        for(int i = 0; i < numSelects; ++i) {
            randomPicker.pickRandom();
        }
    }
}


void RouletteWheelBenchmark::testNaiveSpeedWithParams(int numInserts, int numSelects)
{
    typedef RouletteWheelSelector<int> RandomPicker;
    RandomGenerator randomGenerator;

    double totalChildAreaSize = 0;
    QList<RandomPicker::Area> areas;
    for(int i = 0; i < numInserts; ++i) {
        double randomArea = randomGenerator.getRandomDouble(0, 1);
        totalChildAreaSize += randomArea;
        areas << RandomPicker::Area(i, randomArea);
    }

    QBENCHMARK {
        for(int i = 0; i < numSelects; ++i) {
            naivePick(areas, randomGenerator, totalChildAreaSize);
        }
    }
}


int RouletteWheelBenchmark::naivePick(const QList<RouletteWheelSelector<int>::Area> & areas, RandomGenerator & randomGenerator, double totalChildAreaSize)
{
    typedef RouletteWheelSelector<int>::Area Area;
    double areaSumLimit = randomGenerator.getRandomDouble(0., totalChildAreaSize);
    double currentAreaSum = 0;
    foreach(Area area, areas) {
        currentAreaSum += area.areaSize;
        if(currentAreaSum >= areaSumLimit) {
            return *(area.property);
        }
    }
    throw std::logic_error("Random generator creates values that are too large");
}

void RouletteWheelBenchmark::testRouletteSpeed()
{
    QFETCH(bool, useNaive);
    QFETCH(int, numInserts);

    if(useNaive) {
        testNaiveSpeedWithParams(numInserts, 1000);
    } else {
        testRouletteSpeedWithParams(numInserts, 1000);
    }
}

void RouletteWheelBenchmark::testRouletteSpeed_data()
{
    QTest::addColumn<bool>("useNaive");
    QTest::addColumn<int>("numInserts");

    QList<int> numInsertsList;
    numInsertsList << 100 << 200 << 300 << 500 << 1000 << 2000 << 3000 << 4000 << 5000;
    foreach(int numInserts, numInsertsList) {
        QTest::newRow(str(format("naive (size: %1%, selects: 1000)") % numInserts).c_str()) << true << numInserts;
        QTest::newRow(str(format("optimized (size: %1%, selects: 1000)") % numInserts).c_str()) << false << numInserts;
    }
}
