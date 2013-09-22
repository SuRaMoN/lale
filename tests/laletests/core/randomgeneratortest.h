#ifndef LALETESTS_CORE_RANDOMGENERATORTEST_H
#define LALETESTS_CORE_RANDOMGENERATORTEST_H

#include "app/libs.h"
#include "testhelpers/testcase.h"

namespace laletests { namespace core {

class RandomGeneratorTest : public laletests::testhelpers::TestCase
{
    Q_OBJECT
public:
    explicit RandomGeneratorTest(QObject *parent = 0);
    virtual ~RandomGeneratorTest();

private slots:
    void testGetRandomDouble();
    void testSeed();
};

}}

#endif // LALETESTS_CORE_RANDOMGENERATORTEST_H
