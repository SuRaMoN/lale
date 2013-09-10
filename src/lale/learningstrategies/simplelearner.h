#ifndef LALE_LEARNINGSTRATEGIES_SIMPLELEARNER_H
#define LALE_LEARNINGSTRATEGIES_SIMPLELEARNER_H

#include "app/lale.h"
#include "learner.h"

namespace lale { namespace learningstrategies {

class SimpleLearner : public Learner
{
    Q_OBJECT

public:
    explicit SimpleLearner(QList<core::Question>, QObject *parent = 0);
    virtual ~SimpleLearner();
    
signals:
    
public slots:
    void provideNewQuestion();
    void wrongAnswerGiven(lale::core::Question);
    void correctAnswerGiven(lale::core::Question);
};

}}

#endif // LALE_LEARNINGSTRATEGIES_SIMPLELEARNER_H
