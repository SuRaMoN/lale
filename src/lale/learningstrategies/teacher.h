#ifndef LALE_LEARNINGSTRATEGIES_TEACHER_H
#define LALE_LEARNINGSTRATEGIES_TEACHER_H

#include "app/libs.h"
#include "core/question.h"

namespace lale { namespace learningstrategies {

class Teacher : public QObject
{
    Q_OBJECT

protected:
    QList<core::Question> questions;

public:
    explicit Teacher(QList<core::Question>, QObject *parent = 0);
    virtual ~Teacher();
    
signals:
    void newQuestion(lale::core::Question);
    
public slots:
    virtual void provideNewQuestion() = 0;
    virtual void wrongAnswerGiven(lale::core::Question) = 0;
    virtual void rightAnswerGiven(lale::core::Question) = 0;
};

}}

#endif // LALE_LEARNINGSTRATEGIES_TEACHER_H
