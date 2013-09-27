#ifndef LALE_LEARNINGSTRATEGIES_NAIVELEARNER_H
#define LALE_LEARNINGSTRATEGIES_NAIVELEARNER_H

#include "app/libs.h"
#include "core/randomgenerator.h"
#include "learner.h"

namespace lale { namespace learningstrategies {

class NaiveLearner : public Learner
{
    Q_OBJECT
protected:
    lale::core::RandomGenerator randomGenerator;

public:
    explicit NaiveLearner(QList<core::Question>, QObject *parent = 0);
    virtual ~NaiveLearner();
    
signals:
    void newQuestion(lale::core::Question);
    
public slots:
    void provideNewQuestion();
    void wrongAnswerGiven(lale::core::Question);
    void rightAnswerGiven(lale::core::Question);
};

}}

#endif // LALE_LEARNINGSTRATEGIES_NAIVELEARNER_H
