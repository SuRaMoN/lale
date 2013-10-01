
#include "application.h"

#include <QSettings>
#include <QDir>
#include "gui/mainwindow.h"
#include "core/questionreader.h"
#include "core/statisticscalculator.h"
#include "learningstrategies/naiveteacher.h"
#include "learningstrategies/simpleteacher.h"
#include "learningstrategies/byrepetitionteacher.h"
#include "gui/statisticswindow.h"
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
    parseAllConfigs();
    initDb();
    performMigrations();
    readQuestionFile();

    QPointer<ScoreRepository> scoreRepo = new ScoreRepository(db);
    RandomGenerator randomGenerator;
    //QPointer<Teacher> teacher = new NaiveTeacher(questions);
    //QPointer<Teacher> teacher = new SimpleTeacher(questions, scoreRepo);
    QPointer<Teacher> teacher = new ByRepetitionTeacher(questions, scoreRepo, randomGenerator);
    StatisticsCalculator statisticsCalculator(scoreRepo, questions);

    MainWindow mainWindow;
    connect(&mainWindow, SIGNAL(questionChangeRequest()), teacher, SLOT(provideNewQuestion()));
    connect(&mainWindow, SIGNAL(wrongAnswerGiven(lale::core::Question)), teacher, SLOT(wrongAnswerGiven(lale::core::Question)));
    connect(&mainWindow, SIGNAL(rightAnswerGiven(lale::core::Question)), teacher, SLOT(rightAnswerGiven(lale::core::Question)));
    connect(teacher, SIGNAL(newQuestion(lale::core::Question)), &mainWindow, SLOT(changeQuestion(lale::core::Question)));

    teacher->provideNewQuestion();

    StatisticsWindow statisticsWindow;
    connect(scoreRepo, SIGNAL(scoreUpdatedForQuestion(lale::core::Question, double, double)), &statisticsCalculator, SLOT(scoreUpdatedForQuestion(lale::core::Question, double, double)));
    connect(&statisticsCalculator, SIGNAL(statisticsChanged(lale::core::Statistics)), &statisticsWindow, SLOT(statisticsChanged(lale::core::Statistics)));

    mainWindow.show();
    statisticsWindow.show();
    statisticsCalculator.triggerStatisticsChanged();
    return QApplication::exec();
}

Application::~Application()
{
}

