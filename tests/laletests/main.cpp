#include <QTest>
#include "core/questionreadertest.h"

using namespace QTest;
using namespace laletests::core;

int main(int argc, char *argv[])
{
    return QTest::qExec(new QuestionReaderTest(), argc, argv);
}
