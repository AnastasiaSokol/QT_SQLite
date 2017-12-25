#ifndef SECONDDIALOG_H
#define SECONDDIALOG_H
#include <QDialog>
#include "widget.h"
#include "plotdialog.h"
namespace Ui {
    class SecondDialog;
}

class SecondDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SecondDialog(QWidget *parent = 0);
    ~SecondDialog();

private slots:
    void on_OkButton_clicked();
    void on_UpdateButton_clicked();
    void on_pushButtonDelete_clicked();
    void on_pushButtonLoadTable_clicked();
    void on_tableView_activated(const QModelIndex &index);
    void on_pushButtonPlot_clicked();

signals:
    void loadDB();

private:
    int                 waterID;
    QString             strWaterID;

    int                 waterCount;
    QString             strWaterCount;

    QDate               TimeOfRegister;
    QString             strTime;
    QString             strTimeOfRegister;

    QString             query;

    Ui::SecondDialog    *ui;
};

#endif // SECONDDIALOG_H
