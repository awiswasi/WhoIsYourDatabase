#ifndef SHOWMST_H
#define SHOWMST_H
#include <QString>
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSql>
#include <queue>
#include <vector>
#include <map>
#include <list>
#include <iostream>
#include <string>

using namespace std;
typedef pair<string, string> sPair;
typedef pair<int, string> isPair;

namespace Ui {
class showMST;
}

class showMST : public QDialog
{
    Q_OBJECT

public:
    explicit showMST(QWidget *parent = nullptr);
    ~showMST();
    std::map<string, list<isPair>> adj;
    void addEdge(string u, string v, int w);
    //// prints shortest path from s
    void shortestPath(string s);
    //// prints MST from s
    void mst(string s);


private slots:
    void on_pushButton_clicked();

private:
    Ui::showMST *ui;
};


#endif // SHOWMST_H
