#include "simpleteacher.h"

using namespace lale::learningstrategies;
using namespace lale::core;

SimpleTeacher::SimpleTeacher(QList<Question> questions, QPointer<ScoreRepository> scoreRepo, QObject *parent) :
    Teacher(questions, parent),
    randomPicker(RandomGenerator())
{
    this->scoreRepo = scoreRepo;
    foreach(Question question, questions) {
        randomPicker[question] = scoreRepo->getScoreFor(question);
    }
}

SimpleTeacher::~SimpleTeacher()
{
}

void SimpleTeacher::provideNewQuestion()
{
    emit newQuestion(randomPicker.pickRandom());
}

void SimpleTeacher::wrongAnswerGiven(Question question)
{
    scoreRepo->updateScoreFor(question, 1);
}

void SimpleTeacher::rightAnswerGiven(Question question)
{
    scoreRepo->multiplyScoreWith(question, 0.5);
    randomPicker[question] /= 2;
}
