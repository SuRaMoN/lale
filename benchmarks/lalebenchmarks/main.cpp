
#include "app/libs.h"

#include <QTest>

#include "core/roulettewheelbenchmark.h"

using namespace lalebenchmarks::core;


int main(int argc, char *argv[])
{
    int result = 0;

    QPointer<RouletteWheelBenchmark> rouletteWheelBenchmark = new RouletteWheelBenchmark();
    result |= QTest::qExec(rouletteWheelBenchmark, argc, argv);

    return result;
}
