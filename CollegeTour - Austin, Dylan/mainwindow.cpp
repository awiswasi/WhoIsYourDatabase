#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QTableWidget>
#include <QFileDialog>
#include <iostream>
#include "dataBase.h"
#include "triptake.h"
#include "tripplan.h"
#include <vector>
#include "logindialog.h"
#include <QDebug>

vector<College> dataBase;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    readFile(dataBase);

    ui->setupUi(this);
    this->setFixedSize(800,555);
    this->statusBar()->setSizeGripEnabled(false);

    // Set table properties (resize to contents, fill the widget with last section, prevent editing)
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->clear();
    ui->tableWidget->insertRow ( ui->tableWidget->rowCount() );
    ui->tableWidget->insertRow ( ui->tableWidget->rowCount() );


    createCList();

    ui->actionAdd_from_file->setEnabled(false);
    ui->actionLog_Out->setEnabled(false);
    ui->addButton->setVisible(false);
    ui->saveButton->setVisible(false);

    connect(ui->homeBox,SIGNAL(activated(int)), this, SLOT(showColleges(int)));
//    connect(ui->homeBox,SIGNAL(activated(int)), this, SLOT(displaySouvenirs(int)));
    connect(ui->campusTable,SIGNAL(currentRowChanged(int)), this, SLOT(displaySouvenirs(int)));
    connect(ui->campusTable,SIGNAL(currentRowChanged(int)), this, SLOT(getCollegeIndex(int)));

    //isAdmin = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createCList()
{
    ui->homeBox->clear();
    ui->homeBox->addItem("Select a school...");
    for(unsigned long long int i = 0; i < dataBase.size(); i++)
    {
        ui->homeBox->addItem(QString::fromStdString(dataBase.at(i).getName()));
    }
}

void MainWindow::displaySouvenirs(int index)   //, College college)                                                              //
{
//    int index = selection - 1;


    if (int(dataBase.size()) < index || index < 0){
        ui->tableWidget->clear();
        return;
    }
    int skipped = 0;
    for(int i = 0; i < 7; i++){
        if(QString::fromStdString(dataBase.at(index).getSouvenir(i).souvenir) == "a" || QString::fromStdString(dataBase.at(index).getSouvenir(i).souvenir) == "\r" || QString::fromStdString(dataBase.at(index).getSouvenir(i).souvenir) == ""){
            skipped++;
        }
        if(i+skipped < 7){
        ui->tableWidget->setItem(i,1, new QTableWidgetItem(QString::fromStdString(dataBase.at(index).getSouvenir(i+skipped).souvenir)));
        ui->tableWidget->setItem(i,0, new QTableWidgetItem("$" + QString::number(dataBase.at(index).getSouvenir(i+skipped).cost)));
}

    }
    for(int i = 7-skipped; i < 8; i ++){
        ui->tableWidget->setItem(i,1, new QTableWidgetItem(""));
        ui->tableWidget->setItem(i,0, new QTableWidgetItem(""));
    }
}

void MainWindow::getCollegeIndex(int index)
{
    collegeIndex = index;
}

void MainWindow::editSouvenirs(int index)
{
    qDebug() << index << '\n';
}

void MainWindow::showColleges(int index)
{
    int selection = index-1;

    ui->campusTable->clear();

    if (index != 0)
        ui->campusTable->addItem(QString::fromStdString(dataBase.at(selection).getName()) + " - " + "HOME");

    for(unsigned long long int i = 0; i < dataBase.size()-1; i++)
        if (index != 0)
            ui->campusTable->addItem(QString::fromStdString(dataBase.at(selection).getDistances(i).endingCollege) +
                                     " - " + QString::number(dataBase.at(selection).getDistances(i).distanceBetween));
}


void MainWindow::on_pushButton_clicked()
{
    TripPlan tripplan(dataBase, ui->homeBox->currentIndex());
    tripplan.exec();
}

void MainWindow::on_actionLogin_triggered()
{
    loginDialog *loginWindow = new loginDialog;
    loginWindow->exec();
    isAdmin = loginWindow->getLoggedIn();

    if (isAdmin)
    {
        ui->actionAdd_from_file->setEnabled(true);
        ui->actionLog_Out->setEnabled(true);
        ui->addButton->setVisible(true);
        ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
        ui->saveButton->setVisible(true);
    }
    delete loginWindow;
}
void MainWindow::on_actionLog_Out_triggered()
{
    isAdmin = false;
    ui->actionAdd_from_file->setEnabled(false);
    ui->actionLog_Out->setEnabled(false);
    ui->addButton->setVisible(false);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->saveButton->setVisible(false);
}

void MainWindow::on_addButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open Text File"), "",
            tr("Text file (*.txt);;All Files (*)"));
    string stdFileName = fileName.toLocal8Bit().constData();
    addCollege(dataBase, stdFileName);
    createCList();
}


void MainWindow::on_saveButton_clicked()
{
    //im sure theres a better way for this but this is what i came up with
    vector<string> nameV;
    vector<double> priceV;
    QString nameQ;
    QString priceStr;
    string name;
    double price;

    if (collegeIndex > -1)
    {
        for (int i = 0; i < ui->tableWidget->rowCount(); i++)
        {

            nameQ = ui->tableWidget->item(i,1)->text();
            priceStr = ui->tableWidget->item(i,0)->text();

            name = nameQ.toLocal8Bit().constData();
            price = priceStr.remove(0,1).toDouble();

            nameV.push_back(name);
            priceV.push_back(price);
        }

        for (int i = 0; i < ui->tableWidget->rowCount(); i++)
        {
            dataBase.at(collegeIndex).setSouvenir(nameV[i],priceV[i],i);
            }
        }


    //name.chop(1);

    //qDebug() << collegeIndex << ' ' << name << ' ' << price <<'\n';
}

void MainWindow::on_actionSave_triggered()
{
    saveFiles(dataBase);
}
