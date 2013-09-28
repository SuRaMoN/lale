#include "statisticscalculator.h"

using namespace lale::core;

StatisticsCalculator::StatisticsCalculator(QPointer<ScoreRepository> aScoreRepository, QList<lale::core::Question> aQuestions, QObject *parent) :
    QObject(parent),
    scoreRepository(aScoreRepository),
    questions(aQuestions)
{
}

double StatisticsCalculator::calculatePercentageNotYetLearned()
{
    int notYetLearnedCount = 0;
    foreach(const Question & question, questions) {
        if(scoreRepository->getScoreFor(question) == 1) {
            notYetLearnedCount += 1;
        }
    }
    return (double) notYetLearnedCount / (double) questions.count();
}


void StatisticsCalculator::dataChanged()
{
    emit statisticsChanged(calculateStatistics());
}


Statistics StatisticsCalculator::calculateStatistics()
{
    Statistics statistics;

    statistics.percentageNotYetLearned = calculatePercentageNotYetLearned();

    return statistics;
}
