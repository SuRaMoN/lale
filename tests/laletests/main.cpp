#include <QTest>
#include "core/questionreadertest.h"
#include "learningstrategies/naivelearnertest.h"

using namespace QTest;
using namespace laletests::core;
using namespace laletests::learningstrategies;

int main(int argc, char *argv[])
{
    int result = 0;

    result |= QTest::qExec(new QuestionReaderTest(), argc, argv);
    result |= QTest::qExec(new NaiveLearnerTest(), argc, argv);

    return result;
}
