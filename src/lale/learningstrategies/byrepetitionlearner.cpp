#include "byrepetitionlearner.h"

using namespace lale::learningstrategies;
using namespace lale::core;

ByRepetitionLearner::ByRepetitionLearner(QList<Question> questions, QPointer<ScoreRepository> scoreRepo, RandomGenerator aRandomGenerator, QObject *parent) :
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
    qDebug() << "\n" << "Total area size repeat pool: " << repeatPoolRandomQuestionPicker.getTotalAreaSize();
    qDebug() << "repeat pool max score sum: " << repeatPoolMaxScoreSum;
    qDebug() << "Repeat Pool: ";
    for(RouletteWheelSelector<Question>::iterator i = repeatPoolRandomQuestionPicker.begin(); i != repeatPoolRandomQuestionPicker.end(); ++i) {
        qDebug() << "\t" << i->first.getQuestion() << ": " << i->second;
    }

    if(repeatPoolRandomQuestionPicker.getTotalAreaSize() >= repeatPoolMaxScoreSum) {
        emit newQuestion(repeatPoolRandomQuestionPicker.pickRandom());
        return;
    }

    if(repeatPoolRandomQuestionPicker.size() == 0) {
        emit newQuestion(randomQuestionPicker.pickRandom());
        return;
    }

    double randomAreaLimit = randomGenerator.getRandomDouble(0, repeatPoolMaxScoreSum);
    if(randomAreaLimit < repeatPoolRandomQuestionPicker.size()) {
        qDebug() << "question from repeat pool because: " << randomAreaLimit << " < " << repeatPoolRandomQuestionPicker.size();
        emit newQuestion(repeatPoolRandomQuestionPicker.pickRandom());
    } else {
        qDebug() << "question from global pool because: " << randomAreaLimit << " >= " << repeatPoolRandomQuestionPicker.size();
        emit newQuestion(randomQuestionPicker.pickRandom());
    }
}

void ByRepetitionLearner::wrongAnswerGiven(Question question)
{
    qDebug() << "\n" << "Wrong answer given";
    qDebug() << "Previous score: " << scoreRepo->getScoreFor(question);
    repeatPoolRandomQuestionPicker[question] = 1;
    scoreRepo->updateScoreFor(question, 1);
    qDebug() << "New score: " << scoreRepo->getScoreFor(question);
}

void ByRepetitionLearner::rightAnswerGiven(Question question)
{
    qDebug() << "\n" << "Right answer given";
    if(repeatPoolRandomQuestionPicker.count(question) == 1) {
        qDebug() << "Question is in repeat pool";
        qDebug() << "Global score: " << scoreRepo->getScoreFor(question);
        qDebug() << "Previous repeat pool score: " << repeatPoolRandomQuestionPicker[question];
        repeatPoolRandomQuestionPicker[question] /= 2;
        qDebug() << "New repeat pool score: " << repeatPoolRandomQuestionPicker[question];
        double maxScore = 1 / pow(2, numRightAnswersToRemoveFromRepeatPool);
        if(repeatPoolRandomQuestionPicker[question] <= maxScore) {
            qDebug() << "\n" << "Question is removed from repeat pool";
            repeatPoolRandomQuestionPicker.erase(repeatPoolRandomQuestionPicker.find(question));
        }
        qDebug() << "Global score: " << scoreRepo->getScoreFor(question);
    } else {
        qDebug() << "Question was not in repeat pool";
        qDebug() << "Previous score: " << scoreRepo->getScoreFor(question);
        randomQuestionPicker[question] /= 2;
        scoreRepo->multiplyScoreWith(question, 0.5);
        qDebug() << "New score: " << scoreRepo->getScoreFor(question);
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
