#include "teacher.h"

using namespace lale::learningstrategies;
using namespace lale::core;

Teacher::Teacher(QList<Question> questions, QObject *parent) : QObject(parent)
{
    this->questions = questions;
}

Teacher::~Teacher()
{
}
