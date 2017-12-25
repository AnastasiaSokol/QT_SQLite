#include "plotdialog.h"
#include "ui_plot.h"

PlotDialog::PlotDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Form Plot"));
    PlotDialog::makePlot();
}
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
PlotDialog::~PlotDialog()
{
    delete ui;
}
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void PlotDialog::makePlot()
{
    int countData=5;

    qDebug() <<"slot makePlot()------------------------";
    // generate some data:
    QVector<double> x(countData), y(countData); // initialize with entries 0..100

    //подключаемся к базе данных и пытаемся взять оттуда данные
    Widget conn;
    //Класс QSqlQueryModel предоставляет модель данных только для чтения для наборов результатов SQL.
    QSqlQueryModel *modal = new QSqlQueryModel();
    conn.connectionOpen();
    //Класс QSqlQuery предоставляет средства для выполнения и обработки операторов SQL.
    QSqlQuery *qry = new QSqlQuery(conn.mydb);

    qry->prepare("select waterCount from WaterData");

    int i=0;
    if (qry->exec()){
        //транспортируем данные полученные после запроса в объект qsqlQueryModel
        modal->setQuery(*qry);
        ui->listView->setModel(modal);
    }else{qDebug() <<"Can not execute sql";}


    //закрываем соединение с бд
    conn.connectionClose();


    QModelIndex firstIndex = ui->listView->model()->index( 0, 0 );
    for (int i=0; i<countData; ++i)
    {
      //x[i] = i/50.0 - 1; // x goes from -1 to 1
      //y[i] = x[i]*x[i]*x[i]; // let's plot a quadratic function
      x[i]=i;
      y[i] = ui->listView->model()->data(firstIndex.sibling(i,0)).toDouble(); // x goes from -1 to 1
      qDebug() <<"y[i]="<<y[i];
    }

    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(-10, 10);
    ui->customPlot->yAxis->setRange(0, 10);
    ui->customPlot->replot();
}
