#include "db.h"
#include "ui_db.h"

db::db(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::db)
{
    ui->setupUi(this);
}

db::~db()
{
    delete ui;
}
