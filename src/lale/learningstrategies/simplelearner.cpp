#include "simplelearner.h"

using namespace lale::learningstrategies;
using namespace lale::core;

SimpleLearner::SimpleLearner(QList<Question> questions, QPointer<ScoreRepository> scoreRepo, QObject *parent) :
    Learner(questions, parent),
    randomPicker(RandomGenerator())
{
    this->scoreRepo = scoreRepo;
    foreach(Question question, questions) {
        randomPicker[question] = scoreRepo->getScoreFor(question);
    }
}

SimpleLearner::~SimpleLearner()
{
}

void SimpleLearner::provideNewQuestion()
{
    emit newQuestion(randomPicker.pickRandom());
}

void SimpleLearner::wrongAnswerGiven(Question question)
{
    scoreRepo->updateScoreFor(question, 1);
}

void SimpleLearner::rightAnswerGiven(Question question)
{
    scoreRepo->multiplyScoreWith(question, 0.5);
    randomPicker[question] /= 2;
}
