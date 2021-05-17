#ifndef CUSTOMTRIP_H
#define CUSTOMTRIP_H

#include <QDialog>
#include "stadiumstructs.h"
#include "triptake.h"
#include "tripplan.h"

namespace Ui {
class CustomTrip;
}

class CustomTrip : public QDialog
{
    Q_OBJECT

public:
    explicit CustomTrip(const QString START, QWidget *parent = nullptr);
    ~CustomTrip();

private slots:
    void on_buttonBox_accepted();

    void on_pushButton_clicked();

private:
    Ui::CustomTrip *ui;
//    std::vector<StadiumInfo> sortStadiums(int startingStadium, std::vector<Stadium> StadiumsLeft, std::vector<Stadium> StadiumsDone, std::vector<int> doneIndexes);

    std::vector<StadiumInfo> displayStadiums;
    std::vector<StadiumInfo> foundStadiums;
    std::vector<StadiumInfo> allStadiums;

    std::vector<StadiumInfo> alreadyDoneStadiums;
    QString startingStadium;
    int removedStadiumCount;

    int minimumDist(int dist[], bool Tset[], int max);
    static bool sortByVal(const std::pair<int, int> &a, const std::pair<int, int> &b);
    std::vector<StadiumInfo> sortStadiums(QString startingStadium, std::vector<StadiumInfo> unsortedStadiums);
};

#endif // CUSTOMTRIP_H
