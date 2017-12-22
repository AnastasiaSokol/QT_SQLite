#include "seconddialog.h"
#include "ui_seconddialog.h"

SecondDialog::SecondDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondDialog)
{
    ui->setupUi(this);
    //---------------------------------------------------------
    //проверка подключена ли база данных
    Widget conn;
    if(!conn.connectionOpen()){
        ui->StatusConnectionLabel->setText(tr("db Disconnected"));
    }
    else{
        ui->StatusConnectionLabel->setText(tr("db Connected"));
    }
}

SecondDialog::~SecondDialog()
{
    delete ui;
}

void SecondDialog::on_OkButton_clicked()
{
    //save action ---------------------------------


}
