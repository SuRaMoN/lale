#ifndef LALETESTS_CORE_SCOREREPOSITORYTEST_H
#define LALETESTS_CORE_SCOREREPOSITORYTEST_H

#include "app/lale.h"
#include "testhelpers/testcase.h"

namespace laletests { namespace core {

class ScoreRepositoryTest : public laletests::testhelpers::TestCase
{
    Q_OBJECT

public:
    explicit ScoreRepositoryTest(QObject *parent = 0);
    virtual ~ScoreRepositoryTest();

private slots:
    void testDefaultScoreIsOne();
    void testUpdateAndRetrieveScore();
    void init();
    void cleanup();
};

}}

#endif // LALETESTS_CORE_SCOREREPOSITORYTEST_H
