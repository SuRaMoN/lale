#include "learner.h"

using namespace lale::learningstrategies;
using namespace lale::core;

Learner::Learner(QList<Question> questions, QObject *parent) : QObject(parent)
{
    this->questions = questions;
}

Learner::~Learner()
{
}
