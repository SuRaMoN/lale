#include "question.h"

using namespace lale::core;


Question::Question(QString question, QString answer)
{
    this->question = question;
    this->answer = answer;
}

Question::~Question()
{
}

QString Question::getQuestion() const
{
    return question;
}

void Question::setQuestion(const QString &value)
{
    question = value;
}

QString Question::getAnswer() const
{
    return answer;
}

void Question::setAnswer(const QString &value)
{
    answer = value;
}

bool Question::operator < (const Question & that) const
{
    if(this->getQuestion() != that.getQuestion()) {
        return this->getQuestion() < that.getQuestion();
    }
    return this->getAnswer() < that.getAnswer();
}

bool Question::operator == (const Question & that) const
{
    return this->getQuestion() == that.getQuestion() && this->getAnswer() == that.getAnswer();
}
