#ifndef LALE_CORE_QUESTIONREADER_H
#define LALE_CORE_QUESTIONREADER_H

#include "app/libs.h"
#include "question.h"

namespace lale { namespace core {

class QuestionReader : public QObject
{
    Q_OBJECT

public:
    explicit QuestionReader(QObject *parent = 0);
    QList<Question> fetchAllQuestions(QIODevice &file);
    virtual ~QuestionReader();    
};

}}

#endif // LALE_CORE_QUESTIONREADER_H
