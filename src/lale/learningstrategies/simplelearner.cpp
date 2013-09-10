#include "simplelearner.h"

using namespace lale::learningstrategies;

SimpleLearner::SimpleLearner(QList<core::Question> questions, QObject *parent) : Learner(questions, parent)
{
}


SimpleLearner::~SimpleLearner()
{
}

void SimpleLearner::provideNewQuestion()
{
}

void SimpleLearner::wrongAnswerGiven(lale::core::Question)
{
}

void SimpleLearner::correctAnswerGiven(lale::core::Question)
{
}
