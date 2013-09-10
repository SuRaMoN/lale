#include "dbmigrator.h"

#include "app/lale.h"

using namespace lale::app;

DbMigrator::DbMigrator(QSqlDatabase db, QObject *parent) : QObject(parent)
{
    this->db = db;
}

DbMigrator::~DbMigrator()
{
}

void DbMigrator::migrate(QFileInfoList migrations)
{
    foreach(const QFileInfo & migration, migrations) {
        if(hasBeenMigratedTo(migration)) {
            continue;
        }
        QFile migrationFile(migration.filePath());
        migrationFile.open(QIODevice::ReadOnly | QIODevice::Text);
        foreach(const QString & line, QTextStream(&migrationFile).readAll().split("\n")) {
            db.transaction();
            if(line.trimmed() == "") {
                continue;
            }
            QSqlQuery query(db);
            query.prepare(line);
            query.exec();
            db.commit();
        }
        markMigrationAsDone(migration);
    }
}

bool DbMigrator::markMigrationAsDone(QFileInfo migration)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO migration VALUES (:name)");
    query.bindValue(":name", migration.fileName());
    query.exec();
    return query.first();
}

bool DbMigrator::hasBeenMigratedTo(QFileInfo migration)
{
    QSqlQuery query(db);
    query.prepare("SELECT name FROM migration WHERE name = :name");
    query.bindValue(":name", migration.fileName());
    query.exec();
    return query.first();
}
