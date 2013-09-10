#include "testcase.h"

#include "app/lale.h"
#include "app/dbmigrator.h"

using namespace laletests::testhelpers;
using namespace lale::app;

TestCase::TestCase(QObject *parent) : QObject(parent)
{
}

TestCase::~TestCase()
{
}


void TestCase::createNewDatabase(const QString & name)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", name);
    db.setDatabaseName(":memory:");
    db.open();
    DbMigrator(db).migrate(QDir(":/dbmigrations").entryInfoList());
}
