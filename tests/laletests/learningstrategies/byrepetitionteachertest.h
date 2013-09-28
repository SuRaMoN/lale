#ifndef LALETESTS_LEARNINGSTRATEGIES_BYREPETITIONTEACHERTEST_H
#define LALETESTS_LEARNINGSTRATEGIES_BYREPETITIONTEACHERTEST_H

#include "app/libs.h"
#include "testhelpers/testcase.h"

namespace laletests { namespace learningstrategies {

class ByRepetitionTeacherTest : public laletests::testhelpers::TestCase
{
    Q_OBJECT

public:
    explicit ByRepetitionTeacherTest(QObject *parent = 0);
    virtual ~ByRepetitionTeacherTest();

private slots:
    void testGivesUniformlyChoosenRandomQuestionsAtStart();
    void testDontGiveTheSameQuestionTwoTimesInARow();
    void testWrongAnswersArePooled();
    void init();
    void cleanup();
};

}}

#endif // LALETESTS_LEARNINGSTRATEGIES_BYREPETITIONTEACHERTEST_H
