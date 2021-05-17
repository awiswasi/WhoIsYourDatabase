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

void dfsbfs::DFS(QString start, std::vector<StadiumInfo> unsortedStadiums)
{
//    const int NUM_TEAMS = unsortedStadiums.size();

//    qDebug() << "Depth First Search:\n";
//    int graph[31][31];
//    vector<int> edges;
//    getGraph("San Francisco Giants", unsortedStadiums, graph);
//    vector<QString> accessed;
//    vector<int> discovery;
//    string end;
//    int position = -1;
//    int accum = 0;
////    vertex *s = (work.find(start)->second);

//    //Runs a loop while the accessed locations are less than the total list
//    // of locations
//    while(accessed.size() < NUM_TEAMS) // change to while
//    {

//        vertex *next = NULL;
//        // If the item being visited has not yet been accessed then
//        // output its name
////        if (find(accessed.begin(), accessed.end(), s->name) == accessed.end())
////        {
//////            qDebug() << s->name << endl;
////            accessed.push_back(s->name);
////            position ++;
////        }

//        // Stores all of the distances for the current verticy in a vector
//        vector<int> dist;
//        for(unsigned int i = 0; i < s->adj.size(); i++)
//        {
//            dist.push_back(s->adj[i].first);
//        }
//        // Sorts the vector of distances
//        sort(dist.begin(), dist.end());
//        vector<ve> sortedPairs;
//        //Stores the stored distances back in to a pair vector that cointains
//        //The pointed verticy
//        for(unsigned int i = 0; i < dist.size(); i++)
//        {
//            unsigned int a = 0;
//            while(dist[i] != s->adj[a].first) // change to while
//            {
//                a++;
//            }
//            sortedPairs.push_back(s->adj[a]);
//            qDebug() << sortedPairs[a].first << sortedPairs[a].second;
//        }
//        unsigned int a = 0;
//        bool escape;
//        next = sortedPairs[a].second;
//        // Will set escape based off of if the next name is in the list or not
////        escape = (find(accessed.begin(), accessed.end(),next->name) != accessed.end());

//        // Runs through a loop while the next element has not been found
//        while(escape != false)
//        {
//            a++;
//            if(a < sortedPairs.size())
//            {
//                next = sortedPairs[a].second;
////                escape = (find(accessed.begin(), accessed.end(),next->name)
////                        != accessed.end());
//            }
//            else
//            {
//                escape = false;
//            }
//        }

//        // Will check if the program needs to backtrack
//        if(a >= sortedPairs.size() && accessed.size() != NUM_TEAMS)
//        {
//            if(position != -1)
//            {
//                position --;
////                s = (work.find(accessed[position])->second);
//            }
//        }
//        // Stores the next location to be visited
//        else
//        {
//            s = next;
//            if(accessed.size() != NUM_TEAMS)
//            {
//                accum += sortedPairs[a].first;
//                discovery.push_back(sortedPairs[a].first);
//            }
//        }
//    }

//    qDebug() << "This is the total trip distance: " << accum;

//    // outputs the discovery edges
//    qDebug() << endl << endl << "The discovery edges are distances:\n";
//    for(unsigned int i = 0; i < discovery.size(); i ++)
//    {
//        vector<int>::iterator itr;
//        itr = edges.begin();
//        int a = 0;
//        while(discovery[i] != edges[a])
//        {
//            a++;
//            itr++;
//        }
//        edges.erase(itr);
//    }
//    // outputs the back edges
//    qDebug() << endl << "The back edges are distances:\n";
//    for(unsigned int i = 0; i < edges.size(); i ++)
//    {
//    }
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
    getGraph("San Francisco Giants", unsortedStadiums, graph);
    int level = 0;

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

    dfsbfs::BFS(bfsStart, plannedStadiums);
//    dfsbfs::DFS(dfsStart, plannedStadiums);


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
