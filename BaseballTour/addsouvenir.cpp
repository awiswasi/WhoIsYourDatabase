#include "addsouvenir.h"
#include "ui_addsouvenir.h"
#include <QTimer>
#include <QDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtSql>
#include <QSqlDatabase>
#include "ballparkdb.h"

addsouvenir::addsouvenir(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addsouvenir)
{
    ui->setupUi(this);


}

addsouvenir::~addsouvenir()
{
    delete ui;
}
void addsouvenir::setData(QString arg1)
{
    currentTeam = arg1;
}
void addsouvenir::on_addSouvenirButton_clicked()
{
    QString souvenirName, price;
    souvenirName =ui->souvenirNameText->text();
    price =ui->souvenirPriceText->text();

    bool ok;
    price.toDouble(&ok);

    if(!ok){

        QMessageBox msgBox;
        msgBox.setText("Invalid Price.");
        msgBox.exec();
        return;
    }


    QString changes;
    changes.append("insert into \"" + currentTeam + "\" (souvenir, price) values ('"+souvenirName+"', '"+price+"')");

    BallparkDB conn;
    conn.connOpen();

    qDebug() << changes;

    QSqlQuery update;
    update.prepare(changes);

    if(update.exec()){
        QMessageBox msgBox;
        msgBox.setText("Added " + souvenirName);
        msgBox.exec();
    }else{
        qDebug()<<"Something went wrong";
        qDebug()<<"ERROR! " << update.lastError();
    }

    conn.connClose();


}




void addsouvenir::on_deleteButton_clicked()
{
    BallparkDB conn;
    conn.connOpen();
    QSqlQuery query;

    QString souvenirName = ui->comboBox->currentText();

    query.prepare("DELETE FROM \"" + currentTeam + "\" WHERE souvenir = '" + souvenirName + "'");
    query.exec();

    qDebug() << souvenirName << currentTeam;

}

void addsouvenir::on_cancelButton_clicked()
{
    qDebug() << currentTeam;
    this->close();
}

void addsouvenir::on_connectButton_clicked()
{

    BallparkDB conn;
    conn.connOpen();
    QSqlQuery query;

    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery(conn.mydb);
    QString idk;
    idk.append("select * from \"" + currentTeam +"\"");
    qry->prepare(idk);

    qDebug() << idk;
    qDebug() << currentTeam;
    qry->exec();

    modal->setQuery(*qry);
    ui->comboBox->setModel(modal);

}


void addsouvenir::on_editSouvenirButton_clicked()
{
    QString price =ui->souvenirPriceText->text();
    bool ok;
    price.toDouble(&ok);

    if(!ok){
        QMessageBox msgBox;
        msgBox.setText("Invalid Price.");
        msgBox.exec();
        return;
    }
    if(ui->souvenirNameText->text() == ""){
        ui->souvenirNameText->setText(ui->comboBox->currentText());
    }
    on_deleteButton_clicked();
    on_addSouvenirButton_clicked();
}
