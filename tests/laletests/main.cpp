
#include "app/libs.h"

#include <QTest>

#include "app/dbmigratortest.h"
#include "core/scorerepositorytest.h"
#include "core/questionreadertest.h"
#include "core/roulettewheelselectortest.h"
#include "learningstrategies/naivelearnertest.h"

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

    if(result == 0) {
        cout << endl << "Tests ran successfully" << endl;
    } else {
        cout << endl << "Failure in tests" << endl;
    }

    return result;
}
