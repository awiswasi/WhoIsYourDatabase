#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSortFilterProxyModel>
#include <QString>
#include <QApplication>
#include <QtSql>
#include <QMap>
#include <QMessageBox>
#include "dbmanager.h"
#include "stadiumstructs.h"
#include "graph.h"
#include "graphmst.h"
#include <QTableWidget>
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "addsouvenir.h"
#include "planyourtrip.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

enum pages
{
    LOGIN = 0,
    HOME  = 1,
    STADIUMS = 2,
    SOUVENIRS = 3,
    TEAM_INFO = 4,
    TRIP = 5,
    PURCHASE = 6,
    CONFIRM = 7,
    ADMIN = 8
};

class MainWindow : public QMainWindow
{
        Q_OBJECT
    private slots:
    //    void displaySouvenirs(int index);
    //    void editSouvenirs(int index);

        void on_actionLogin_triggered();

        void on_actionLog_Out_triggered();

        //void onactionAdd_from_file_triggered();

        //    void on_addButton_clicked();

        //    void on_saveButton_clicked();

     //    void on_actionSave_triggered();

        void on_push_souvenirs_clicked();

        void on_addSouvenirButton_clicked();


        void on_combo_sort_activated(const QString &arg1);
        void on_combo_team_activated(const QString &arg1);

        void on_tableView_activated(const QModelIndex &index);

        void on_reload_button_clicked();

        void on_Ami_League_Button_clicked();

        void on_Nat_Leagu_Button_clicked();

        void on_Open_Roof_Button_clicked();

        void on_pushButton_clicked();
        bool Find(QString stadium)
            {
                int i = 0;
                bool found = false;

                while(!found && i < stadiumsToVisit.size())
                {
                    if(stadiumsToVisit[i].stadiumName == stadium)
                    {
                        found = true;
                    }

                    i++;
                }

                return found;
            }
        QString FindTeam(QString stadium)
            {
                int i = 0;
                bool found = false;
                QVector<StadiumInfo> temp = thisDatabase.sortedByTeamStadium("Stadium");
                while(!found && i < temp.size())
                {
                    if(temp[i].stadiumName == stadium)
                    {
                        found = true;

                        return temp[i].teamName;
                    }

                    i++;
                }

                return "N/A";
            }
        QVector<CurrLocal> InsertionSort(QVector<CurrLocal> stadiums)
            {
                int indexCurrent;
                int indexCheck;
                CurrLocal tempLargerCheck;

                /**********************************************************************
                 * PROCESSING
                 * 	- indexCurrent starts as 1 and is incremented after each loop
                 * 	  iteration
                 * 	- tempLargerCheck becomes the value at stadiums[indexCurrent]
                 * 	- indexCheck becomes (indexCurrent - 1)
                 * 	- then a while loop that swaps the values in the two index numbers
                 * 	  loops as long as the value of indexCheck >= 0 & the value of the
                 * 	  element of indexCheck is bigger than the value of tempLargerCheck
                 *  - if the conditions for the while loop are not met, then the element
                 *    of [indexCheck + 1] becomes tempLargerCheck
                 *  - then the for loop iterates again until it reaches the end of the
                 *    array.
                 **********************************************************************/
                for(indexCurrent = 1; indexCurrent < stadiums.size(); indexCurrent++)
                {
                    tempLargerCheck = stadiums[indexCurrent];
                    indexCheck = indexCurrent - 1;

                    while(indexCheck >= 0 && stadiums[indexCheck].totDistance > tempLargerCheck.totDistance)
                    {
                        stadiums[indexCheck + 1] = stadiums[indexCheck];
                        indexCheck = indexCheck - 1;
                    }

                    stadiums[indexCheck + 1] = tempLargerCheck;
                }

                return stadiums;
            }



            QVector<CurrLocal> InsertionSort2(QVector<int> distances)
            {
                int indexCurrent;
                int indexCheck;
                int tempLargerCheck;
                QVector<CurrLocal> dists;
                /**********************************************************************
                 * PROCESSING
                 * 	- indexCurrent starts as 1 and is incremented after each loop
                 * 	  iteration
                 * 	- tempLargerCheck becomes the value at stadiums[indexCurrent]
                 * 	- indexCheck becomes (indexCurrent - 1)
                 * 	- then a while loop that swaps the values in the two index numbers
                 * 	  loops as long as the value of indexCheck >= 0 & the value of the
                 * 	  element of indexCheck is bigger than the value of tempLargerCheck
                 *  - if the conditions for the while loop are not met, then the element
                 *    of [indexCheck + 1] becomes tempLargerCheck
                 *  - then the for loop iterates again until it reaches the end of the
                 *    array.
                 **********************************************************************/
                for(indexCurrent = 1; indexCurrent < distances.size(); indexCurrent++)
                {
                    tempLargerCheck = distances[indexCurrent];
                    indexCheck = indexCurrent - 1;

                    while(indexCheck >= 0 && distances[indexCheck] > tempLargerCheck)
                    {
                        distances[indexCheck + 1] = distances[indexCheck];
                        indexCheck = indexCheck - 1;
                    }

                    distances[indexCheck + 1] = tempLargerCheck;
                }

                for(int i = 0; i < distances.size(); i++)
                {
                    CurrLocal c = {stadiumsToVisit[i].teamName,"",0, 0, double(distances[i]), true};

                    dists.push_back(c);
                }

                return dists;
            }

            bool StadiumVisited(QString stad)
            {
                int i= 0;
                bool found = false;

                while(!found && i < visited.size())
                {
                    if(visited[i] == stad)
                    {
                        found = true;
                    }

                    i++;
                }

                return found;
            }

            bool isSelectedStadium(QString ind)
            {
                int i = 0;
                bool found = false;

                while(!found && i < stadToVisit2.size())
                {
                    if(stadToVisit2[i] == ind)
                        found = true;

                    i++;
                }

                return found;
            }

            CurrLocal FindShortestIndex(int currRow)
            {
                int shortest = 10000000;
                CurrLocal temp;
                for(int i = 1; i < selectDist[currRow].size(); i++)
                {
                    if(selectDist[currRow][i].totDistance < shortest && isSelectedStadium(selectDist[currRow][i].local) && !StadiumVisited(selectDist[currRow][i].local))
                    {
                        shortest = selectDist[currRow][i].totDistance;

                        temp = selectDist[currRow][i];

                    }
                }

                return temp;
            }
            int FindIndexSelectDist(QString stad)
            {
                int i = 0;
                int col = 0;
                int index;
                bool found = false;
                while(!found && i < selectDist.size())
                {
                    if(selectDist[i][col].local == stad){
                        found = true;

                        index = i;
                    }

                    i++;
                }
                return index;
            }

            CurrLocal FindShortestIndexDefault(int currRow)
            {
                int shortest = 10000000;
                CurrLocal temp;
                for(int i = 1; i < selectDist[currRow].size(); i++)
                {
                    if(selectDist[currRow][i].totDistance < shortest && !StadiumVisited(selectDist[currRow][i].local))
                    {
                        shortest = selectDist[currRow][i].totDistance;

                        temp = selectDist[currRow][i];
                    }
                }
                qDebug() << shortest;
                return temp;
            }

            void on_editButton_clicked();


            void on_push_plan_clicked();

            void on_showGreatest_clicked();

            void on_showSmallest_clicked();

private:
        bool isAdmin;
        QString team;
        QString stad;
        QString seat;
        QString loc;
        QString date;
        QString league;
        QString Center;
        QString surface;
        Ui::MainWindow *ui;
        int tripNum = 0;
        int index = 0;
        double grandTotalSpent = 0;
        double totalSpent = 0;
        bool createCol = true;
        int currRow = 0;
        int grandTotalDistance = 0;
        dbManager thisDatabase;
        SouvenirMap souvenirMap;
        QVector<StadiumInfo> stadiumsToVisit;
        QVector<QString> stadfoodItems;
        QVector<CurrLocal> shortestPaths;
        QVector<QString> shortestCust2;
        QVector<QString> stadToVisit2;
        QVector<QString> visited;
        QVector<int> selectInd;
        QVector<QVector<CurrLocal>> selectDist;
        planyourtrip *planTrip;


    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        void PopulateSouvenirTable(const QString teamName, QTableWidget *inTable);
        /******************************
         *  Mutator Functions
         * ****************************/
        void setName(QString teamName);
        void setStad(QString stadiumName);
        void setCap(QString seatingCapacity);
        void setLoc(QString location);
        void setDate(QString dateOfOpening);
        void setDist(QString distanceToCenter);
        void setSurface(QString surfaceType);
        /******************************
         *  Accessor Functions
         * ****************************/
        QString getName();
        QString getStad();
        QString getCap();
        QString getLoc();
        QString getDate();
        QString getDist();
        QString getSurf();
        void createCList();
        QSqlDatabase souvenirsDB;
        addsouvenir *addSouvenirs;

};

#endif // MAINWINDOW_H
