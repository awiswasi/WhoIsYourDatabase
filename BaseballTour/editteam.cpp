#include "editteam.h"
#include "ui_editteam.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtSql>
#include <QSqlDatabase>
#include "ballparkdb.h"

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


    teamName =ui->lineEdit_teamname->text();
    stadiumName =ui->lineEdit_stadiumname->text();
    seatingCapacity =ui->lineEdit_seatingcapacity->text();
    location =ui->lineEdit_location->text();
    playingSurface =ui->lineEdit_playingsurface->text();
    league =ui->lineEdit_league->text();
    dateOpened =ui->lineEdit_dateopened->text();
    distanceToCenter =ui->lineEdit_distancetocenter->text();
    ballparkTypology =ui->lineEdit_ballparktypology->text();
    roofType =ui->lineEdit_rooftype->text();


    QString changes;
    changes.append("insert into _MLBinfo (teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType) values ('"
                                    +teamName+"', '"+stadiumName+"', '"+seatingCapacity+"', '"+location+"', '"+playingSurface+"', '"+league+"', '"+dateOpened+"', '"+distanceToCenter+"', '"+ballparkTypology+"', '"+roofType+"')");

    BallparkDB conn;
    conn.connOpen();

    qDebug() << changes;

    QSqlQuery update;
    update.prepare(changes);

    if(update.exec()){
        qDebug()<<"Added team.";
    }else{
        qDebug()<<"Something went wrong";
        qDebug()<<"ERROR! " << update.lastError();
    }

    conn.connClose();
}

void editTeam::on_CancelButton_clicked()
{
    this->close();
}

void editTeam::on_expansionButton_clicked()
{
    ui->lineEdit_teamname->setText("Las Vegas Gamblers");
    ui->lineEdit_stadiumname->setText("Las Vegas Stadium");
    ui->lineEdit_seatingcapacity->setText("44,444");
    ui->lineEdit_location->setText("Las Vegas, Nevada");
    ui->lineEdit_playingsurface->setText("Grass");
    ui->lineEdit_league->setText("National");
    ui->lineEdit_dateopened->setText("2022");
    ui->lineEdit_distancetocenter->setText("400");
    ui->lineEdit_ballparktypology->setText("Retro Modern");
    ui->lineEdit_rooftype->setText("Open");

    on_SaveButton_clicked();
}
