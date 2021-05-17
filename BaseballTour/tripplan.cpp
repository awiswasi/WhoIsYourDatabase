#include "tripplan.h"
#include "triptake_old.h"
#include "ui_tripplan.h"
#include <QDebug>
#include <QDialog>
#include "ballparkdb.h"
#include "triptake.h"
#include "customtrip.h"
#include <map>
#include <algorithm>

QString scrapStadium(QString str)
{
    int index = 0;
    bool done = index > str.length();

    while(!done)
    {
        if(str[index] == '(')
        {
            done = true;
            index = index - 1;

            if(index < 0)
            {
                index = 0;
            }
        }

        if(!done)
        {
            index++;
            done = index > str.length();
        }
    }

    return str.left(index);
}

void TripPlan::on_button_AutomaticTrip_clicked()
{
    if(ui->dropdown_CollegeList->currentIndex() == 0)
    {
        return;
    }

    this->close();

    plannedStadiums = sortStadiums(scrapStadium(ui->dropdown_CollegeList->currentText()),allStadiums);
//    vector<StadiumInfo> concatStadiums(plannedStadiums.begin(),plannedStadiums.begin() + ui->spin_numColleges->value());
    vector<StadiumInfo> concatStadiums(plannedStadiums.begin(),plannedStadiums.begin() + endIndex);

    TripTake * trip = new TripTake(concatStadiums, this);
    trip->exec();
    qDebug() << scrapStadium(ui->dropdown_CollegeList->currentText());
}

void TripPlan::on_button_CustomTrip_clicked()
{
    CustomTrip * ct = new CustomTrip(scrapStadium(ui->dropdown_CollegeList_2->currentText()));
    ct->exec();

    qDebug() << scrapStadium(ui->dropdown_CollegeList_2->currentText());
}

TripPlan::TripPlan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TripPlan)
{
    ui->setupUi(this);

    StadiumInfo tempstad;
    BallparkDB conn;
    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from _MLBinfo");
    qry->exec();

    ui->dropdown_CollegeList->addItem("Select a team...");
    ui->dropdown_CollegeList_2->addItem("Select a team...");
    ui->dropdown_endStadium->addItem("Select a team...");

    int count = 0;

    while(qry->next()) //these seem to be coming out in alphabetical order by default
    {
        tempstad.teamName = qry->value(0).toString();
        tempstad.stadiumName = qry->value(1).toString();
        tempstad.capacity = qry->value(2).toInt();
        tempstad.location = qry->value(3).toString();
        tempstad.surface = qry->value(4).toString();
        tempstad.leagueType = qry->value(5).toString();
        tempstad.dateOpen = qry->value(6).toInt();
        tempstad.distanceToCenter = qry->value(7).toInt();
        tempstad.typology = qry->value(8).toString();
        tempstad.roofType = qry->value(9).toString();
        allStadiums.push_back(tempstad);

        ui->dropdown_CollegeList->addItem(qry->value(0).toString() + " (" + qry->value(1).toString() + ")");
        ui->dropdown_CollegeList_2->addItem(qry->value(0).toString() + " (" + qry->value(1).toString() + ")");
        ui->dropdown_endStadium->addItem(qry->value(0).toString() + " (" + qry->value(1).toString() + ")");

        count++;
    }

    ui->spin_numColleges->setValue(count);
    ui->spin_numColleges->setMaximum(count);

    conn.connClose();
}

int minimumDist(int dist[], bool Tset[], int max)
{
    int min=INT_MAX,index;

    for(int i=0;i<max;i++)
    {
        if(Tset[i]==false && dist[i]<=min)
        {
            min=dist[i];
            index=i;
        }
    }
    return index;
}

bool sortByVal(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second < b.second);
}

std::vector<StadiumInfo> TripPlan::sortStadiums(QString startingStadium, std::vector<StadiumInfo> unsortedStadiums)
{
    BallparkDB conn;
    QString queryString;
    conn.connOpen();
    QSqlQuery qry(conn.mydb);

    const int NUM_TEAMS = unsortedStadiums.size();

    int  dist[NUM_TEAMS];
    bool Tset[NUM_TEAMS];

    int graph[NUM_TEAMS][NUM_TEAMS];

    int start;

    for(int i = 0; i < NUM_TEAMS; i++)
    {
        dist[i] = INT_MAX;
        Tset[i] = false;

        for(int j = 0; j < NUM_TEAMS; j++)
        {
            if(i == j)
            {
                graph[i][j] = 0;
            }
            else
            {
                graph[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < NUM_TEAMS; i++)
    {
        if (unsortedStadiums[i].teamName == startingStadium)
        {
            start = i;
            dist[start] = 0;
        }
        queryString = QString("select destinationStadium, distance from _DISTANCES "
                        "where originatedStadium = \"") + QString(unsortedStadiums[i].stadiumName) + QString("\"");

        qry.prepare(queryString);
        if(qry.exec())
        {
            while(qry.next())
            {
                QString qry0 = qry.value(0).toString();
                int qry1 = qry.value(1).toInt();

                for(int j = 0; j < NUM_TEAMS; j++)
                {
                    if (unsortedStadiums[j].stadiumName == qry0)
                    {
                        graph[i][j] = qry1;
                        graph[j][i] = qry1;
                        qDebug() << "!!!! " << qry1;
                    }
                }
            }
        }
        else
        {
            qDebug() << "ERROR IN sortStadiums() #1";
            qDebug() << qry.lastError();
            qDebug() << qry.lastQuery();
        }

    }


    for(int i = 0; i < NUM_TEAMS; i++)
    {
        QString pp = "[";
        for(int j = 0; j < NUM_TEAMS; j++)
        {
            pp = pp + QString::number(graph[i][j]) + QString("] [");
        }
        qDebug() << pp;                                                         // outputting graph
    }

    conn.connClose();

    for (int i = 0; i < NUM_TEAMS; i++)
    {
        int m = minimumDist(dist,Tset,NUM_TEAMS);
        Tset[m] = true;
        for(int i = 0; i < NUM_TEAMS; i++)
        {
            if(!Tset[i] && graph[m][i] && dist[m]!=INT_MAX && dist[m]+graph[m][i]<dist[i])
            {
                dist[i]=dist[m]+graph[m][i];
            }
        }
    }

    std::vector<std::pair<int,int>> vec;

    for(int i = 0; i<NUM_TEAMS; i++)
    {
        vec.push_back(make_pair(i,dist[i]));
    }

    sort(vec.begin(),vec.end(),sortByVal);

    vector<StadiumInfo> sortedStadiums;
    StadiumInfo tempTeam;

    for(int i = 0; i < NUM_TEAMS; i++)
    {
        qDebug() << unsortedStadiums[vec[i].first].stadiumName << QString::number(vec[i].second);

        tempTeam = unsortedStadiums[vec[i].first];
        tempTeam.distanceNeeded = vec[i].second;
        sortedStadiums.push_back(tempTeam);

        if(tempTeam.teamName == scrapStadium(ui->dropdown_endStadium->currentText()))
            endIndex = i + 1;
    }
    if(ui->dropdown_endStadium->currentText()=="Select a team...")
        endIndex = ui->spin_numColleges->value();
    qDebug() << endIndex;

    return sortedStadiums;
}

TripPlan::~TripPlan(){delete ui;}
