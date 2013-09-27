#include "byrepetitionlearner.h"

using namespace lale::learningstrategies;
using namespace lale::core;

ByRepetitionLearner::ByRepetitionLearner(QList<Question> questions, QPointer<ScoreRepository> scoreRepo, RandomGenerator aRandomGenerator, QObject *parent) :
    previousQuestion("", ""),
    Learner(questions, parent),
    randomGenerator(aRandomGenerator),
    randomQuestionPicker(aRandomGenerator),
    repeatPoolRandomQuestionPicker(aRandomGenerator)
{
    repeatPoolMaxScoreSum = 6;
    numRightAnswersToRemoveFromRepeatPool = 4;

    this->scoreRepo = scoreRepo;
    foreach(Question question, questions) {
        randomQuestionPicker[question] = scoreRepo->getScoreFor(question);
    }
}

ByRepetitionLearner::~ByRepetitionLearner()
{
}

void ByRepetitionLearner::provideNewQuestion()
{
    Question newQuestionCandidate = getNewQuestionCandidate();
    for(int i = 0; i < 100 && newQuestionCandidate == previousQuestion; ++i) {
        newQuestionCandidate = getNewQuestionCandidate();
    }
    previousQuestion = newQuestionCandidate;
    emit newQuestion(newQuestionCandidate);
}

Question ByRepetitionLearner::getNewQuestionCandidate()
{
    if(repeatPoolRandomQuestionPicker.getTotalAreaSize() >= repeatPoolMaxScoreSum) {
        return repeatPoolRandomQuestionPicker.pickRandom();
    }

    if(repeatPoolRandomQuestionPicker.size() == 0) {
        return randomQuestionPicker.pickRandom();
    }

    double randomAreaLimit = randomGenerator.getRandomDouble(0, repeatPoolMaxScoreSum);
    if(randomAreaLimit < repeatPoolRandomQuestionPicker.size()) {
        return repeatPoolRandomQuestionPicker.pickRandom();
    } else {
        return randomQuestionPicker.pickRandom();
    }
}

void ByRepetitionLearner::wrongAnswerGiven(Question question)
{
    repeatPoolRandomQuestionPicker[question] = 1;
    scoreRepo->updateScoreFor(question, 1);
}

void ByRepetitionLearner::rightAnswerGiven(Question question)
{
    if(repeatPoolRandomQuestionPicker.count(question) == 1) {
        repeatPoolRandomQuestionPicker[question] /= 2;
        double maxScore = 1 / std::pow(2., (double) numRightAnswersToRemoveFromRepeatPool);
        if(repeatPoolRandomQuestionPicker[question] <= maxScore) {
            repeatPoolRandomQuestionPicker.erase(repeatPoolRandomQuestionPicker.find(question));
        }
    } else {
        randomQuestionPicker[question] /= 2;
        scoreRepo->multiplyScoreWith(question, 0.5);
    }
}

unsigned int ByRepetitionLearner::getNumRightAnswersToRemoveFromRepeatPool() const
{
    return numRightAnswersToRemoveFromRepeatPool;
}

void ByRepetitionLearner::setNumRightAnswersToRemoveFromRepeatPool(unsigned int value)
{
    numRightAnswersToRemoveFromRepeatPool = value;
}

unsigned int ByRepetitionLearner::getRepeatPoolMaxScoreSum() const
{
    return repeatPoolMaxScoreSum;
}

void ByRepetitionLearner::setRepeatPoolMaxScoreSum(unsigned int value)
{
    repeatPoolMaxScoreSum = value;
}
