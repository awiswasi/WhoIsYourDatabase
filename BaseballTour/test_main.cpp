#include "test_main.h"
#include "ui_test_main.h"

test_main::test_main(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::test_main)
{
    ui->setupUi(this);
}

test_main::~test_main()
{
    delete ui;
}
