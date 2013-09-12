#ifndef LALE_CORE_SCOREREPOSITORY_H
#define LALE_CORE_SCOREREPOSITORY_H

#include "app/libs.h"
#include "question.h"

namespace lale { namespace core {

class ScoreRepository : public QObject
{
    Q_OBJECT

protected:
    QSqlDatabase db;

public:
    explicit ScoreRepository(QSqlDatabase, QObject *parent = 0);
    virtual ~ScoreRepository();
    double getScoreFor(Question);
    void updateScoreFor(Question, double);
    void multiplyScoreWith(Question, double);
    
signals:
    
public slots:
    
};

}}

#endif // LALE_CORE_SCOREREPOSITORY_H
