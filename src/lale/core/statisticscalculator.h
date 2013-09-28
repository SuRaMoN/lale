#ifndef LALE_CORE_STATISTICSCALCULATOR_H
#define LALE_CORE_STATISTICSCALCULATOR_H

#include "app/libs.h"
#include "scorerepository.h"
#include "statistics.h"

namespace lale { namespace core {

class StatisticsCalculator : public QObject
{
    Q_OBJECT

protected:
    QPointer<lale::core::ScoreRepository> scoreRepository;
    QList<lale::core::Question> questions;

public:
    explicit StatisticsCalculator(QPointer<lale::core::ScoreRepository>, QList<lale::core::Question>, QObject *parent = 0);
    double calculatePercentageNotYetLearned();
    lale::core::Statistics calculateStatistics();

public slots:
    void dataChanged();

signals:
    void statisticsChanged(lale::core::Statistics);
};

}}

#endif // LALE_CORE_STATISTICSCALCULATOR_H
