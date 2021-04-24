#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindialog.h"
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase souvenirsDB = QSqlDatabase::addDatabase("QSQLITE");
    souvenirsDB.setDatabaseName("C:/Users/awfwi/OneDrive/Desktop/CS1D/souvenirs.db");

    souvenirsDB.open();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionLogin_triggered()
{
    loginDialog *loginWindow = new loginDialog;
    loginWindow->exec();
    isAdmin = loginWindow->getLoggedIn();

    if (isAdmin)
    {
//        ui->actionAdd_from_file->setEnabled(true);
//        ui->actionLog_Out->setEnabled(true);
//        ui->addButton->setVisible(true);
//        ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
//        ui->saveButton->setVisible(true);
    }
    delete loginWindow;
}
//void MainWindow::on_actionLog_Out_triggered()
//{
//    isAdmin = false;
//    ui->actionAdd_from_file->setEnabled(false);
//    ui->actionLog_Out->setEnabled(false);
//    ui->addButton->setVisible(false);
//    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    ui->saveButton->setVisible(false);
//}


void MainWindow::on_push_souvenirs_clicked()
{
    souvenirsDB.open();

    MainWindow souvenirObj;
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery * qry=new QSqlQuery(souvenirObj.souvenirsDB);
    qry->prepare("select souvenir, price from souvenirs");

    qry->exec();

    model->setQuery(*qry);
    ui->tableView->setModel(model);
}
