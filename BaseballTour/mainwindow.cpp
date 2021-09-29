#include "mainwindow.h"
#include "display.h"
#include "login.h"
#include "trip.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_displayCities_clicked()
{
    display disp;
    disp.setModal(true);
    disp.exec();
}

void MainWindow::on_planYourTripButton_clicked()
{
    trip trp;
    trp.setModal(true);
    trp.exec();
}

void MainWindow::on_adminButton_clicked()
{
    login log;
    log.setModal(true);
    log.exec();
}
