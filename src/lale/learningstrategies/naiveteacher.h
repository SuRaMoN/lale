#ifndef LALE_LEARNINGSTRATEGIES_NAIVETEACHER_H
#define LALE_LEARNINGSTRATEGIES_NAIVETEACHER_H

#include "app/libs.h"
#include "core/randomgenerator.h"
#include "teacher.h"

namespace lale { namespace learningstrategies {

class NaiveTeacher : public Teacher
{
    Q_OBJECT
protected:
    lale::core::RandomGenerator randomGenerator;

public:
    explicit NaiveTeacher(QList<core::Question>, QObject *parent = 0);
    virtual ~NaiveTeacher();
    
signals:
    void newQuestion(lale::core::Question);
    
public slots:
    void provideNewQuestion();
    void wrongAnswerGiven(lale::core::Question);
    void rightAnswerGiven(lale::core::Question);
};

}}

#endif // LALE_LEARNINGSTRATEGIES_NAIVETEACHER_H
