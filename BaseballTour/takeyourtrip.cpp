#include "takeyourtrip.h"
#include "ui_takeyourtrip.h"

takeyourtrip::takeyourtrip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::takeyourtrip)
{
    ui->setupUi(this);
}

takeyourtrip::~takeyourtrip()
{
    delete ui;
}
