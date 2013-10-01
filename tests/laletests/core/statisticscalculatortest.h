#ifndef LALETESTS_CORE_STATISTICSCALCULATORTEST_H
#define LALETESTS_CORE_STATISTICSCALCULATORTEST_H

#include "app/libs.h"
#include "testhelpers/testcase.h"

namespace laletests { namespace core {

class StatisticsCalculatorTest : public laletests::testhelpers::TestCase
{
    Q_OBJECT

public:
    explicit StatisticsCalculatorTest(QObject *parent = 0);
    virtual ~StatisticsCalculatorTest();

private slots:
    void testStatistics();
    void init();
    void cleanup();
};

}}

#endif // LALETESTS_CORE_STATISTICSCALCULATORTEST_H
