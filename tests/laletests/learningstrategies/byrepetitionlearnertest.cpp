#include "byrepetitionlearnertest.h"

#include "app/libs.h"
#include "app/dbmigrator.h"
#include "learningstrategies/byrepetitionlearner.h"
#include "learningstrategies/questionsignalfetcher.h"

using namespace laletests::learningstrategies;
using namespace lale::core;
using namespace lale::app;
using namespace lale::learningstrategies;

ByRepetitionLearnerTest::ByRepetitionLearnerTest(QObject *parent) : TestCase(parent)
{
}

ByRepetitionLearnerTest::~ByRepetitionLearnerTest()
{
}

void ByRepetitionLearnerTest::init()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "SimpleLearnerTest");
    db.setDatabaseName(":memory:");
    db.open();
    DbMigrator(db).migrate(QDir(":/dbmigrations").entryInfoList());
}

void ByRepetitionLearnerTest::cleanup()
{
    QSqlDatabase::database("SimpleLearnerTest").close();
    QSqlDatabase::removeDatabase("SimpleLearnerTest");
}

void ByRepetitionLearnerTest::testGivesUniformlyChoosenRandomQuestionsAtStart()
{
    QList<Question> questions;
    questions << Question("question1", "answer1") << Question("question2", "answer2");

    QPointer<ScoreRepository> scoreRepo(new ScoreRepository(QSqlDatabase::database("SimpleLearnerTest")));
    ByRepetitionLearner learner(questions, scoreRepo, RandomGenerator());
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

void ByRepetitionLearnerTest::testWrongAnswersArePooled()
{
    QList<Question> questions;
    for(int i = 0; i < 100; ++i) {
        questions << Question(QString::number(i), "answer1");
    }

    QPointer<ScoreRepository> scoreRepo(new ScoreRepository(QSqlDatabase::database("SimpleLearnerTest")));
    ByRepetitionLearner learner(questions, scoreRepo, RandomGenerator());
    QuestionSignalFetcher sentQuestions(&learner, SIGNAL(newQuestion(lale::core::Question)));

    // provide 7 wrong answers
    for(unsigned int i = 0; i < learner.getRepeatPoolMaxScoreSum(); ++i) {
        learner.wrongAnswerGiven(questions[i]);
    }

    // pool is full, no new questions should be given until answer correctly multiple times
    for(int i = 0; i < 50; i += 1) {
        learner.provideNewQuestion();
        int questionNum = sentQuestions.getQuestions().last().getQuestion().toInt();
        if(questionNum >= learner.getRepeatPoolMaxScoreSum()) {
            QFAIL("Wrong questions are not pooled");
        }
    }

    for(unsigned int i = 0; i < learner.getNumRightAnswersToRemoveFromRepeatPool(); ++i) {
        // in learning pool, no score update!
        learner.rightAnswerGiven(questions[0]);
        QCOMPARE(scoreRepo->getScoreFor(questions[0]), 1.);
    }

    // 3 times answered correctly, yeah! no longer in pool
    learner.rightAnswerGiven(questions[0]);
    QCOMPARE(scoreRepo->getScoreFor(questions[0]), 0.5);

    learner.rightAnswerGiven(questions[0]);
    QCOMPARE(scoreRepo->getScoreFor(questions[0]), 0.25);
}
