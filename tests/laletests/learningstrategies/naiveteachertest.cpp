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
    questions << Question("question3", "answer3") << Question("question4", "answer4");
    questions << Question("question5", "answer5") << Question("question6", "answer6");

    NaiveTeacher teacher(questions);
    QuestionSignalFetcher sentQuestions(&teacher, SIGNAL(newQuestion(lale::core::Question)));

    int question1GivenCount = 0;
    for(int i = 0; i < 1000; i += 1) {
        teacher.provideNewQuestion();
        if(sentQuestions.getQuestions().last().getQuestion() == "question1") {
            question1GivenCount += 1;
        }
    }

    QVERIFY(abs(question1GivenCount - 1000 / questions.size()) < 50);
}
