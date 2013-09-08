#ifndef LALE_APP_APPLICATION_H
#define LALE_APP_APPLICATION_H

#include <QApplication>
#include <QFile>
#include "core/question.h"

namespace lale { namespace app {

class Application : public QApplication
{
    Q_OBJECT

protected:
    QList<core::Question> questions;
    QString questionsFilePath;

    void setQuestionsFilePath(const QString &questionsFilePath);
    void parseAllConfigs();
    void parseConfig(const QString &configFile);
    void readQuestionFile();

public:
    explicit Application(int&, char**&);
    int exec();
    virtual ~Application();
    
signals:
    
public slots:
    
};

}}

#endif // LALE_APP_APPLICATION_H
