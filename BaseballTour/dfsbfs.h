#ifndef DFSBFS_H
#define DFSBFS_H

#include <QDialog>
#include <QString>
#include <QtAlgorithms>
#include <vector>
#include <map>
#include <iostream>
#include "stadiumstructs.h"
#include <iomanip>
#include <QString>
#include <map>
#include <list>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <iterator>
#include <string>
#include <queue>
#include <deque>
#include <functional>
#include <bits/stdc++.h>

using namespace std;

using namespace std;
namespace Ui {
class dfsbfs;
}

class dfsbfs : public QDialog
{
    Q_OBJECT

public:

    explicit dfsbfs(QWidget *parent = nullptr);
    ~dfsbfs();

    void BFS(int start);
    struct vertex;
    struct visited;
    typedef pair<int, vertex*> ve;

    typedef map<string, vertex *> vmap;
    vmap work;
    struct visited
    {
        QString name;
        QString color;
    };
    struct vertex {
        vector<ve> adj; //cost of edge, destination vertex
        QString name;
        vertex(QString s) : name(s) {}
    };


        void addvertex(const QString&);
        void addedge(const QString& from, const QString& to, double dist);
        int DFS(int start, std::vector<StadiumInfo> unsortedStadiums, bool visited[31][31], int adj[31][31]);

        void BFS(int start, std::vector<StadiumInfo> unsortedStadiums);

        std::vector<StadiumInfo> allStadiums;
        std::vector<StadiumInfo> plannedStadiums;
        std::vector<StadiumInfo> sortStadiums(QString startingStadium, std::vector<StadiumInfo> unsortedStadiums);


private slots:
        void on_pushButton_clicked();

private:
    Ui::dfsbfs *ui;

};

#endif // DFSBFS_H
