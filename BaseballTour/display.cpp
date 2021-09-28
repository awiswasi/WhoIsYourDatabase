#include "display.h"
#include "ui_display.h"
#include "login.h"
#include <QSqlQueryModel>

display::display(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::display)
{
    ui->setupUi(this);
}

display::~display()
{
    delete ui;
}

void display::on_pushButton_clicked()
{
    login conn;
    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.mydb);

    qry->prepare("select EndingCity, Kilometers from EuropeanInfo where StartingCity = 'Berlin'");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    qDebug() << (modal->rowCount());

}
