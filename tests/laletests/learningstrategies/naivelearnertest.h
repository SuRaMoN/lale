#ifndef LALETESTS_LEARNINGSTRATEGIES_NAIVELEARNERTEST_H
#define LALETESTS_LEARNINGSTRATEGIES_NAIVELEARNERTEST_H

#include "app/lale.h"
#include "testhelpers/testcase.h"

namespace laletests { namespace learningstrategies {

class NaiveLearnerTest : public laletests::testhelpers::TestCase
{
    Q_OBJECT

public:
    explicit NaiveLearnerTest(QObject *parent = 0);
    virtual ~NaiveLearnerTest();

private slots:
    void testGivesRandomQuestions();
};

}}

#endif // LALETESTS_LEARNINGSTRATEGIES_NAIVELEARNERTEST_H
