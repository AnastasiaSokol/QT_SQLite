#ifndef WIDGET_H
#define WIDGET_H
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QWidget>
#include "seconddialog.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_ButtonLogin_clicked();

private:
    Ui::Widget *ui;
    SecondDialog *secondD;
};

#endif // WIDGET_H
