#include "edit_cities.h"
#include "ui_edit_cities.h"

edit_cities::edit_cities(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_cities)
{
    ui->setupUi(this);
}

edit_cities::~edit_cities()
{
    delete ui;
}
