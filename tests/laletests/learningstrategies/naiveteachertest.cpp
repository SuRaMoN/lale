#include "naiveteachertest.h"

#include "app/libs.h"
#include "learningstrategies/naiveteacher.h"
#include "learningstrategies/questionsignalfetcher.h"

using namespace laletests::learningstrategies;
using namespace lale::core;
using namespace lale::learningstrategies;

NaiveTeacherTest::NaiveTeacherTest(QObject *parent) : TestCase(parent)
{
}

NaiveTeacherTest::~NaiveTeacherTest()
{
}

void NaiveTeacherTest::testGivesRandomQuestions()
{
    QList<Question> questions;
    questions << Question("question1", "answer1") << Question("question2", "answer2");

    NaiveTeacher teacher(questions);
    QuestionSignalFetcher sentQuestions(&teacher, SIGNAL(newQuestion(lale::core::Question)));

    for(int i = 0; i < 50; i += 1) {
        teacher.provideNewQuestion();
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
