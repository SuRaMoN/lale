#include "statisticswindow.h"
#include "ui_statisticswindow.h"

using namespace lale::gui;

StatisticsWindow::StatisticsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatisticsWindow)
{
    ui->setupUi(this);
}

StatisticsWindow::~StatisticsWindow()
{
    delete ui;
}

void StatisticsWindow::statisticsChanged(lale::core::Statistics statistics)
{
    QString statisticsString;
    statisticsString += "Percentage not yet learned: " + QString::number(statistics.percentageNotYetLearned * 100);
    ui->statisticsLabel->setText(statisticsString);
}
