#include "simpleteachertest.h"

#include <cmath>
#include <QSqlQuery>
#include <QDir>
#include "app/dbmigrator.h"
#include "learningstrategies/simpleteacher.h"
#include "learningstrategies/questionsignalfetcher.h"

using namespace laletests::learningstrategies;
using namespace lale::core;
using namespace lale::app;
using namespace lale::learningstrategies;

SimpleTeacherTest::SimpleTeacherTest(QObject *parent) : TestCase(parent)
{
}

SimpleTeacherTest::~SimpleTeacherTest()
{
}

void SimpleTeacherTest::init()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "SimpleTeacherTest");
    db.setDatabaseName(":memory:");
    db.open();
    DbMigrator(db).migrate(QDir(":/dbmigrations").entryInfoList());
}

void SimpleTeacherTest::cleanup()
{
    QSqlDatabase::database("SimpleTeacherTest").close();
    QSqlDatabase::removeDatabase("SimpleTeacherTest");
}

void SimpleTeacherTest::testGivesUniformlyChoosenRandomQuestionsAtStart()
{
    QList<Question> questions;
    questions << Question("question1", "answer1") << Question("question2", "answer2");

    QPointer<ScoreRepository> scoreRepo(new ScoreRepository(QSqlDatabase::database("SimpleTeacherTest")));
    SimpleTeacher teacher(questions, scoreRepo);
    QuestionSignalFetcher sentQuestions(&teacher, SIGNAL(newQuestion(lale::core::Question)));

    int question1GivenCount = 0;
    for(int i = 0; i < 1000; i += 1) {
        teacher.provideNewQuestion();
        if(sentQuestions.getQuestions().last().getQuestion() == "question1") {
            question1GivenCount += 1;
        }
    }

    QVERIFY(abs(question1GivenCount - 500) < 50);
}

void SimpleTeacherTest::testCorrectAnswersAreGivenLessFrequently()
{
    QList<Question> questions;
    questions << Question("question1", "answer1") << Question("question2", "answer2");

    QPointer<ScoreRepository> scoreRepo(new ScoreRepository(QSqlDatabase::database("SimpleTeacherTest")));
    SimpleTeacher teacher(questions, scoreRepo);
    QuestionSignalFetcher sentQuestions(&teacher, SIGNAL(newQuestion(lale::core::Question)));

    for(int i = 0; i < 5; i+= 1) {
        teacher.rightAnswerGiven(questions[0]);
    }

    QCOMPARE(scoreRepo->getScoreFor(questions[0]), 1 / std::pow(2, 5));
    QCOMPARE(scoreRepo->getScoreFor(questions[1]), 1.);

    int question1GivenCount = 0;
    for(int i = 0; i < 1000; i += 1) {
        teacher.provideNewQuestion();
        if(sentQuestions.getQuestions().last().getQuestion() == "question1") {
            question1GivenCount += 1;
        }
    }

    double question1Score = 1 / std::pow(2, 5);
    int expectedQuestion1Count = 1000 * question1Score / (1 + question1Score);

    QVERIFY(abs(question1GivenCount - expectedQuestion1Count) < 50);
}
