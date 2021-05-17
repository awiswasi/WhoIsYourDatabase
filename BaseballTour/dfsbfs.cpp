#include "dfsbfs.h"
#include "ui_dfsbfs.h"
#include <QDebug>
#include <QDialog>
#include <stack>
#include <algorithm>
#include "ballparkdb.h"
#include "triptake.h"
#include "customtrip.h"
#include <map>

void getGraph(QString startingStadium, std::vector<StadiumInfo> unsortedStadiums, int graph[31][31]){
    BallparkDB conn;
    QString queryString;
    conn.connOpen();
    QSqlQuery qry(conn.mydb);
    const int NUM_TEAMS = unsortedStadiums.size();

    int  dist[NUM_TEAMS];
    bool Tset[NUM_TEAMS];

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
    conn.connClose();
//    return graph;
}

int dfsbfs::DFS(int start, std::vector<StadiumInfo> unsortedStadiums, bool visited[31][31], int adj[31][31])
{
    int totalDistance = 0;
    const int NUM_TEAMS = unsortedStadiums.size();


        // For every node of the graph
        for (int i = 0; i < NUM_TEAMS; i++) {

            // If some node is adjacent to the current node
            // and it has not already been visited
            if (adj[start][i] != 0 && (!visited[start][i])) {
                visited[start][i] = true;
                visited[i][start] = true;
                totalDistance = adj[start][i];
//                qDebug()<< "DFS distance " << totalDistance;
                totalDistance += DFS(i, unsortedStadiums, visited, adj);
            }
        }
        ui->dfs_answer_label->setText(QString::number(totalDistance/2));
    return totalDistance;

}
void dfsbfs::BFS(int start, std::vector<StadiumInfo> unsortedStadiums)
{
    const int NUM_TEAMS = unsortedStadiums.size();
    // Visited vector to so that
    // a vertex is not visited more than once
    // Initializing the vector to false as no
    // vertex is visited at the beginning
    vector<bool> visited(NUM_TEAMS, false);
    vector<int> q;
    q.push_back(start);

    int totalDistance = 0;
//    priority_queue pq;

    int graph[31][31];
    getGraph("Minnesota Twins", unsortedStadiums, graph);

    // Set source as visited
    visited[start] = true;

    int vis;
    while (!q.empty()) {
        vis = q[0];

        // Print the current node
        qDebug() << plannedStadiums[vis].teamName;
        q.erase(q.begin());

        // For every adjacent vertex to the current vertex
        for (int i = 0; i < NUM_TEAMS; i++) {
            if (graph[vis][i] != 0 && (!visited[i])) {

                // Push the adjacent node to the queue
                q.push_back(i);
                totalDistance += graph[vis][i];
                // Set
                visited[i] = true;
            }
        }
    }

    ui->bfs_answer_label->setText(QString::number(totalDistance));
    qDebug() << totalDistance;
}


int minimumDist2(int dist[], bool Tset[], int max)
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

bool sortByVal2(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second < b.second);
}

dfsbfs::dfsbfs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dfsbfs)
{
    ui->setupUi(this);

    int bfsStart;
    int dfsStart;

    StadiumInfo tempstad;
    BallparkDB conn;
    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from _MLBinfo");
    qry->exec();

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
        if(tempstad.teamName == "San Francisco Giants")
            bfsStart = count;
        if(tempstad.teamName == "Minnesota Twins")
            dfsStart = count;

        count++;
    }

    conn.connClose();

    plannedStadiums = sortStadiums("San Francisco Giants", allStadiums);
    const int NUM_TEAMS = 31;                                                               // problem maybe

//    vector<bool> visited(NUM_TEAMS, false);
    dfsbfs::BFS(bfsStart, plannedStadiums);
    int dfsDistance = -1;

    int adj[31][31];
    bool visited[31][31] = {false};
    getGraph("San Francisco Giants", plannedStadiums, adj);

    dfsDistance = dfsbfs::DFS(dfsStart, plannedStadiums, visited, adj);

    qDebug() << "constructor " << dfsDistance;

//void dfsbfs::BFS(int start, std::vector<StadiumInfo> unsortedStadiums)
}

dfsbfs::~dfsbfs()
{
    delete ui;
}

std::vector<StadiumInfo> dfsbfs::sortStadiums(QString startingStadium, std::vector<StadiumInfo> unsortedStadiums)
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
//                        qDebug() << "!!!! " << qry1;
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
        int m = minimumDist2(dist,Tset,NUM_TEAMS);
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

    sort(vec.begin(),vec.end(),sortByVal2);

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



void dfsbfs::on_pushButton_clicked()
{

}
