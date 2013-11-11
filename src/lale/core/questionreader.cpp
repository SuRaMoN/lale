#include "questionreader.h"

#include "app/libs.h"
#include "csvtools/csv_reader.hpp"
#include "boost/foreach.hpp"
#include <QTextCodec>

using namespace lale::core;
using namespace csvtools;

QuestionReader::QuestionReader(QObject *parent) :
    QObject(parent)
{
}

QList<Question> QuestionReader::fetchAllQuestions(QIODevice & file)
{
    QList<Question> questions;
    if(! file.isOpen()) {
        file.open(QIODevice::ReadOnly | QIODevice::Text);
    }
    QTextStream fileInputStream(&file);
    fileInputStream.setCodec("UTF-8");
    BOOST_FOREACH(const csv_line & line, csv_reader::new_from_string(fileInputStream.readAll().toStdWString())) {
        questions.append(Question(QString::fromStdWString(line[1]), QString::fromStdWString(line[0])));
    }
    return questions;
}

QuestionReader::~QuestionReader()
{
}
