#ifndef LALETESTS_LEARNINGSTRATEGIES_NAIVETEACHERTEST_H
#define LALETESTS_LEARNINGSTRATEGIES_NAIVETEACHERTEST_H

#include "app/libs.h"
#include "testhelpers/testcase.h"

namespace laletests { namespace learningstrategies {

class NaiveTeacherTest : public laletests::testhelpers::TestCase
{
    Q_OBJECT

public:
    explicit NaiveTeacherTest(QObject *parent = 0);
    virtual ~NaiveTeacherTest();

private slots:
    void testGivesRandomQuestions();
};

}}

#endif // LALETESTS_LEARNINGSTRATEGIES_NAIVETEACHERTEST_H
