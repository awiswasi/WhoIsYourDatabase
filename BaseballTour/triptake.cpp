#include "triptake.h"
#include "ballparkdb.h"
#include "stadiumstructs.h"
#include "ui_triptake.h"

TripTake::TripTake(std::vector<StadiumInfo> INPUTSTADIUMS, QWidget *parent) :
    QDialog(parent),
    stadiums(INPUTSTADIUMS),
    ui(new Ui::TripTake)
{
    ui->setupUi(this);

    on_push_next_clicked();
}

TripTake::~TripTake()
{
    delete ui;
}

void TripTake::on_push_next_clicked()
{
    ui->label->setText("Total Spent: ");
    BallparkDB conn;
    conn.connOpen();

    QString selectStatement = QString("select * from\"") + QString(stadiums[currentStadium].teamName) + QString("\"");
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery(conn.mydb);

    qry->prepare(QString(selectStatement));

    if(!qry->exec()){
        qDebug() << qry->lastQuery();
        qDebug() << qry->lastError();}

    modal->setQuery(*qry);

    ui->label_team->setText(stadiums[currentStadium].teamName);
    ui->label_stadium->setText(stadiums[currentStadium].stadiumName);
    ui->label_stadium->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    ui->tableView->setModel(modal);
    ui->tableView->resizeColumnsToContents();
    ui->label_distance->setText(QString::number(stadiums[currentStadium].distanceNeeded));

    ui->comboBox->setModel(modal);
    currentStadium++;

    if(currentStadium >= int(stadiums.size()))
    {
        ui->push_next->hide();
    }

    conn.connClose();

}


void TripTake::on_buyButton_clicked()
{
    BallparkDB conn;
    conn.connOpen();

    QSqlQuery query;

    query.exec("select price from '" +stadiums[currentStadium-1].teamName + "' where souvenir = '" +ui->comboBox->currentText() + "'");
    query.next();

    double price = query.value(0).toDouble();

    qDebug() << "Price = " << price;

    stadiums[currentStadium-1].totalSpent += price * ui->quantitySpinBox->value();

    ui->label->setText("Total Spent: " + QString::number(stadiums[currentStadium-1].totalSpent));

    ui->quantitySpinBox->setValue(0);
    conn.connClose();
}
