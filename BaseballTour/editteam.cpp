#include "editteam.h"
#include "ui_editteam.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtSql>
#include <QSqlDatabase>


editTeam::editTeam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editTeam)
{
    ui->setupUi(this);
}

editTeam::~editTeam()
{
    delete ui;
}

void editTeam::on_SaveButton_clicked()
{
    QString teamName;
    QString stadiumName;
    QString seatingCapacity;        // int
    QString location;
    QString playingSurface;
    QString league;
    QString dateOpened;             // int
    QString distanceToCenter;       // int
    QString ballparkTypology;
    QString roofType;


    teamName =ui->label->text();
    stadiumName =ui->label_2->text();
    seatingCapacity =ui->label_3->text();
    location =ui->label_4->text();
    playingSurface =ui->label_5->text();
    league =ui->label_6->text();
    dateOpened =ui->label_7->text();
    distanceToCenter =ui->label_8->text();
    ballparkTypology =ui->label_9->text();
    roofType =ui->label_10->text();


    QString changes;
    changes.append("insert into _MLBinfo (teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType) values ('"+teamName+"', '"+stadiumName+"', '"+seatingCapacity+"', '"+location+"', '"+playingSurface+"', '"+league+"', '"+dateOpened+"', '"+distanceToCenter+"', '"+ballparkTypology+"', '"+roofType+"')");


    QSqlQuery update;
    update.prepare(changes);

    if(update.exec()){
        qDebug()<<"the student is successful update.";
    }else{
        qDebug()<<"the student is NOT successful update.";
        qDebug()<<"ERROR! " << update.lastError();
    }

}
