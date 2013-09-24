
#include "app/libs.h"

#include <QTest>

#include "app/dbmigratortest.h"
#include "core/scorerepositorytest.h"
#include "core/questionreadertest.h"
#include "core/roulettewheelselectortest.h"
#include "core/randomgeneratortest.h"
#include "learningstrategies/naivelearnertest.h"
#include "learningstrategies/simplelearnertest.h"
#include "learningstrategies/byrepetitionlearnertest.h"

using namespace QTest;
using namespace std;
using namespace laletests::core;
using namespace laletests::learningstrategies;

int main(int argc, char *argv[])
{
    int result = 0;

    QPointer<QuestionReaderTest> questionReaderTest = new QuestionReaderTest();
    result |= QTest::qExec(questionReaderTest, argc, argv);

    QPointer<NaiveLearnerTest> naiveLearnerTest = new NaiveLearnerTest();
    result |= QTest::qExec(naiveLearnerTest, argc, argv);

    QPointer<DbMigratorTest> dbMigratorTest = new DbMigratorTest();
    result |= QTest::qExec(dbMigratorTest, argc, argv);

    QPointer<ScoreRepositoryTest> scoreRepositoryTest = new ScoreRepositoryTest();
    result |= QTest::qExec(scoreRepositoryTest, argc, argv);

    QPointer<RouletteWheelSelectorTest> rouletteWheelSelectorTest = new RouletteWheelSelectorTest();
    result |= QTest::qExec(rouletteWheelSelectorTest, argc, argv);

    QPointer<SimpleLearnerTest> simpleLearnerTest = new SimpleLearnerTest();
    result |= QTest::qExec(simpleLearnerTest, argc, argv);

    QPointer<RandomGeneratorTest> randomGeneratorTest = new RandomGeneratorTest();
    result |= QTest::qExec(randomGeneratorTest, argc, argv);

    QPointer<ByRepetitionLearnerTest> byRepetitionLearnerTest = new ByRepetitionLearnerTest();
    result |= QTest::qExec(byRepetitionLearnerTest, argc, argv);

    if(result == 0) {
        cout << endl << "Tests ran successfully" << endl;
    } else {
        cout << endl << "Failure in tests" << endl;
    }

    return result;
}
