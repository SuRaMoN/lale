#ifndef LALE_LEARNINGSTRATEGIES_LEARNER_H
#define LALE_LEARNINGSTRATEGIES_LEARNER_H

#include <QObject>
#include <QList>
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
    
};

}}

#endif // LALE_LEARNINGSTRATEGIES_LEARNER_H
