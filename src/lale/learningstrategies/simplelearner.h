#ifndef LALE_LEARNINGSTRATEGIES_SIMPLELEARNER_H
#define LALE_LEARNINGSTRATEGIES_SIMPLELEARNER_H

#include "app/libs.h"
#include "learner.h"
#include "core/scorerepository.h"

namespace lale { namespace learningstrategies {

class SimpleLearner : public Learner
{
    Q_OBJECT

    QPointer<lale::core::ScoreRepository> scoreRepo;

public:
    explicit SimpleLearner(QList<core::Question>, QPointer<lale::core::ScoreRepository>, QObject *parent = 0);
    virtual ~SimpleLearner();

public slots:
    void provideNewQuestion();
    void wrongAnswerGiven(lale::core::Question);
    void rightAnswerGiven(lale::core::Question);
};

}}

#endif // LALE_LEARNINGSTRATEGIES_SIMPLELEARNER_H
