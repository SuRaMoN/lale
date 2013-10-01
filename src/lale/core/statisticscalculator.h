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
    lale::core::Statistics stats;

    void recalculateStatistics();

public:
    explicit StatisticsCalculator(QPointer<lale::core::ScoreRepository>, QList<lale::core::Question>, QObject *parent = 0);
    double calculatePercentageNotYetLearned();
    void triggerStatisticsChanged();
    lale::core::Statistics getStatistics();

public slots:
    void scoreUpdatedForQuestion(lale::core::Question, double, double);

signals:
    void statisticsChanged(lale::core::Statistics);
};

}}

#endif // LALE_CORE_STATISTICSCALCULATOR_H
