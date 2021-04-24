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

class BallparkDB : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase mydb;

    bool connOpen()
    {
        QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName(QCoreApplication::applicationDirPath() + "/databases/MLBinfo.db");

        return mydb.open();
    }


    void connClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }



};

#endif // BALLPARKDB_H
