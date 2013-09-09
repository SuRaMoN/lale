#include "scorerepository.h"

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
}
