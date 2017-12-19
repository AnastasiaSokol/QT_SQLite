#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QSqlDatabase mydb= QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("water.db");


    if(!mydb.open()){
        ui->label->setText(tr("db Disconnected"));
    }
    else{
        ui->label->setText(tr("db Connected"));
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_ButtonLogin_clicked()
{
    QString username = ui->lineEditUserName->text();
    QString password = ui->lineEditPassword->text();
    //проверка на корректность имени пользователя и его пароля
    if  (username=="test" && password=="test"){
        QMessageBox::information(this, "Login","UserName and Password is correct");
        this->hide();//скрыть окно для login
        secondD = new SecondDialog(this);
        secondD->show();
    }
    else {
        QMessageBox::information(this, "Login","UserName and Password is not correct");

    }
}
