#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindialog.h"
#include "addsouvenir.h"
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QTableWidget>
#include <QFileDialog>
#include <iostream>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->statusBar()->setSizeGripEnabled(false);

    QSqlDatabase souvenirsDB = QSqlDatabase::addDatabase("QSQLITE");
        souvenirsDB.setDatabaseName("../souvenirs.db");

        souvenirsDB.open();

    // Set table properties (resize to contents, fill the widget with last section, prevent editing)
//    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
//    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
//    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    ui->tableWidget->clear();
//    ui->tableWidget->insertRow ( ui->tableWidget->rowCount() );
//    ui->tableWidget->insertRow ( ui->tableWidget->rowCount() );


//    createCList();

//    ui->actionAdd_from_file->setEnabled(false);
    ui->actionLog_Out->setEnabled(false);

    ui->addButton->setVisible(false);
    ui->saveButton->setVisible(false);
    ui->editButton->setVisible(false);
    ui->addSouvenirButton->setVisible(false);

//    connect(ui->homeBox,SIGNAL(activated(int)), this, SLOT(showColleges(int)));
////    connect(ui->homeBox,SIGNAL(activated(int)), this, SLOT(displaySouvenirs(int)));
//    connect(ui->campusTable,SIGNAL(currentRowChanged(int)), this, SLOT(displaySouvenirs(int)));
//    connect(ui->campusTable,SIGNAL(currentRowChanged(int)), this, SLOT(getCollegeIndex(int)));

    //isAdmin = false;
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
        ui->actionLog_Out->setEnabled(true);
        ui->addButton->setVisible(true);
        ui->editButton->setVisible(true);
        ui->addSouvenirButton->setVisible(true);
        ui->actionLogin->setEnabled(false);

//        ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
        ui->saveButton->setVisible(true);
    }
    delete loginWindow;
}
void MainWindow::on_actionLog_Out_triggered()
{
    isAdmin = false;
//    ui->actionAdd_from_file->setEnabled(false);
    ui->actionLog_Out->setEnabled(false);
    ui->actionLogin->setEnabled(true);
    ui->addButton->setVisible(false);
//    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->saveButton->setVisible(false);
    ui->editButton->setVisible(false);
    ui->addSouvenirButton->setVisible(false);
}


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

void MainWindow::on_addSouvenirButton_clicked()
{
    // open a new dialog window to add a souvenir

    addSouvenirs = new addsouvenir(this);
    addSouvenirs->show();

}
