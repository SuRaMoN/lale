#ifndef LALE_GUI_MAINWINDOW_H
#define LALE_GUI_MAINWINDOW_H

#include "app/libs.h"
#include "core/question.h"

namespace Ui {
    class MainWindow;
}

namespace lale { namespace gui {

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    lale::core::Question currentQuestion;

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();
    
private:
    Ui::MainWindow *ui;

public slots:
    void changeQuestion(lale::core::Question);
    void on_wrong_clicked();
    void on_right_clicked();
    void on_showAnswer_clicked();

signals:
    void questionChangeRequest();
    void wrongAnswerGiven(lale::core::Question);
    void rightAnswerGiven(lale::core::Question);
};

}}

#endif // LALE_GUI_MAINWINDOW_H
