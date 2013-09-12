#include "simplelearner.h"

#include "app/libs.h"
#include "core/question.h"

using namespace lale::learningstrategies;
using namespace lale::core;

SimpleLearner::SimpleLearner(QList<Question> questions, QPointer<ScoreRepository> scoreRepo, QObject *parent) :
    Learner(questions, parent)
{
    this->scoreRepo = scoreRepo;
}


SimpleLearner::~SimpleLearner()
{
}

void SimpleLearner::provideNewQuestion()
{
    Question question = questions[qrand() % questions.length()];
    emit newQuestion(question);
}

void SimpleLearner::wrongAnswerGiven(Question question)
{
    scoreRepo->updateScoreFor(question, 1);
}

void SimpleLearner::rightAnswerGiven(Question question)
{
    scoreRepo->multiplyScoreWith(question, 0.5);
}
