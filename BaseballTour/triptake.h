#ifndef TRIPTAKE_H
#define TRIPTAKE_H

#include <QDialog>
#include <vector>
#include "stadiumstructs.h"

namespace Ui {
class TripTake;
}

class TripTake : public QDialog
{
    Q_OBJECT

public:
    explicit TripTake(std::vector<StadiumInfo> INPUTSTADIUMS, QWidget *parent = nullptr);
    ~TripTake();

private slots:
    void on_push_next_clicked();

    void on_buyButton_clicked();

private:
    std::vector<StadiumInfo> stadiums;
    Ui::TripTake *ui;
    int currentStadium = 0;
    double grandTotal = 0;
    int totalSouvenirs = 0;
};

#endif // TRIPTAKE_H
