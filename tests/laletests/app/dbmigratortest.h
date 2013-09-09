#ifndef LALETESTS_CORE_DBMIGRATORTEST_H
#define LALETESTS_CORE_DBMIGRATORTEST_H

#include <QObject>
#include <QSqlDatabase>
#include <QTemporaryFile>

namespace laletests { namespace core {

class DbMigratorTest : public QObject
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
