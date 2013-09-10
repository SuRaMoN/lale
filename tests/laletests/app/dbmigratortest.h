#ifndef LALETESTS_CORE_DBMIGRATORTEST_H
#define LALETESTS_CORE_DBMIGRATORTEST_H

#include "app/lale.h"
#include "testhelpers/testcase.h"

namespace laletests { namespace core {

class DbMigratorTest : public laletests::testhelpers::TestCase
{
    Q_OBJECT

public:
    explicit DbMigratorTest(QObject *parent = 0);
    virtual ~DbMigratorTest();

private slots:
    void testDbMigration();
    void testNoDoubleMigrations();
    void init();
    void cleanup();
};

}}

#endif // LALETESTS_CORE_DBMIGRATORTEST_H
