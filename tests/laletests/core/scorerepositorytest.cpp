#include "scorerepositorytest.h"

#include "app/lale.h"
#include "core/scorerepository.h"

using namespace laletests::core;
using namespace lale::core;

ScoreRepositoryTest::ScoreRepositoryTest(QObject *parent) : TestCase(parent)
{
}


ScoreRepositoryTest::~ScoreRepositoryTest()
{
}

void ScoreRepositoryTest::testDefaultScoreIsOne()
{
    QSqlDatabase db = QSqlDatabase::database("ScoreRepositoryTest");
    ScoreRepository scoreRepo(db);
    Question question("question", "answer");
    double score = scoreRepo.getScoreFor(question);
    QCOMPARE(score, 1.);
}

void ScoreRepositoryTest::testUpdateAndRetrieveScore()
{
    QSqlDatabase db = QSqlDatabase::database("ScoreRepositoryTest");
    ScoreRepository scoreRepo(db);
    Question question("question", "answer");
    scoreRepo.updateScoreFor(question, 10);
    double score = scoreRepo.getScoreFor(question);
    QCOMPARE(score, 10.);
}

void ScoreRepositoryTest::init()
{
    createNewDatabase("ScoreRepositoryTest");
}

void ScoreRepositoryTest::cleanup()
{
    QSqlDatabase::removeDatabase("ScoreRepositoryTest");
}
