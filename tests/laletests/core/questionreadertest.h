#ifndef LALETESTS_CORE_QUESTIONREADERTEST_H
#define LALETESTS_CORE_QUESTIONREADERTEST_H

#include "app/lale.h"
#include "testhelpers/testcase.h"

namespace laletests { namespace core {

class QuestionReaderTest : public laletests::testhelpers::TestCase
{
    Q_OBJECT

public:
    explicit QuestionReaderTest(QObject *parent = 0);
    virtual ~QuestionReaderTest();

private slots:
    void testFetchingQuestions();
};

}}

#endif // LALETESTS_CORE_QUESTIONREADERTEST_H
