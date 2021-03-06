#include "gui/mainwindow.h"

#include "ui_mainwindow.h"

using namespace lale::gui;
using namespace lale::core;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    currentQuestion("", ""),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_wrong_clicked()
{
    emit wrongAnswerGiven(currentQuestion);
    emit questionChangeRequest();
}

void MainWindow::on_right_clicked()
{
    emit rightAnswerGiven(currentQuestion);
    emit questionChangeRequest();
}

void MainWindow::changeQuestion(Question question)
{
    ui->question->setText(question.getQuestion());
    currentQuestion = question;
    ui->answer->setText("");
    ui->right->setHidden(true);
    ui->wrong->setHidden(true);
    ui->showAnswer->setHidden(false);
}

void MainWindow::on_showAnswer_clicked()
{
    ui->answer->setText(currentQuestion.getAnswer());
    ui->showAnswer->setHidden(true);
    ui->right->setHidden(false);
    ui->wrong->setHidden(false);
}
