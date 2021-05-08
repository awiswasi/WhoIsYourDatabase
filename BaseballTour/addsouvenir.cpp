#include "addsouvenir.h"
#include "ui_addsouvenir.h"
#include <QTimer>
#include <QDialog>
#include <QMessageBox>

addsouvenir::addsouvenir(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addsouvenir)
{
    ui->setupUi(this);

    QSqlDatabase souvenirsDB = QSqlDatabase::addDatabase("QSQLITE");
        souvenirsDB.setDatabaseName("../souvenirs.db");

        souvenirsDB.open();
}

addsouvenir::~addsouvenir()
{
    delete ui;
}

void addsouvenir::on_pushButton_clicked()
{
    addsouvenir obj;
            QString souvenirName, price;
            souvenirName =ui->souvenirNameText->text();
            price =ui->souvenirPriceText->text();

            souvenirsDB.open();
            QSqlQuery * qry=new QSqlQuery(obj.souvenirsDB);
            qry->prepare("insert into souvenirs(souvenir, price) values ('"+souvenirName+"', '"+price+"')");

            qry->exec();
}
