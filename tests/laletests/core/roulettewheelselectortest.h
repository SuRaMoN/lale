#ifndef LALETESTS_CORE_ROULETTEWHEELSELECTORTEST_H
#define LALETESTS_CORE_ROULETTEWHEELSELECTORTEST_H

#include "app/libs.h"
#include "testhelpers/testcase.h"

namespace laletests { namespace core {

class RouletteWheelSelectorTest : public laletests::testhelpers::TestCase
{
    Q_OBJECT

public:
    explicit RouletteWheelSelectorTest(QObject *parent = 0);
    virtual ~RouletteWheelSelectorTest();

private slots:
    void testSimpleRandomPicks();
    void testFrequency();
};

}}

#endif // LALETESTS_CORE_ROULETTEWHEELSELECTORTEST_H
