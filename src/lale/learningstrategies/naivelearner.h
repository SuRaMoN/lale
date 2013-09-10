#ifndef LALE_LEARNINGSTRATEGIES_NAIVELEARNER_H
#define LALE_LEARNINGSTRATEGIES_NAIVELEARNER_H

#include "app/lale.h"
#include "learner.h"

namespace lale { namespace learningstrategies {

class NaiveLearner : public Learner
{
    Q_OBJECT

public:
    explicit NaiveLearner(QList<core::Question>, QObject *parent = 0);
    virtual ~NaiveLearner();
    
signals:
    void newQuestion(lale::core::Question);
    
public slots:
    void provideNewQuestion();
    void wrongAnswerGiven(lale::core::Question);
    void correctAnswerGiven(lale::core::Question);
};

}}

#endif // LALE_LEARNINGSTRATEGIES_NAIVELEARNER_H
