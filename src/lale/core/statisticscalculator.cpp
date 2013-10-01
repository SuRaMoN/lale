#include "statisticscalculator.h"

using namespace lale::core;

StatisticsCalculator::StatisticsCalculator(QPointer<ScoreRepository> aScoreRepository, QList<lale::core::Question> aQuestions, QObject *parent) :
    QObject(parent),
    scoreRepository(aScoreRepository),
    questions(aQuestions)
{
    recalculateStatistics();
}


void StatisticsCalculator::recalculateStatistics()
{
    stats.questionsNotYetLearnedCount = 0;
    foreach(const Question & question, questions) {
        double score = scoreRepository->getScoreFor(question);
        if(1 == score) {
            stats.questionsNotYetLearnedCount += 1;
        }
    }
    stats.questionCount = questions.count();
    stats.percentageNotYetLearned = (double) stats.questionsNotYetLearnedCount / (double) stats.questionCount;

    emit statisticsChanged(stats);
}


void StatisticsCalculator::scoreUpdatedForQuestion(Question, double oldValue, double newValue)
{
    if(1 == oldValue) {
        stats.questionsNotYetLearnedCount -= 1;
    }
    if(1 == newValue) {
        stats.questionsNotYetLearnedCount += 1;
    }

    stats.percentageNotYetLearned = (double) stats.questionsNotYetLearnedCount / (double) stats.questionCount;
    emit statisticsChanged(stats);
}


void StatisticsCalculator::triggerStatisticsChanged()
{
    emit statisticsChanged(stats);
}

Statistics StatisticsCalculator::getStatistics()
{
    return stats;
}
