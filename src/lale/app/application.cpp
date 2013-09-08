#include "application.h"

#include <QDir>
#include <QSettings>
#include <QTime>
#include <QPointer>
#include <qglobal.h>
#include "gui/mainwindow.h"
#include "core/questionreader.h"
#include "learningstrategies/naivelearner.h"

using namespace lale;
using namespace lale::gui;
using namespace lale::core;
using namespace lale::app;
using namespace lale::learningstrategies;

Application::Application(int&argc, char**&argv) : QApplication(argc, argv)
{
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
    qsrand(QTime::currentTime().msec());

    Application::parseAllConfigs();
    readQuestionFile();
    QPointer<Learner> learner = new NaiveLearner(questions);

    MainWindow mainWindow;
    connect(&mainWindow, SIGNAL(questionChangeRequest()), learner, SLOT(provideNewQuestion()));
    connect(learner, SIGNAL(newQuestion(lale::core::Question)), &mainWindow, SLOT(changeQuestion(lale::core::Question)));

    learner->provideNewQuestion();

    mainWindow.show();
    return QApplication::exec();
}

Application::~Application()
{
}

