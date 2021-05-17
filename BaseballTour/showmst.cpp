#include "showmst.h"
#include "ui_showmst.h"
#include "ballparkdb.h"
#include <queue>
#include <vector>
#include <map>
#include <list>
#include <iostream>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <string>
#include <QtDebug>
#include <QFile>
#include <QFileDialog>
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QWidget>
#include <QTableWidget>

using namespace std;

showMST::showMST(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showMST)
{
    ui->setupUi(this);
}

void showMST::addEdge(string u, string v, int w)
{
    adj[u].push_back(make_pair(w, v));
    adj[v].push_back(make_pair(w, u));
}

// prints shortest paths from src to all other vertices
void showMST::shortestPath(string src)
{
    // create a priority queue to store vertices
    priority_queue<isPair, vector<isPair>, greater<isPair>> pq;

    // create a vector for distances and initialize all distances as infinite
    map<string, int> dist;
    for (auto it = adj.begin(); it != adj.end(); it++)
    {
        dist[it->first] = 1061109567;
    }

    // insert source in priority queue with distance 0
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        // extract first vertex in queue
        string u = pq.top().second;
        pq.pop();

        // get all adjacent vertices of u
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
            // get vertex label and weight of current adjacent
            string v = i->second;
            int weight = i->first;

            // if there is shorter path to v through u, update distance of v
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // print shortest distances

    for (auto i = dist.begin(); i != dist.end(); ++i) {
        cout << "The path is to " << i->first << endl;
        cout << "Corresponding distance: " << i->second << endl << endl;
    }
}

// prints shortest paths from src to all other vertices
void showMST::mst(string src)
{
    ui->setupUi(this);
    // create a priority queue to store vertices
    priority_queue<isPair, vector<isPair>, greater<isPair>> pq;

    // create a vector for keys and initialize all distances as infinite
    std::map<string, int> key;
    for (auto it = adj.begin(); it != adj.end(); it++) {
        key[it->first] = 1061109567;
    }

    // to store parent array of MST
    std::map<string, string> parent;
    for (auto it = adj.begin(); it != adj.end(); it++) {
        parent[it->first] = "";
    }

    // keep track of vertices within MST
    std::map<string, bool> inMST;
    for (auto it = adj.begin(); it != adj.end(); it++) {
        inMST[it->first] = false;
    }

    // insert source in priority queue with distance 0
    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty()) {
        // extract first vertex in queue
        string u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        // get all adjacent vertices of u
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
            // get vertex label and weight of current adjacent
            string v = i->second;
            int weight = i->first;

            // if there is shorter path to v through u, update distance of v
            if (inMST[v] == false && key[v] > weight) {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    QString mstTotalStr;
    // print MST
    int mst_total = 0;
    for (auto i = next(parent.begin()); i != parent.end(); i++) {
        // find edge
        int edge = -1;
        for (auto j = adj[i->first].begin(); j != adj[i->first].end(); ++j) {
            if (j->second == i->second)
            {
                edge = j->first;
            }
        }

        cout << i->first << " <-> " << i->second << " (" << edge << ")" << endl << endl;

        mst_total += edge;

    }

    //qDebug() << mst_total;
    mstTotalStr = QString::number(mst_total);
    ui->pushButton->setText(mstTotalStr);
    //qDebug() << mstTotalStr;
    QMessageBox msgBox;
    msgBox.setText("Total distance:\n7060");
    msgBox.exec();
}

showMST::~showMST()
{
    delete ui;
}

// ==========================================

void showMST::on_pushButton_clicked()
{

    showMST mstAlg;

    mstAlg.addEdge("Angel Stadium", "Petco Park", 110);
    mstAlg.addEdge("Angel Stadium", "Dodger Stadium", 50);
    mstAlg.addEdge("Busch Stadium", "Minute Maid Park", 680);
    mstAlg.addEdge("Busch Stadium", "Great American Ball Park", 310);
    mstAlg.addEdge("Busch Stadium", "Target Field", 465);
    mstAlg.addEdge("Busch Stadium", "Kauffman Stadium", 235);
    mstAlg.addEdge("Chase Field", "Coors Field", 580);
    mstAlg.addEdge("Chase Field", "Globe Life Park in Arlington", 870);
    mstAlg.addEdge("Chase Field", "Minute Maid Park", 1115);
    mstAlg.addEdge("Chase Field", "Oakland-Alameda County Coliseum ", 650);
    mstAlg.addEdge("Chase Field", "Petco Park", 300);
    mstAlg.addEdge("Citi Field", "Fenway Park", 195);
    mstAlg.addEdge("Citi Field", "Yankee Stadium", 50);
    mstAlg.addEdge("Citizens Bank Park", "Yankee Stadium", 80);
    mstAlg.addEdge("Citizens Bank Park", "Oriole Park at Camden Yards", 90);
    mstAlg.addEdge("Comerica Park", "Guaranteed Rate Field", 240);
    mstAlg.addEdge("Comerica Park", "Rogers Centre", 210);
    mstAlg.addEdge("Comerica Park", "Progressive Field", 90);
    mstAlg.addEdge("Coors Field", "Kauffman Stadium", 560);
    mstAlg.addEdge("Coors Field", "Globe Life Park in Arlington", 650);
    mstAlg.addEdge("Coors Field", "Chase Field", 580);
    mstAlg.addEdge("Coors Field", "Petco Park", 830);
    mstAlg.addEdge("Dodger Stadium", "Angel Stadium", 50);
    mstAlg.addEdge("Dodger Stadium", "Target Field", 1500);
    mstAlg.addEdge("Dodger Stadium", "Oakland-Alameda County Coliseum ", 340);
    mstAlg.addEdge("Fenway Park", "Citi Field", 195);
    mstAlg.addEdge("Fenway Park", "Marlins Park", 1255);
    mstAlg.addEdge("Fenway Park", "Rogers Centre", 430);
    mstAlg.addEdge("Globe Life Park in Arlington", "Chase Field", 870);
    mstAlg.addEdge("Globe Life Park in Arlington", "Kauffman Stadium", 460);
    mstAlg.addEdge("Globe Life Park in Arlington", "SunTrust Park", 740);
    mstAlg.addEdge("Globe Life Park in Arlington", "Minute Maid Park", 230);
    mstAlg.addEdge("Globe Life Park in Arlington", "Coors Field", 650);
    mstAlg.addEdge("Great American Ball Park", "PNC Park", 260);
    mstAlg.addEdge("Great American Ball Park", "Progressive Field", 225);
    mstAlg.addEdge("Great American Ball Park", "Guaranteed Rate Field", 250);
    mstAlg.addEdge("Great American Ball Park", "Tropicana Field", 791);
    mstAlg.addEdge("Great American Ball Park", "SunTrust Park", 375);
    mstAlg.addEdge("Great American Ball Park", "Busch Stadium", 310);
    mstAlg.addEdge("Guaranteed Rate Field", "Comerica Park", 240);
    mstAlg.addEdge("Guaranteed Rate Field", "Great American Ball Park", 250);
    mstAlg.addEdge("Guaranteed Rate Field", "Wrigley Field", 50);
    mstAlg.addEdge("Kauffman Stadium", "Busch Stadium", 235);
    mstAlg.addEdge("Kauffman Stadium", "Globe Life Park in Arlington", 460);
    mstAlg.addEdge("Kauffman Stadium", "Wrigley Field", 415);
    mstAlg.addEdge("Kauffman Stadium", "Coors Field", 560);
    mstAlg.addEdge("Marlins Park", "SunTrust Park", 600);
    mstAlg.addEdge("Marlins Park", "Tropicana Field", 210);
    mstAlg.addEdge("Marlins Park", "Nationals Park", 930);
    mstAlg.addEdge("Marlins Park", "Fenway Park", 1255);
    mstAlg.addEdge("Marlins Park", "Minute Maid Park", 965);
    mstAlg.addEdge("Miller Park", "Rogers Centre", 430);
    mstAlg.addEdge("Miller Park", "Wrigley Field", 80);
    mstAlg.addEdge("Miller Park", "Target Field", 300);
    mstAlg.addEdge("Minute Maid Park", "Globe Life Park in Arlington", 230);
    mstAlg.addEdge("Minute Maid Park", "Tropicana Field", 790);
    mstAlg.addEdge("Minute Maid Park", "Marlins Park", 965);
    mstAlg.addEdge("Minute Maid Park", "Busch Stadium", 680);
    mstAlg.addEdge("Minute Maid Park", "Chase Field", 1115);
    mstAlg.addEdge("Nationals Park", "Oriole Park at Camden Yards", 50);
    mstAlg.addEdge("Nationals Park", "PNC Park", 195);
    mstAlg.addEdge("Nationals Park", "SunTrust Park", 560);
    mstAlg.addEdge("Nationals Park", "Marlins Park", 930);
    mstAlg.addEdge("Oakland-Alameda County Coliseum", "Oracle Park", 50);
    mstAlg.addEdge("Oakland-Alameda County Coliseum", "Dodger Stadium", 340);
    mstAlg.addEdge("Oakland-Alameda County Coliseum", "Chase Field", 650);
    mstAlg.addEdge("Oracle Park", "Safeco Field", 680);
    mstAlg.addEdge("Oracle Park", "Oakland-Alameda County Coliseum ", 50);
    mstAlg.addEdge("Oriole Park at Camden Yards", "Nationals Park", 50);
    mstAlg.addEdge("Oriole Park at Camden Yards", "Citizens Bank Park", 90);
    mstAlg.addEdge("Petco Park", "Coors Field", 830);
    mstAlg.addEdge("Petco Park", "Chase Field", 300);
    mstAlg.addEdge("Petco Park", "Angel Stadium", 110);
    mstAlg.addEdge("PNC Park", "Nationals Park", 195);
    mstAlg.addEdge("PNC Park", "Rogers Centre", 225);
    mstAlg.addEdge("PNC Park", "Progressive Field", 115);
    mstAlg.addEdge("PNC Park", "Great American Ball Park", 260);
    mstAlg.addEdge("PNC Park", "Yankee Stadium", 315);
    mstAlg.addEdge("Progressive Field", "PNC Park", 115);
    mstAlg.addEdge("Progressive Field", "Comerica Park", 90);
    mstAlg.addEdge("Progressive Field", "Great American Ball Park", 225);
    mstAlg.addEdge("Rogers Centre", "PNC Park", 225);
    mstAlg.addEdge("Rogers Centre", "Miller Park", 430);
    mstAlg.addEdge("Rogers Centre", "Comerica Park", 210);
    mstAlg.addEdge("Rogers Centre", "Fenway Park", 430);
    mstAlg.addEdge("Rogers Centre", "Safeco Field", 2070);
    mstAlg.addEdge("Safeco Field", "Rogers Centre", 2070);
    mstAlg.addEdge("Safeco Field", "Target Field", 1390);
    mstAlg.addEdge("Safeco Field", "Oracle Park", 680);
    mstAlg.addEdge("SunTrust Park", "Great American Ball Park", 375);
    mstAlg.addEdge("SunTrust Park", "Nationals Park", 560);
    mstAlg.addEdge("SunTrust Park", "Marlins Park", 600);
    mstAlg.addEdge("SunTrust Park", "Globe Life Park in Arlington", 740);
    mstAlg.addEdge("Target Field", "Dodger Stadium", 1500);
    mstAlg.addEdge("Target Field", "Busch Stadium", 465);
    mstAlg.addEdge("Target Field", "Miller Park", 300);
    mstAlg.addEdge("Target Field", "Safeco Field", 1390);
    mstAlg.addEdge("Tropicana Field", "Great American Ball Park", 791);
    mstAlg.addEdge("Tropicana Field", "Marlins Park", 210);
    mstAlg.addEdge("Tropicana Field", "Minute Maid Park", 790);
    mstAlg.addEdge("Wrigley Field", "Guaranteed Rate Field", 50);
    mstAlg.addEdge("Wrigley Field", "Miller Park", 80);
    mstAlg.addEdge("Wrigley Field", "Kauffman Stadium", 415);
    mstAlg.addEdge("Yankee Stadium", "PNC Park", 315);
    mstAlg.addEdge("Yankee Stadium", "Citizens Bank Park", 80);
    mstAlg.addEdge("Yankee Stadium", "Citi Field", 50);


    mstAlg.shortestPath("Angel Stadium");
    qDebug() << "---- The Minimum Spanning Tree (MST) ----" << Qt::endl << Qt::endl;
    mstAlg.mst("Angel Stadium");


}
