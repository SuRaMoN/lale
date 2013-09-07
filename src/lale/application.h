#ifndef LALE_APPLICATION_H
#define LALE_APPLICATION_H

#include <QApplication>
#include <QFile>
#include "core/question.h"

namespace lale {

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
    void newQuestion(core::Question);
    
public slots:
    void provideNewQuestion();
    
};

}

#endif // LALE_APPLICATION_H
