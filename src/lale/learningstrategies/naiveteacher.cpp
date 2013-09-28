#include "naiveteacher.h"

using namespace lale::learningstrategies;
using namespace lale::core;

NaiveTeacher::NaiveTeacher(QList<Question> questions, QObject *parent) : Teacher(questions, parent)
{
}

NaiveTeacher::~NaiveTeacher()
{
}

void NaiveTeacher::provideNewQuestion()
{
    Question question = questions[randomGenerator.getRandomInt(0, questions.length() - 1)];
    emit newQuestion(question);
}

void NaiveTeacher::wrongAnswerGiven(Question)
{
}

void NaiveTeacher::rightAnswerGiven(Question)
{
}
