#ifndef LALE_APP_DBMIGRATOR_H
#define LALE_APP_DBMIGRATOR_H

#include "libs.h"

namespace lale { namespace app {

class DbMigrator : public QObject
{
    Q_OBJECT
protected:
    QSqlDatabase db;
    bool markMigrationAsDone(QFileInfo migration);

public:
    explicit DbMigrator(QSqlDatabase, QObject *parent = 0);
    virtual ~DbMigrator();
    void migrate(QFileInfoList migrations);
    bool hasBeenMigratedTo(QFileInfo migration);
    
signals:
    
public slots:
    
};

}}

#endif // LALE_APP_DBMIGRATOR_H
