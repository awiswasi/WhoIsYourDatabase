#ifndef TRIPPLAN_H
#define TRIPPLAN_H

#include <QDialog>
#include <QDebug>
#include "stadiumstructs.h"

namespace Ui {
class TripPlan;
}

class TripPlan : public QDialog
{
    Q_OBJECT

public:
    explicit TripPlan(QWidget *parent = nullptr);
    ~TripPlan();

private slots:

    void on_button_AutomaticTrip_clicked();

    void on_button_CustomTrip_clicked();

private:
    Ui::TripPlan *ui;
    int endIndex=0;
    std::vector<StadiumInfo> allStadiums;
    std::vector<StadiumInfo> plannedStadiums;
    std::vector<StadiumInfo> sortStadiums(QString startingStadium, std::vector<StadiumInfo> unsortedStadiums);
};

#endif // TRIPPLAN_H
