#include "triptake.h"
#include "ballparkdb.h"
#include "stadiumstructs.h"
#include "ui_triptake.h"

TripTake::TripTake(std::vector<StadiumInfo> INPUTSTADIUMS, QWidget *parent) :
    QDialog(parent),
    stadiums(INPUTSTADIUMS),
    ui(new Ui::TripTake)
{
    ui->setupUi(this);

    on_pushButton_clicked();
}

TripTake::~TripTake()
{
    delete ui;
}

void TripTake::on_pushButton_clicked()
{
    ui->label->setText(stadiums[currentStadium++].teamName);

    if(currentStadium >= int(stadiums.size()))
    {
        ui->pushButton->hide();
    }
}

