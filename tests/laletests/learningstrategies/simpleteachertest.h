#ifndef LALETESTS_LEARNINGSTRATEGIES_SIMPLETEACHERTEST_H
#define LALETESTS_LEARNINGSTRATEGIES_SIMPLETEACHERTEST_H

#include "app/libs.h"
#include "testhelpers/testcase.h"

namespace laletests { namespace learningstrategies {

class SimpleTeacherTest : public laletests::testhelpers::TestCase
{
    Q_OBJECT

public:
    explicit SimpleTeacherTest(QObject *parent = 0);
    virtual ~SimpleTeacherTest();

private slots:
    void testGivesUniformlyChoosenRandomQuestionsAtStart();
    void testCorrectAnswersAreGivenLessFrequently();
    void init();
    void cleanup();
};

}}

#endif // LALETESTS_LEARNINGSTRATEGIES_SIMPLETEACHERTEST_H
