#ifndef LALE_GUI_STATISTICSWINDOW_H
#define LALE_GUI_STATISTICSWINDOW_H

#include "app/libs.h"
#include "core/statistics.h"

namespace Ui {
    class StatisticsWindow;
}

namespace lale { namespace gui {

class StatisticsWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit StatisticsWindow(QWidget *parent = 0);
    virtual ~StatisticsWindow();
    
private:
    Ui::StatisticsWindow *ui;

public slots:
    void statisticsChanged(lale::core::Statistics);
};

}}

#endif // LALE_GUI_STATISTICSWINDOW_H
