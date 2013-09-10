#include "dbmigratortest.h"

#include "app/lale.h"
#include "app/dbmigrator.h"

using namespace laletests::core;
using namespace lale::app;


DbMigratorTest::DbMigratorTest(QObject * parent) : TestCase(parent)
{
}

void DbMigratorTest::init()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "DbMigratorTest");
    db.setDatabaseName(":memory:");
    db.open();
}

void DbMigratorTest::cleanup()
{
    QSqlDatabase::database("DbMigratorTest").close();
    QSqlDatabase::removeDatabase("DbMigratorTest");
}

DbMigratorTest::~DbMigratorTest()
{
}

void DbMigratorTest::testDbMigration()
{
    QSqlDatabase db = QSqlDatabase::database("DbMigratorTest");
    DbMigrator(db).migrate(QDir(":/app/testdata/migrations").entryInfoList());
    QSqlQuery query(db);
    query.prepare("SELECT * FROM migration");
    QVERIFY(query.exec());
}

void DbMigratorTest::testNoDoubleMigrations()
{
    QSqlDatabase db = QSqlDatabase::database("DbMigratorTest");
    DbMigrator(db).migrate(QDir(":/app/testdata/migrations").entryInfoList());
    DbMigrator(db).migrate(QDir(":/app/testdata/migrations").entryInfoList());
    QSqlQuery query(db);
    query.prepare("SELECT * FROM migration");
    query.exec();
    int size = 0;
    while(query.next()) {
        size += 1;
    }
    QCOMPARE(size, 3);
}
