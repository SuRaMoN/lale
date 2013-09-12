#ifndef QUESTIONSIGNALFETCHER_H
#define QUESTIONSIGNALFETCHER_H

#include "app/libs.h"
#include "core/question.h"

namespace laletests { namespace learningstrategies {

class QuestionSignalFetcher : public QObject
{
    Q_OBJECT

protected:
    QList<lale::core::Question> questions;

public:
    explicit QuestionSignalFetcher(QObject*, const char *, QObject *parent = 0);
    virtual ~QuestionSignalFetcher();
    
    QList<lale::core::Question> getQuestions() const;

signals:
    
public slots:
    void fetchQuestionSignal(lale::core::Question);
};

}}

#endif // QUESTIONSIGNALFETCHER_H
