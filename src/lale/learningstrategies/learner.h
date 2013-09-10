#ifndef LALE_LEARNINGSTRATEGIES_LEARNER_H
#define LALE_LEARNINGSTRATEGIES_LEARNER_H

#include "app/lale.h"
#include "core/question.h"

namespace lale { namespace learningstrategies {

class Learner : public QObject
{
    Q_OBJECT

protected:
    QList<core::Question> questions;

public:
    explicit Learner(QList<core::Question>, QObject *parent = 0);
    virtual ~Learner();
    
signals:
    void newQuestion(lale::core::Question);
    
public slots:
    virtual void provideNewQuestion() = 0;
    virtual void wrongAnswerGiven(lale::core::Question) = 0;
    virtual void correctAnswerGiven(lale::core::Question) = 0;
};

}}

#endif // LALE_LEARNINGSTRATEGIES_LEARNER_H
