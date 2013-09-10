#include "questionreadertest.h"

#include "app/lale.h"
#include "core/questionreader.h"

using namespace laletests::core;
using namespace lale::core;

QuestionReaderTest::QuestionReaderTest(QObject *parent) : TestCase(parent)
{
}

QuestionReaderTest::~QuestionReaderTest()
{
}

void QuestionReaderTest::testFetchingQuestions()
{
    QuestionReader questionReader;
    QFile questionFile(":core/testdata/vocabularium.csv");
    QList<Question> questions = questionReader.fetchAllQuestions(questionFile);

    QCOMPARE(questions.size(), 5);
    QCOMPARE(questions.first().getQuestion(), QString("drukletter"));
    QCOMPARE(questions.last().getAnswer().length(), 14);
}
