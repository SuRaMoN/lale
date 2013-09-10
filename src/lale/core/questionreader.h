#ifndef QUESTIONREADER_H
#define QUESTIONREADER_H

#include "app/lale.h"
#include "question.h"

namespace lale { namespace core {

class QuestionReader : public QObject
{
    Q_OBJECT

public:
    explicit QuestionReader(QObject *parent = 0);
    QList<Question> fetchAllQuestions(QIODevice &file);
    virtual ~QuestionReader();

signals:
    
public slots:
    
};

}}

#endif // QUESTIONREADER_H
