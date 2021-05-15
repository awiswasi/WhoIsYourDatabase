#include "planyourtrip.h"
#include "ui_planyourtrip.h"

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
    takeTrip = new takeyourtrip(this);
    takeTrip->show();
}


void planyourtrip::on_button_CustomTrip_clicked()
{
    takeTrip = new takeyourtrip(this);
    takeTrip->show();
}

