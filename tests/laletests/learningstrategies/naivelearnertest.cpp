#include "naivelearnertest.h"

#include "app/lale.h"
#include "learningstrategies/naivelearner.h"
#include "learningstrategies/questionsignalfetcher.h"

using namespace laletests::learningstrategies;
using namespace lale::core;
using namespace lale::learningstrategies;

NaiveLearnerTest::NaiveLearnerTest(QObject *parent) : TestCase(parent)
{
}

NaiveLearnerTest::~NaiveLearnerTest()
{
}

void NaiveLearnerTest::testGivesRandomQuestions()
{
    QList<Question> questions;
    questions << Question("question1", "answer1") << Question("question2", "answer2");

    NaiveLearner learner(questions);
    QuestionSignalFetcher sentQuestions(&learner, SIGNAL(newQuestion(lale::core::Question)));

    for(int i = 0; i < 50; i += 1) {
        learner.provideNewQuestion();
    }

    bool question1Provided = false, question2Provided = false;
    foreach(Question question, sentQuestions.getQuestions()) {
        if(question.getQuestion() == "question1") {
            question1Provided = true;
        } else if(question.getQuestion() == "question2") {
            question2Provided = true;
        } else {
            QVERIFY(false);
        }
    }
    QCOMPARE(question1Provided, true);
    QCOMPARE(question2Provided, true);
}
