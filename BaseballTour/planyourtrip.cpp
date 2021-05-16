#include "planyourtrip.h"
#include "ui_planyourtrip.h"
#include "ballparkdb.h"

planyourtrip::planyourtrip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::planyourtrip)
{
    ui->setupUi(this);
}

planyourtrip::~planyourtrip()
{
    delete ui;
}

void planyourtrip::on_button_AutomaticTrip_clicked()
{
//    takeTrip = new takeyourtrip(this);
//    takeTrip->show();
    if(ui->dropdown_CollegeList->currentIndex() == 0)
           return;

    this->close();

//    for (BallparkDB i : plannedColleges)
//    {
//         qDebug() << i.getName().c_str();
//    }

//       takeyourtrip triptake(findRoute(ui->spin_numColleges->value()));
//       triptake.exec();
}


void planyourtrip::on_button_CustomTrip_clicked()
{
    takeTrip = new takeyourtrip(this);
    takeTrip->show();
}

