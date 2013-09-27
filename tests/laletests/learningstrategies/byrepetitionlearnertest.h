#ifndef LALETESTS_LEARNINGSTRATEGIES_BYREPETITIONLEARNERTEST_H
#define LALETESTS_LEARNINGSTRATEGIES_BYREPETITIONLEARNERTEST_H

#include "app/libs.h"
#include "testhelpers/testcase.h"

namespace laletests { namespace learningstrategies {

class ByRepetitionLearnerTest : public laletests::testhelpers::TestCase
{
    Q_OBJECT

public:
    explicit ByRepetitionLearnerTest(QObject *parent = 0);
    virtual ~ByRepetitionLearnerTest();

private slots:
    void testGivesUniformlyChoosenRandomQuestionsAtStart();
    void testDontGiveTheSameQuestionTwoTimesInARow();
    void testWrongAnswersArePooled();
    void init();
    void cleanup();
};

}}

#endif // LALETESTS_LEARNINGSTRATEGIES_BYREPETITIONLEARNERTEST_H
