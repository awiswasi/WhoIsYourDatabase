#include "trip.h"
#include "ui_trip.h"
#include "triptake.h"
#include <QDebug>
#include <QDialog>

trip::trip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::trip)
{
    ui->setupUi(this);
}

trip::~trip()
{
    delete ui;
}

//#include "ballparkdb.h"
//#include "triptake.h"

//QString scrapCity(QString str)
//{
//    int index = 0;
//    bool done = index > str.length();

//    while(!done)
//    {
//        if(str[index] == '(')
//        {
//            done = true;
//            index = index - 1;

//            if(index < 0)
//            {
//                index = 0;
//            }
//        }

//        if(!done)
//        {
//            index++;
//            done = index > str.length();
//        }
//    }

//    return str.left(index);
//}

//void trip::on_button_AutomaticTrip_clicked()
//{
//    this->close();

//    plannedStadiums = sortStadiums("",allStadiums);
//    vector<StadiumInfo> concatStadiums(plannedStadiums.begin(),plannedStadiums.begin() + ui->spin_numColleges->value());

//    TripTake * trip = new TripTake(concatStadiums, this);
//    trip->exec();
//    qDebug() << scrapStadium(ui->dropdown_CollegeList->currentText());
//}

//void TripPlan::on_button_CustomTrip_clicked()
//{
//    qDebug() << scrapStadium(ui->dropdown_CollegeList_2->currentText());
//}

//TripPlan::TripPlan(QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::TripPlan)
//{
//    ui->setupUi(this);

//    StadiumInfo tempstad;
//    BallparkDB conn;
//    conn.connOpen();
//    QSqlQuery * qry = new QSqlQuery(conn.mydb);

//    qry->prepare("select * from _MLBinfo");
//    qry->exec();

//    ui->dropdown_CollegeList->addItem("Select a team...");
//    ui->dropdown_CollegeList_2->addItem("Select a team...");

//    int count = 0;

//    while(qry->next()) //these seem to be coming out in alphabetical order by default
//    {
//        tempstad.teamName = qry->value(0).toString();
//        tempstad.stadiumName = qry->value(1).toString();
//        tempstad.capacity = qry->value(2).toInt();
//        tempstad.location = qry->value(3).toString();
//        tempstad.surface = qry->value(4).toString();
//        tempstad.leagueType = qry->value(5).toString();
//        tempstad.dateOpen = qry->value(6).toInt();
//        tempstad.distanceToCenter = qry->value(7).toInt();
//        tempstad.typology = qry->value(8).toString();
//        tempstad.roofType = qry->value(9).toString();
//        allStadiums.push_back(tempstad);

//        ui->dropdown_CollegeList->addItem(qry->value(0).toString() + " (" + qry->value(1).toString() + ")");
//        ui->dropdown_CollegeList_2->addItem(qry->value(0).toString() + " (" + qry->value(1).toString() + ")");
//        count++;
//    }

//    ui->spin_numColleges->setValue(count);
//    ui->spin_numColleges->setMaximum(count);

//    conn.connClose();

void trip::on_button_AutomaticTrip_clicked()
{
    triptake trp;
    trp.setModal(true);
    trp.exec();
}

void trip::on_dropdown_CollegeList_activated(const QString &arg1)
{
//    mydb conn;
//    QSqlQuery * qry = new QSqlQuery(conn.mydb);
//    qry->prepare("select * from mydb");
//    qry->exec();
       /*conn.connOpen();
       QSqlQuery * qry = new QSqlQuery(conn.mydb);



       ui->dropdown_CollegeList->addItem("Select a City...");*/
//   //    ui->dropdown_CollegeList_2->addItem("Select a team...");





}
