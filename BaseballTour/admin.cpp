#include "admin.h"
#include "ui_admin.h"
#include "mainwindow.h"

#include <QObject>
#include <QDebug>
#include <QMessageBox>
admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}

void admin::on_edit_cities_clicked()
{

}

void admin::on_edit_food_clicked()
{

}
