#ifndef LALETESTS_LEARNINGSTRATEGIES_SIMPLELEARNERTEST_H
#define LALETESTS_LEARNINGSTRATEGIES_SIMPLELEARNERTEST_H

#include "app/libs.h"
#include "testhelpers/testcase.h"

namespace laletests { namespace learningstrategies {

class SimpleLearnerTest : public laletests::testhelpers::TestCase
{
    Q_OBJECT

public:
    explicit SimpleLearnerTest(QObject *parent = 0);
    virtual ~SimpleLearnerTest();

private slots:
    void testGivesUniformlyChoosenRandomQuestionsAtStart();
    void testCorrectAnswersAreGivenLessFrequently();
    void init();
    void cleanup();
};

}}

#endif // LALETESTS_LEARNINGSTRATEGIES_SIMPLELEARNERTEST_H
