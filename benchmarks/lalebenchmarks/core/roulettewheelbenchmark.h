#ifndef LALEBENCHMARKS_CORE_ROULETTEWHEELBENCHMARK_H
#define LALEBENCHMARKS_CORE_ROULETTEWHEELBENCHMARK_H

#include "app/libs.h"

#include <QObject>
#include <QTest>

#include "core/roulettewheelselector.h"

namespace lalebenchmarks { namespace core {

class RouletteWheelBenchmark : public QObject
{
    Q_OBJECT

protected:
    void testRouletteSpeedWithParams(int numInserts, int numSelects);
    void testNaiveSpeedWithParams(int numInserts, int numSelects);
    int naivePick(const QList<lale::core::RouletteWheelSelector<int>::Area> &, lale::core::RandomGenerator &, double);

public:
    explicit RouletteWheelBenchmark(QObject *parent = 0);
    virtual ~RouletteWheelBenchmark();

private slots:
    void testRouletteSpeed();
    void testRouletteSpeed_data();
};

}}

#endif // LALEBENCHMARKS_CORE_ROULETTEWHEELBENCHMARK_H
