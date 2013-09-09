
#include <QTest>
#include "core/questionreadertest.h"
#include "learningstrategies/naivelearnertest.h"
#include "app/dbmigratortest.h"

using namespace QTest;
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

    return result;
}
