
#include "app/libs.h"

#include <QTest>

#include "app/dbmigratortest.h"
#include "core/scorerepositorytest.h"
#include "core/questionreadertest.h"
#include "core/roulettewheelselectortest.h"
#include "core/randomgeneratortest.h"
#include "learningstrategies/naiveteachertest.h"
#include "learningstrategies/simpleteachertest.h"
#include "learningstrategies/byrepetitionteachertest.h"

using namespace QTest;
using namespace std;
using namespace laletests::core;
using namespace laletests::learningstrategies;

int main(int argc, char *argv[])
{
    int result = 0;

    QPointer<QuestionReaderTest> questionReaderTest = new QuestionReaderTest();
    result |= QTest::qExec(questionReaderTest, argc, argv);

    QPointer<NaiveTeacherTest> naiveTeacherTest = new NaiveTeacherTest();
    result |= QTest::qExec(naiveTeacherTest, argc, argv);

    QPointer<DbMigratorTest> dbMigratorTest = new DbMigratorTest();
    result |= QTest::qExec(dbMigratorTest, argc, argv);

    QPointer<ScoreRepositoryTest> scoreRepositoryTest = new ScoreRepositoryTest();
    result |= QTest::qExec(scoreRepositoryTest, argc, argv);

    QPointer<RouletteWheelSelectorTest> rouletteWheelSelectorTest = new RouletteWheelSelectorTest();
    result |= QTest::qExec(rouletteWheelSelectorTest, argc, argv);

    QPointer<SimpleTeacherTest> simpleTeacherTest = new SimpleTeacherTest();
    result |= QTest::qExec(simpleTeacherTest, argc, argv);

    QPointer<RandomGeneratorTest> randomGeneratorTest = new RandomGeneratorTest();
    result |= QTest::qExec(randomGeneratorTest, argc, argv);

    QPointer<ByRepetitionTeacherTest> byRepetitionTeacherTest = new ByRepetitionTeacherTest();
    result |= QTest::qExec(byRepetitionTeacherTest, argc, argv);

    if(result == 0) {
        cout << endl << "Tests ran successfully" << endl;
    } else {
        cout << endl << "Failure in tests" << endl;
    }

    return result;
}
