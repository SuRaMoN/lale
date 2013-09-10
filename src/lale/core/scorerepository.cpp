#include "scorerepository.h"

#include "app/lale.h"

using namespace lale::core;

ScoreRepository::ScoreRepository(QSqlDatabase db, QObject *parent) : QObject(parent)
{
    this->db = db;
}

ScoreRepository::~ScoreRepository()
{
}

double ScoreRepository::getScoreFor(Question question)
{
    QSqlQuery query(db);
    query.prepare("SELECT score FROM score WHERE question = :question");
    query.bindValue(":question", question.getQuestion());
    if(!query.exec()) {
        throw query.lastError();
    }
    if(!query.first()) {
        return 1.;
    }
    return query.value(0).toDouble();
}

void ScoreRepository::updateScoreFor(Question question, double score)
{
    QSqlQuery query(db);
    query.prepare("REPLACE INTO score (question, score) VALUES (:question, :score)");
    query.bindValue(":question", question.getQuestion());
    query.bindValue(":score", score);
    if(!query.exec()) {
        throw query.lastError();
    }
}
