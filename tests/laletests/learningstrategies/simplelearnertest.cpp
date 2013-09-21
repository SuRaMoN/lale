#include "simplelearnertest.h"

#include <math.h>
#include "app/libs.h"
#include "app/dbmigrator.h"
#include "learningstrategies/simplelearner.h"
#include "learningstrategies/questionsignalfetcher.h"

using namespace laletests::learningstrategies;
using namespace lale::core;
using namespace lale::app;
using namespace lale::learningstrategies;

SimpleLearnerTest::SimpleLearnerTest(QObject *parent) : TestCase(parent)
{
}

SimpleLearnerTest::~SimpleLearnerTest()
{
}

void SimpleLearnerTest::init()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "SimpleLearnerTest");
    db.setDatabaseName(":memory:");
    db.open();
    DbMigrator(db).migrate(QDir(":/dbmigrations").entryInfoList());
}

void SimpleLearnerTest::cleanup()
{
    QSqlDatabase::database("SimpleLearnerTest").close();
    QSqlDatabase::removeDatabase("SimpleLearnerTest");
}

void SimpleLearnerTest::testGivesUniformlyChoosenRandomQuestionsAtStart()
{
    QList<Question> questions;
    questions << Question("question1", "answer1") << Question("question2", "answer2");

    QPointer<ScoreRepository> scoreRepo(new ScoreRepository(QSqlDatabase::database("SimpleLearnerTest")));
    SimpleLearner learner(questions, scoreRepo);
    QuestionSignalFetcher sentQuestions(&learner, SIGNAL(newQuestion(lale::core::Question)));

    int question1GivenCount = 0;
    for(int i = 0; i < 1000; i += 1) {
        learner.provideNewQuestion();
        if(sentQuestions.getQuestions().last().getQuestion() == "question1") {
            question1GivenCount += 1;
        }
    }

    QVERIFY(abs(question1GivenCount - 500) < 50);
}

void SimpleLearnerTest::testCorrectAnswersAreGivenLessFrequently()
{
    QList<Question> questions;
    questions << Question("question1", "answer1") << Question("question2", "answer2");

    QPointer<ScoreRepository> scoreRepo(new ScoreRepository(QSqlDatabase::database("SimpleLearnerTest")));
    SimpleLearner learner(questions, scoreRepo);
    QuestionSignalFetcher sentQuestions(&learner, SIGNAL(newQuestion(lale::core::Question)));

    for(int i = 0; i < 5; i+= 1) {
        learner.rightAnswerGiven(questions[0]);
    }

    QCOMPARE(scoreRepo->getScoreFor(questions[0]), 1 / pow(2, 5));
    QCOMPARE(scoreRepo->getScoreFor(questions[1]), 1.);

    int question1GivenCount = 0;
    for(int i = 0; i < 1000; i += 1) {
        learner.provideNewQuestion();
        if(sentQuestions.getQuestions().last().getQuestion() == "question1") {
            question1GivenCount += 1;
        }
    }

    double question1Score = 1 / pow(2, 5);
    int expectedQuestion1Count = 1000 * question1Score / (1 + question1Score);

    QVERIFY(abs(question1GivenCount - expectedQuestion1Count) < 50);
}
