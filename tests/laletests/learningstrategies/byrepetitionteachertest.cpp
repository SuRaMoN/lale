#include "byrepetitionteachertest.h"

#include <QDir>
#include "app/dbmigrator.h"
#include "learningstrategies/byrepetitionteacher.h"
#include "learningstrategies/questionsignalfetcher.h"

using namespace laletests::learningstrategies;
using namespace lale::core;
using namespace lale::app;
using namespace lale::learningstrategies;

ByRepetitionTeacherTest::ByRepetitionTeacherTest(QObject *parent) : TestCase(parent)
{
}

ByRepetitionTeacherTest::~ByRepetitionTeacherTest()
{
}

void ByRepetitionTeacherTest::init()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "SimpleTeacherTest");
    db.setDatabaseName(":memory:");
    db.open();
    DbMigrator(db).migrate(QDir(":/dbmigrations").entryInfoList());
}

void ByRepetitionTeacherTest::cleanup()
{
    QSqlDatabase::database("SimpleTeacherTest").close();
    QSqlDatabase::removeDatabase("SimpleTeacherTest");
}

void ByRepetitionTeacherTest::testGivesUniformlyChoosenRandomQuestionsAtStart()
{
    QList<Question> questions;
    questions << Question("question1", "answer1") << Question("question2", "answer2");
    questions << Question("question3", "answer3") << Question("question4", "answer4");
    questions << Question("question5", "answer5") << Question("question6", "answer6");

    QPointer<ScoreRepository> scoreRepo(new ScoreRepository(QSqlDatabase::database("SimpleTeacherTest")));
    ByRepetitionTeacher teacher(questions, scoreRepo, RandomGenerator());
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

void ByRepetitionTeacherTest::testDontGiveTheSameQuestionTwoTimesInARow()
{
    QList<Question> questions;
    questions << Question("question1", "answer1") << Question("question2", "answer2");
    questions << Question("question3", "answer3") << Question("question4", "answer4");
    questions << Question("question5", "answer5") << Question("question6", "answer6");

    QPointer<ScoreRepository> scoreRepo(new ScoreRepository(QSqlDatabase::database("SimpleTeacherTest")));
    ByRepetitionTeacher teacher(questions, scoreRepo, RandomGenerator());
    QuestionSignalFetcher sentQuestions(&teacher, SIGNAL(newQuestion(lale::core::Question)));

    Question previousQuestion("", "");
    for(int i = 0; i < 1000; i += 1) {
        teacher.provideNewQuestion();
        if(previousQuestion == sentQuestions.getQuestions().last()) {
            QFAIL("Same question is given twice in a row");
        }
        previousQuestion = sentQuestions.getQuestions().last();
    }

}

void ByRepetitionTeacherTest::testWrongAnswersArePooled()
{
    QList<Question> questions;
    for(int i = 0; i < 100; ++i) {
        questions << Question(QString::number(i), "answer1");
    }

    QPointer<ScoreRepository> scoreRepo(new ScoreRepository(QSqlDatabase::database("SimpleTeacherTest")));
    ByRepetitionTeacher teacher(questions, scoreRepo, RandomGenerator());
    QuestionSignalFetcher sentQuestions(&teacher, SIGNAL(newQuestion(lale::core::Question)));

    // provide 7 wrong answers
    for(unsigned int i = 0; i < teacher.getRepeatPoolMaxScoreSum(); ++i) {
        teacher.wrongAnswerGiven(questions[i]);
    }

    // pool is full, no new questions should be given until answer correctly multiple times
    for(int i = 0; i < 50; i += 1) {
        teacher.provideNewQuestion();
        unsigned int questionNum = sentQuestions.getQuestions().last().getQuestion().toInt();
        if(questionNum >= teacher.getRepeatPoolMaxScoreSum()) {
            QFAIL("Wrong questions are not pooled");
        }
    }

    for(unsigned int i = 0; i < teacher.getNumRightAnswersToRemoveFromRepeatPool(); ++i) {
        // in learning pool, no score update!
        teacher.rightAnswerGiven(questions[0]);
        QCOMPARE(scoreRepo->getScoreFor(questions[0]), 1.);
    }

    // 3 times answered correctly, yeah! no longer in pool
    teacher.rightAnswerGiven(questions[0]);
    QCOMPARE(scoreRepo->getScoreFor(questions[0]), 0.5);

    teacher.rightAnswerGiven(questions[0]);
    QCOMPARE(scoreRepo->getScoreFor(questions[0]), 0.25);
}
