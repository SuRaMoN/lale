#include "questionreadertest.h"

#include <QDebug>
#include <QFile>
#include <QTest>
#include <QTextCodec>

#include "core/questionreader.h"

using namespace laletests::core;
using namespace lale::core;

QuestionReaderTest::QuestionReaderTest(QObject *parent) :
    QObject(parent)
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

    QCOMPARE(5, questions.size());
    QCOMPARE(QString("drukletter"), questions.first().getQuestion());
    QCOMPARE(14, questions.last().getAnswer().length());
}
