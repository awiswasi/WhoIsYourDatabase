#ifndef DFSBFS_H
#define DFSBFS_H

#include <QDialog>
#include <QString>
#include <QtAlgorithms>
#include <vector>
#include <map>
#include <iostream>

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


    struct vertex;
    struct visited;
    typedef pair<int, vertex*> ve;

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

        typedef map<string, vertex *> vmap;
        vmap work;
        void addvertex(const QString&);
        void addedge(const QString& from, const QString& to, double dist);
        void DFS(vector<QString> titles, vector<int> edges, QString start);
        void BFS(vector<QString> titles, vector<int> edges, QString start);

private:
    Ui::dfsbfs *ui;

};

#endif // DFSBFS_H
