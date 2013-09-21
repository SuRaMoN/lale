#ifndef LALE_CORE_QUESTION_H
#define LALE_CORE_QUESTION_H

#include "app/libs.h"

namespace lale { namespace core {

class Question
{
protected:
    QString question;
    QString answer;

public:
    Question(QString question, QString answer);
    virtual ~Question();

    QString getQuestion() const;
    void setQuestion(const QString &value);
    QString getAnswer() const;
    void setAnswer(const QString &value);

    bool operator < (const Question &) const;
    bool operator == (const Question &) const;
};

}}

#endif // LALE_CORE_QUESTION_H
