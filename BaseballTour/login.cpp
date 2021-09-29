#include "login.h"
#include "ui_login.h"
#include "admin.h"

#include <QMessageBox>
#include <QObject>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_Login_clicked()
{
    //valid username and password.
    QString username = "admin";
    QString password = "password";

    //If username or password is empty, there is a warning message.
    if(ui->userName->text() == "" || ui->passWord->text()== "")
    {
        QMessageBox::warning(this, "Empty!", "Please fill in all fields");
    }
    else
    {
        if(ui->userName->text() == username && ui->passWord->text() == password)
        {
            //returns signal to hide mainwindow
            accepted();
            admin *ad = new admin;
            ad->show();

            QObject::connect(ad, SIGNAL(accepted()),this,SLOT(reject()));
            QObject::connect(ad, SIGNAL(accepted()), ad, SLOT(deleteLater()));
        }
        else
        {
            QMessageBox::critical(this, "Error", "Invalid Login");
        }
    }
}
