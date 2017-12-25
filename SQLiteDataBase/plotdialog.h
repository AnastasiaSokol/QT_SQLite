#ifndef PLOTDIALOG_H
#define PLOTDIALOG_H
#include <QDialog>
#include "widget.h"
namespace Ui {
    class Dialog;
}
class PlotDialog : public QDialog
{
    Q_OBJECT
public:
    explicit PlotDialog(QWidget *parent = 0);
    ~PlotDialog();



public slots:
    void makePlot();
private:
    Ui::Dialog    *ui;
};
#endif // PLOTDIALOG_H
