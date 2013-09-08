#ifndef LALE_GUI_MAINWINDOW_H
#define LALE_GUI_MAINWINDOW_H

#include <QMainWindow>
#include "core/question.h"

namespace Ui {
    class MainWindow;
}

namespace lale { namespace gui {

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    QString currentAnswer;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;

public slots:
    void changeQuestion(lale::core::Question);
    void answerVerified();
    void showAnswer();

signals:
    void questionChangeRequest();
};

}}

#endif // LALE_GUI_MAINWINDOW_H
