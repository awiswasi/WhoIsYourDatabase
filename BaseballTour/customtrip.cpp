#include "customtrip.h"
#include "ui_customtrip.h"
#include "tripplan.h"
#include "triptake.h"
#include "ballparkdb.h"
#include <QDebug>
#include <algorithm>
#include <QListWidgetItem>

//      /////////////
//    /////////////////
//   /////         /////
//  /////           /////
//  /////////////////////
//  /////////////////////
//  /////////////////////
//  /////////////////////
//  ////////    /////////
//  /////////   //////////

CustomTrip::CustomTrip(const QString START, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomTrip),
    startingStadium(START)
{
    QString STARTING_FROM = "Starting from ";

    ui->setupUi(this);
    ui->label->setText(STARTING_FROM + START);

    BallparkDB conn;
    conn.connOpen();
    QSqlQuery qry(conn.mydb);
    qry.exec("select * from _MLBinfo where teamName != '" + START + "'");

    while(qry.next())
    {
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(qry.value(0).toString());
        item->setCheckState(Qt::Unchecked);

        ui->listView->addItem(item);
    }

    StadiumInfo tempstad;

    qry.exec("select * from _MLBinfo");
    while(qry.next())
    {
        tempstad.teamName = qry.value(0).toString();
        tempstad.stadiumName = qry.value(1).toString();
        tempstad.capacity = qry.value(2).toInt();
        tempstad.location = qry.value(3).toString();
        tempstad.surface = qry.value(4).toString();
        tempstad.leagueType = qry.value(5).toString();
        tempstad.dateOpen = qry.value(6).toInt();
        tempstad.distanceToCenter = qry.value(7).toInt();
        tempstad.typology = qry.value(8).toString();
        tempstad.roofType = qry.value(9).toString();

        allStadiums.push_back(tempstad);
    }

    conn.connClose();
}

CustomTrip::~CustomTrip()
{
    delete ui;
}

int CustomTrip::minimumDist(int dist[], bool Tset[], int max)
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

bool CustomTrip::sortByVal(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second < b.second);
}

std::vector<StadiumInfo> CustomTrip::sortStadiums(QString startingStadium, std::vector<StadiumInfo> unsortedStadiums)
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
        qDebug() << pp;
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
    }

    return sortedStadiums;
}

void CustomTrip::on_buttonBox_accepted()
{
    this->close();

    StadiumInfo tempstad;
    BallparkDB conn;
    vector<StadiumInfo> toSort;

    conn.connOpen();
    QSqlQuery qry(conn.mydb);

    qry.exec("select * from _MLBinfo where teamName == '" + startingStadium + "'");

    qry.next();

    tempstad.teamName = qry.value(0).toString();
    tempstad.stadiumName = qry.value(1).toString();
    tempstad.capacity = qry.value(2).toInt();
    tempstad.location = qry.value(3).toString();
    tempstad.surface = qry.value(4).toString();
    tempstad.leagueType = qry.value(5).toString();
    tempstad.dateOpen = qry.value(6).toInt();
    tempstad.distanceToCenter = qry.value(7).toInt();
    tempstad.typology = qry.value(8).toString();
    tempstad.roofType = qry.value(9).toString();

    alreadyDoneStadiums.push_back(tempstad);

    qDebug() << tempstad.teamName;

    for (int i = 0; i < ui->listView->count(); i++)
    {
        if(ui->listView->item(i)->checkState() == Qt::Checked)
        {
            qry.exec("select * from _MLBinfo where teamName == '" + ui->listView->item(i)->text() + "'");

            qry.next();

            tempstad.teamName = qry.value(0).toString();
            tempstad.stadiumName = qry.value(1).toString();
            tempstad.capacity = qry.value(2).toInt();
            tempstad.location = qry.value(3).toString();
            tempstad.surface = qry.value(4).toString();
            tempstad.leagueType = qry.value(5).toString();
            tempstad.dateOpen = qry.value(6).toInt();
            tempstad.distanceToCenter = qry.value(7).toInt();
            tempstad.typology = qry.value(8).toString();
            tempstad.roofType = qry.value(9).toString();
            toSort.push_back(tempstad);

            qDebug() << tempstad.teamName;
        }
    }

    conn.connClose();

    QString prev = startingStadium;
    StadiumInfo next;
    vector<StadiumInfo> workingVec;

    bool found = false;

    while(toSort.size()>0)
    {
        int i = 1;
        int j = 0;

        workingVec = sortStadiums(prev, allStadiums);

        while(!found && i < int(workingVec.size()))
        {
            while(!found && j < int(toSort.size()))
            {
                found = workingVec[i].teamName == toSort[j].teamName;

                if(found)
                {
                    prev = workingVec[i].teamName;
                }
                else
                {
                    j++;
                }
            }

            if(!found)
            {
                i++;
                j = 0;
            }
        }

        alreadyDoneStadiums.push_back(workingVec[i]);
        toSort.erase(toSort.begin() + j);

        found = false;
    }

    for (int i = 1; i < int(alreadyDoneStadiums.size()); i++)
    {
        alreadyDoneStadiums[i].distanceNeeded=alreadyDoneStadiums[i-1].distanceNeeded+alreadyDoneStadiums[i].distanceNeeded;
    }

    TripTake tt(alreadyDoneStadiums);
    tt.exec();
}


