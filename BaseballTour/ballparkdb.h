#ifndef BALLPARKDB_H
#define BALLPARKDB_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "mainwindow.h"

namespace Ui {
class BallparkDB;
}

/*!
 * \brief The addsouvenir class: dialog for adding souvenirs
 *
 * tt
 */
class BallparkDB : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase mydb;

    bool connOpen()
    {
        QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName(QCoreApplication::applicationDirPath() + "/databases/MLBinfo.db");
        //mydb.setDatabaseName("C:/Users/mered/OneDrive/Desktop/WhoIsYourDatabase-initial-ui (1)/WhoIsYourDatabase-initial-ui/BaseballTour/databases");
        return mydb.open();
    }


    void connClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }



};

#endif // BALLPARKDB_H
