#include "application.h"

#include <QDir>
#include <QSettings>
#include <QTime>
#include <qglobal.h>
#include "gui/mainwindow.h"
#include "core/questionreader.h"

using namespace lale;
using namespace lale::gui;
using namespace lale::core;

Application::Application(int&argc, char**&argv) : QApplication(argc, argv)
{
    qsrand(QTime::currentTime().msec());

    setQuestionsFilePath("questions.csv.dist");
    setQuestionsFilePath("questions.csv");
    setQuestionsFilePath(QDir(applicationDirPath()).filePath("questions.csv.dist"));
    setQuestionsFilePath(QDir(applicationDirPath()).filePath("questions.csv"));
}

void Application::setQuestionsFilePath(const QString &questionsFilePath)
{
    if(QFile(questionsFilePath).exists()) {
        this->questionsFilePath = questionsFilePath;
    }
}

void Application::parseAllConfigs()
{
    parseConfig(QDir(applicationDirPath()).filePath("lale.ini.dist"));
    parseConfig(QDir(applicationDirPath()).filePath("lale.ini"));
    parseConfig("lale.ini.dist");
    parseConfig("lale.ini");
    parseConfig("~/.lale.ini");
}

void Application::parseConfig(const QString & configFilePath)
{
    if(!QFile(configFilePath).exists()) {
        return;
    }
    QSettings config(configFilePath, QSettings::IniFormat);
    QVariant questionsFilePath = config.value("questions_file_path");
    if(questionsFilePath.isValid()) {
        this->questionsFilePath = questionsFilePath.toString();
    }
}

void Application::readQuestionFile()
{
    QFile questionFile(questionsFilePath);
    questions = QuestionReader().fetchAllQuestions(questionFile);
}

int Application::exec()
{
    Application::parseAllConfigs();
    readQuestionFile();

    MainWindow mainWindow;
    connect(&mainWindow, SIGNAL(questionChangeRequest()), this, SLOT(provideNewQuestion()));
    connect(this, SIGNAL(newQuestion(core::Question)), &mainWindow, SLOT(changeQuestion(core::Question)));

    provideNewQuestion();

    mainWindow.show();
    return QApplication::exec();
}

Application::~Application()
{
}

void Application::provideNewQuestion()
{
    Question question = questions[qrand() % questions.length()];
    emit newQuestion(question);
}
