#include "naivelearner.h"

using namespace lale::learningstrategies;
using namespace lale::core;

NaiveLearner::NaiveLearner(QList<Question> questions, QObject *parent) : Learner(questions, parent)
{
}

NaiveLearner::~NaiveLearner()
{
}

void NaiveLearner::provideNewQuestion()
{
    Question question = questions[qrand() % questions.length()];
    emit newQuestion(question);
}
