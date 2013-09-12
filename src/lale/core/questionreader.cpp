#include "questionreader.h"

#include "app/libs.h"

using namespace lale::core;

QuestionReader::QuestionReader(QObject *parent) :
    QObject(parent)
{
}

QList<Question> QuestionReader::fetchAllQuestions(QIODevice &file)
{
    QxtCsvModel csvModel(&file);
    QList<Question> questions;
    int rowCount = csvModel.rowCount();
    for(int i = 0; i < rowCount; i += 1) {
        QString question = QString::fromUtf8(csvModel.data(csvModel.index(i, 1)).toByteArray());
        QString answer = QString::fromUtf8(csvModel.data(csvModel.index(i, 0)).toByteArray());
        questions.append(Question(question, answer));
    }
    return questions;
}

QuestionReader::~QuestionReader()
{
}
