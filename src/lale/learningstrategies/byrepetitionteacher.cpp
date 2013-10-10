#include "byrepetitionteacher.h"

#include <cmath>


using namespace lale::learningstrategies;
using namespace lale::core;

ByRepetitionTeacher::ByRepetitionTeacher(QList<Question> questions, QPointer<ScoreRepository> scoreRepo, RandomGenerator aRandomGenerator, QObject *parent) :
    Teacher(questions, parent),
    randomGenerator(aRandomGenerator),
    randomQuestionPicker(aRandomGenerator),
    repeatPoolRandomQuestionPicker(aRandomGenerator)
{
    repeatPoolMaxScoreSum = 6;
    numRightAnswersToRemoveFromRepeatPool = 4;
    numQuestionsBeforeRepititionAllowed = 3;

    this->scoreRepo = scoreRepo;
    foreach(Question question, questions) {
        randomQuestionPicker[question] = scoreRepo->getScoreFor(question);
    }
}

ByRepetitionTeacher::~ByRepetitionTeacher()
{
}

void ByRepetitionTeacher::provideNewQuestion()
{
    Question newQuestionCandidate = getNewQuestionCandidate();
    for(int i = 0; i < 20 && previousQuestions.contains(newQuestionCandidate); ++i) {
        newQuestionCandidate = getNewQuestionCandidate();
    }
    previousQuestions.append(newQuestionCandidate);
    if(previousQuestions.size() > numQuestionsBeforeRepititionAllowed) {
        previousQuestions.removeFirst();
    }
    emit newQuestion(newQuestionCandidate);
}

Question ByRepetitionTeacher::getNewQuestionCandidate()
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

void ByRepetitionTeacher::wrongAnswerGiven(Question question)
{
    repeatPoolRandomQuestionPicker[question] = 1;
    scoreRepo->updateScoreFor(question, 1);
}

void ByRepetitionTeacher::rightAnswerGiven(Question question)
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

unsigned int ByRepetitionTeacher::getNumRightAnswersToRemoveFromRepeatPool() const
{
    return numRightAnswersToRemoveFromRepeatPool;
}

void ByRepetitionTeacher::setNumRightAnswersToRemoveFromRepeatPool(unsigned int value)
{
    numRightAnswersToRemoveFromRepeatPool = value;
}

unsigned int ByRepetitionTeacher::getRepeatPoolMaxScoreSum() const
{
    return repeatPoolMaxScoreSum;
}

void ByRepetitionTeacher::setRepeatPoolMaxScoreSum(unsigned int value)
{
    repeatPoolMaxScoreSum = value;
}
