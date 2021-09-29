#include "edit_food.h"
#include "ui_edit_food.h"

edit_food::edit_food(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_food)
{
    ui->setupUi(this);
}

edit_food::~edit_food()
{
    delete ui;
}
