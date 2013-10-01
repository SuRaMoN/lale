#include "scorerepository.h"

#include <QSqlError>
#include <QSqlQuery>

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
    double oldScore = getScoreFor(question);
    QSqlQuery query(db);
    query.prepare("REPLACE INTO score (question, score) VALUES (:question, :score)");
    query.bindValue(":question", question.getQuestion());
    query.bindValue(":score", score);
    if(!query.exec()) {
        throw query.lastError();
    }
    emit scoreUpdatedForQuestion(question, oldScore, score);
}

void ScoreRepository::multiplyScoreWith(Question question, double factor)
{
    double oldScore = getScoreFor(question);
    updateScoreFor(question, factor * oldScore);
}


