#include "questionsignalfetcher.h"

using namespace laletests::learningstrategies;
using namespace lale::core;

QuestionSignalFetcher::QuestionSignalFetcher(QObject * source, const char * signal, QObject *parent) : QObject(parent)
{
    connect(source, signal, SLOT(fetchQuestionSignal(lale::core::Question)));
}

QuestionSignalFetcher::~QuestionSignalFetcher()
{
}

void QuestionSignalFetcher::fetchQuestionSignal(Question question)
{
    questions.append(question);
}

QList<Question> QuestionSignalFetcher::getQuestions() const
{
    return questions;
}
