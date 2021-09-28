#ifndef TRIP_H
#define TRIP_H

#include <QDialog>
#include "triptake.h"
#include <QTableWidget>
#include <QString>
#include <QApplication>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "db.h"

namespace Ui
{
    class trip;
}

class trip : public QDialog
{
    Q_OBJECT

public:
    explicit trip(QWidget *parent = nullptr);
   // QSqlDatabase mydb;
    ~trip();

private slots:
    void on_button_AutomaticTrip_clicked();

    void on_dropdown_CollegeList_activated(const QString &arg1);

private:
    Ui::trip *ui;
    triptake *trp;
};

#endif // TRIP_H


