#include "statisticscalculatortest.h"

#include "app/libs.h"
#include "core/statisticscalculator.h"

using namespace laletests::core;
using namespace lale::core;

StatisticsCalculatorTest::StatisticsCalculatorTest(QObject *parent) : TestCase(parent)
{
}

StatisticsCalculatorTest::~StatisticsCalculatorTest()
{
}

void StatisticsCalculatorTest::init()
{
    createNewDatabase("ScoreRepositoryTest");
}

void StatisticsCalculatorTest::cleanup()
{
    QSqlDatabase::removeDatabase("ScoreRepositoryTest");
}

void StatisticsCalculatorTest::testStatistics()
{
    QSqlDatabase db = QSqlDatabase::database("ScoreRepositoryTest");
    QPointer<ScoreRepository> scoreRepo(new ScoreRepository(db));

    QList<Question> questions;
    questions << Question("question1", "answer1") << Question("question2", "answer2");
    questions << Question("question3", "answer3") << Question("question4", "answer4");

    StatisticsCalculator calculator(scoreRepo, questions);

    QCOMPARE(calculator.getStatistics().questionsNotYetLearnedCount, 4);

    calculator.scoreUpdatedForQuestion(questions[0], 1, 0.5);
    QCOMPARE(calculator.getStatistics().questionsNotYetLearnedCount, 3);

    calculator.scoreUpdatedForQuestion(questions[0], 0.5, 0.25);
    QCOMPARE(calculator.getStatistics().questionsNotYetLearnedCount, 3);

    calculator.scoreUpdatedForQuestion(questions[1], 1, 0.5);
    QCOMPARE(calculator.getStatistics().questionsNotYetLearnedCount, 2);

    calculator.scoreUpdatedForQuestion(questions[0], 0.25, 1);
    QCOMPARE(calculator.getStatistics().questionsNotYetLearnedCount, 3);
}
