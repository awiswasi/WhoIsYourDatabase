#include "triptake.h"
#include "trip.h"
#include "ui_triptake.h"

triptake::triptake(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::triptake)
{
    ui->setupUi(this);
}

triptake::~triptake()
{
    delete ui;
}


//void triptake::on_back_button_clicked()
//{
////    trip tripp;
////    tripp.setModal(true);
////    tripp.exec();
//}
