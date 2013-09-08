#ifndef QUESTIONREADERTEST_H
#define QUESTIONREADERTEST_H

#include <QObject>

namespace laletests { namespace core {

class QuestionReaderTest : public QObject
{
    Q_OBJECT

public:
    explicit QuestionReaderTest(QObject *parent = 0);
    virtual ~QuestionReaderTest();

private slots:
    void testFetchingQuestions();
};

}}

#endif // QUESTIONREADERTEST_H
