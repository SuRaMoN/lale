#ifndef LALE_APP_APPLICATION_H
#define LALE_APP_APPLICATION_H

#include "libs.h"
#include "core/question.h"

namespace lale { namespace app {

class Application : public QApplication
{
    Q_OBJECT

protected:
    QList<core::Question> questions;
    QString questionsFilePath;
    QSqlDatabase db;

    void setQuestionsFilePath(const QString &questionsFilePath);
    void parseAllConfigs();
    void initDb();
    void performMigrations();
    void parseConfig(const QString &configFile);
    void readQuestionFile();

public:
    explicit Application(int&, char**&);
    int exec();
    virtual ~Application();
};

}}

#endif // LALE_APP_APPLICATION_H
