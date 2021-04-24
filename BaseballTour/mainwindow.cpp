#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ballparkdb.h"
#include <QtSql>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    BallparkDB bpdb;

    if(!bpdb.connOpen())
    {
        ui->label_dbstatus->setText("Put DB's in build/databases/ folder");
        qDebug() << "Put databases in " << QString(QCoreApplication::applicationDirPath()) << " / databases/";
    }
    else
        ui->label_dbstatus->setText("Database connected");

    BallparkDB conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from MLBinfo");
    qry->exec();

    modal->setQuery(*qry);

    ui->tableView->setModel(modal);

    conn.connClose();
}

MainWindow::~MainWindow()
{
    delete ui;
}

