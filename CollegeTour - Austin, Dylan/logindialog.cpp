#include "logindialog.h"
#include "ui_logindialog.h"
#include <QTimer>

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
    //QTimer::singleShot(0, loginButton, SLOT(setFocus))
}

loginDialog::~loginDialog()
{
    delete ui;
}

bool loginDialog::getLoggedIn()
{
    return loggedIn;
}


void loginDialog::on_cancelButton_clicked()
{
    loginDialog::close();
}

void loginDialog::on_loginButton_clicked()
{
    QString username = "admin";
    QString password = "pass";


    QString userInput = ui->userEdit->text();
    QString passInput = ui->passEdit->text();

    if(userInput == username && passInput == password)
    {
     loggedIn = true;
     this->close();
    }
    else
        this->close();
}
