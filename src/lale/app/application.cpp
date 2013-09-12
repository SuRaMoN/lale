#include "application.h"

#include "app/libs.h"
#include "gui/mainwindow.h"
#include "core/questionreader.h"
#include "learningstrategies/naivelearner.h"
#include "learningstrategies/simplelearner.h"
#include "dbmigrator.h"

using namespace lale;
using namespace lale::gui;
using namespace lale::core;
using namespace lale::app;
using namespace lale::learningstrategies;

Application::Application(int&argc, char**&argv) :
    QApplication(argc, argv),
    db(QSqlDatabase::addDatabase("QSQLITE"))
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

void Application::initDb()
{
    db.setDatabaseName("lale.db");
    db.open();
}

void Application::performMigrations()
{
    DbMigrator(db).migrate(QDir(":/dbmigrations").entryInfoList());
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

    parseAllConfigs();
    initDb();
    performMigrations();
    readQuestionFile();

    QPointer<ScoreRepository> scoreRepo = new ScoreRepository(db);
    QPointer<Learner> learner = new SimpleLearner(questions, scoreRepo);

    MainWindow mainWindow;
    connect(&mainWindow, SIGNAL(questionChangeRequest()), learner, SLOT(provideNewQuestion()));
    connect(&mainWindow, SIGNAL(wrongAnswerGiven(lale::core::Question)), learner, SLOT(wrongAnswerGiven(lale::core::Question)));
    connect(&mainWindow, SIGNAL(rightAnswerGiven(lale::core::Question)), learner, SLOT(rightAnswerGiven(lale::core::Question)));
    connect(learner, SIGNAL(newQuestion(lale::core::Question)), &mainWindow, SLOT(changeQuestion(lale::core::Question)));

    learner->provideNewQuestion();

    mainWindow.show();
    return QApplication::exec();
}

Application::~Application()
{
}

