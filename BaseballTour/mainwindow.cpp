#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



//void MainWindow::on_actionLogin_triggered()
//{
//    loginDialog *loginWindow = new loginDialog;
//    loginWindow->exec();
//    isAdmin = loginWindow->getLoggedIn();

//    if (isAdmin)
//    {
//        ui->actionAdd_from_file->setEnabled(true);
//        ui->actionLog_Out->setEnabled(true);
//        ui->addButton->setVisible(true);
//        ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
//        ui->saveButton->setVisible(true);
//    }
//    delete loginWindow;
//}
//void MainWindow::on_actionLog_Out_triggered()
//{
//    isAdmin = false;
//    ui->actionAdd_from_file->setEnabled(false);
//    ui->actionLog_Out->setEnabled(false);
//    ui->addButton->setVisible(false);
//    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    ui->saveButton->setVisible(false);
//}




