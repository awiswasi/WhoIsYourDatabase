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
    ui->tableWidget->setVisible(false);
    on_push_next_clicked();
}

TripTake::~TripTake()
{
    delete ui;
}

void TripTake::on_push_next_clicked()
{
    if (int(stadiums.size()) <= currentStadium || currentStadium < 0 || currentStadium-1 >= int(stadiums.size())){

        currentStadium--;
        ui->tableWidget->setVisible(true);
        ui->tableView->setVisible(false);

        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
            ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
            ui->tableWidget->clear();
            ui->tableWidget->setMinimumSize(650,450);
            ui->label->setText("Souvenir Purchases");
//            ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("End Trip");
            ui->buyButton->setVisible(false);
            ui->push_next->setVisible(false);
            ui->comboBox->setVisible(false);
            ui->pushButton->setVisible(false);

            ui->quantitySpinBox->setVisible(false);
            ui->label_team->setText("Trip Summary");
            ui->label_stadium->setText("");
            ui->tableWidget->setMinimumWidth(ui->tableWidget->width()+50);


            for (int i = 0; i < stadiums.size(); i++){
                if(i == ui->tableWidget->rowCount()){
                    ui->tableWidget->insertRow ( ui->tableWidget->rowCount() );
                }

                ui->tableWidget->setItem( i, 0, new QTableWidgetItem(stadiums[i].teamName));
                ui->tableWidget->setItem( i, 1, new QTableWidgetItem("$" + QString::number(stadiums[i].totalSpent)));
                // repeat for more columns
            }

            ui->tableWidget->insertRow ( ui->tableWidget->rowCount() );
            ui->tableWidget->insertRow ( ui->tableWidget->rowCount() );

            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem("Grand Total"));
            ui->tableWidget->setItem( ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem("$" + QString::number(grandTotal)));

            ui->tableWidget->insertRow ( ui->tableWidget->rowCount() );
            ui->tableWidget->insertRow ( ui->tableWidget->rowCount() );

            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem("Total Distance Traveled: "));
            ui->tableWidget->setItem( ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(QString::number(stadiums[currentStadium].distanceNeeded)));
            if(stadiums[currentStadium].distanceNeeded==0){
                ui->tableWidget->removeRow(ui->tableWidget->rowCount()-1);
                ui->tableWidget->removeRow(ui->tableWidget->rowCount()-1);

        }
            return;
        }
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

//    if(currentStadium >= int(stadiums.size()))
//    {
//        ui->push_next->hide();
//    }

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

    grandTotal += price * ui->quantitySpinBox->value();
    totalSouvenirs += ui->quantitySpinBox->value();
    ui->quantitySpinBox->setValue(0);
    conn.connClose();
}

void TripTake::on_pushButton_clicked()
{
    while(ui->push_next->isVisible()){
        on_push_next_clicked();
    }
}
