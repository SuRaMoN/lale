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
    Question question = questions[randomGenerator.getRandomInt(0, questions.length() - 1)];
    emit newQuestion(question);
}

void NaiveLearner::wrongAnswerGiven(Question)
{
}

void NaiveLearner::rightAnswerGiven(Question)
{
}
