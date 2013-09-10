#include "gui/mainwindow.h"

#include "ui_mainwindow.h"

using namespace lale::gui;
using namespace lale::core;

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeQuestion(Question question)
{
    ui->question->setText(question.getQuestion());
    currentAnswer = question.getAnswer();
    ui->answer->setText("");
    ui->right->setHidden(true);
    ui->wrong->setHidden(true);
    ui->showAnswer->setHidden(false);
}

void MainWindow::answerVerified()
{
    emit questionChangeRequest();
}

void MainWindow::showAnswer()
{
    ui->answer->setText(currentAnswer);
    ui->showAnswer->setHidden(true);
    ui->right->setHidden(false);
    ui->wrong->setHidden(false);
}
