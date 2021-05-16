//#include "triptake.h"
//#include "ui_triptake.h"
//#include "qdebug.h"

//TripTake::TripTake(std::vector<College> inColleges, QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::TripTake)
//{
//    setWindowFlag(Qt::WindowContextHelpButtonHint,false);

//    ui->setupUi(this);
//    // Set table properties (resize to contents, fill the widget with last section, prevent editing)
//    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

//    currCol = -1;



////    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

////    ui->tableWidget->insertRow ( ui->tableWidget->rowCount() );
////    ui->tableWidget->insertRow ( ui->tableWidget->rowCount() );

//ui->tableWidget->insertColumn ( ui->tableWidget->columnCount() );
//ui->tableWidget->setColumnWidth(0, 100);
//ui->tableWidget->setColumnWidth(1, 275);
//ui->tableWidget->setColumnWidth(2, 65);
//ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


////    connect(ui->tableWidget,SIGNAL(cellDoubleClicked(int, int)), this, SLOT(on_purchase(int, int)));            // change to button?
//    connect(ui->buyButton,SIGNAL(pressed()), this, SLOT(on_purchase()));

//    colleges = inColleges;
//    currentCollege = 0;

//    ui->label->setText(QString::fromStdString(colleges[currentCollege].getName()));
/////////////////////////////////////////////////////////////////////////////////////////////////////////TABLE///////////////////////////////////////////////////////////


//    if (int(colleges.size()) < currentCollege || currentCollege < 0){
//        ui->tableWidget->clear();
//        return;
//    }
//    if (int(colleges.size()) < currentCollege || currentCollege < 0){
//        ui->tableWidget->clear();
//        return;
//    }
//    ui->tableWidget->clear();
//    int skipped = 0;
//    for(int i = 0; i < 7; i++){
//        if(QString::fromStdString(colleges.at(currentCollege).getSouvenir(i).souvenir) == "a" || QString::fromStdString(colleges.at(currentCollege).getSouvenir(i).souvenir) == "\r" || QString::fromStdString(colleges.at(currentCollege).getSouvenir(i).souvenir) == ""){
//            skipped++;
//        }else{

//        if(i+skipped < 7){
//            QTableWidgetItem *s = new QTableWidgetItem(QString::fromStdString(colleges.at(currentCollege).getSouvenir(i+skipped).souvenir));
//            QTableWidgetItem *c = new QTableWidgetItem("$" + QString::number(colleges.at(currentCollege).getSouvenir(i+skipped).cost));
//            s->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled );
//            c->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);



////        ui->tableWidget->setItem(i,1, new QTableWidgetItem(QString::fromStdString(colleges.at(currentCollege).getSouvenir(i+skipped).souvenir)));
////        ui->tableWidget->setItem(i,0, new QTableWidgetItem("$" + QString::number(colleges.at(currentCollege).getSouvenir(i+skipped).cost)));

//            ui->tableWidget->setItem(i,1, s);
//            ui->tableWidget->setItem(i,0, c);

//        QTableWidgetItem *item = new QTableWidgetItem(QString::number(0));
//        item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled|Qt::ItemIsEditable );

//        ui->tableWidget->setItem(i,2, item);
//        }
//        }

//    }
//    for(int i = 7-skipped; i < 7; i ++){
//        QTableWidgetItem *b0 = new QTableWidgetItem("");
//        b0->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
//        QTableWidgetItem *b1 = new QTableWidgetItem("");
//        b1->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
//        QTableWidgetItem *b2 = new QTableWidgetItem("");
//        b2->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);

//        ui->tableWidget->setItem(i,0, b0);
//        ui->tableWidget->setItem(i,1, b1);
//        ui->tableWidget->setItem(i,2, b2);
//    }
///////////////////////////////////////////////////////////////////////////////////////////////////////TABLE/////////////////////////////////////////////////////////////////

//    currentCollege++;

//    if(currentCollege == int(colleges.size()))
//        ui->nextButton->setVisible(false);
//}

//TripTake::~TripTake()
//{
//    delete ui;
//}

//void TripTake::on_purchase()
//{
//    qDebug() << "PURCHASED\n";
//    QString numStr;
//    int num;
//    int numbers[7];
////    for(int i = 0; i < 7; i++){


//        for (int i = 0; i < ui->tableWidget->rowCount(); i++)
//        {

//            numStr = ui->tableWidget->item(i,2)->text();
//qDebug() << numStr;
//            num = numStr.toInt();

//            numbers[i] = num;
//        }

//        for(int i = 0; i < 7; i++){
//            if(numbers[i] > 0){
//                for(int j = 0; j < numbers[i]; j++){
//                    colleges.at(currentCollege-1).purchase(colleges.at(currentCollege-1).getSouvenir(i));

//                }
//            }
//            qDebug() << numbers[i];
//        }

////    }

////    colleges.at(currentCollege-1).purchase(colleges.at(currentCollege-1).getSouvenir(row));
//}

//void TripTake::on_nextButton_clicked()
//{
//    currCol++;

//    if (int(colleges.size()) <= currentCollege || currentCollege < 0){          // Print the last Totals Screen
//        ui->traveledD->setVisible(false);
//        ui->label_2->setVisible(false);

//        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
//        ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
//        double grandTotal = 0;
//        int totalSouvenirs = 0;
//        ui->tableWidget->clear();
//        ui->nextButton->setVisible(false);
//        ui->tableWidget->setMinimumSize(650,450);
//        ui->label->setText("Souvenir Purchases");
//        ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("End Trip");
//        ui->buyButton->setVisible(false);
//        ui->tableWidget->setMinimumWidth(ui->tableWidget->width()+50);

//        ui->tableWidget->removeColumn(2);

//        for (int i = 0; i < colleges.size(); i++){
//            if(i == ui->tableWidget->rowCount()){
//                ui->tableWidget->insertRow ( ui->tableWidget->rowCount() );
//            }

//            ui->tableWidget->setItem( i, 0, new QTableWidgetItem(QString::fromStdString(colleges.at(i).getName())));
//            ui->tableWidget->setItem( i, 1, new QTableWidgetItem(QString::number(colleges.at(i).getNumPurchased()) + " for $" + QString::number(colleges.at(i).getTotalSpent())));
//            grandTotal += colleges.at(i).getTotalSpent();
//            totalSouvenirs += colleges.at(i).getNumPurchased();
//            // repeat for more columns
//        }

//        ui->tableWidget->insertRow ( ui->tableWidget->rowCount() );
//        ui->tableWidget->insertRow ( ui->tableWidget->rowCount() );

//        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem("Grand Total"));
//        ui->tableWidget->setItem( ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(QString::number(totalSouvenirs) + " for $" + QString::number(grandTotal)));

//        ui->tableWidget->insertRow ( ui->tableWidget->rowCount() );
//        ui->tableWidget->insertRow ( ui->tableWidget->rowCount() );

//        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem("Total Distance Traveled: "));
//        ui->tableWidget->setItem( ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(QString::number(totalDistance)));
//        if(totalDistance==0){
//            ui->tableWidget->removeRow(ui->tableWidget->rowCount()-1);
//            ui->tableWidget->removeRow(ui->tableWidget->rowCount()-1);

//    }
//        return;
//    }


//    if(currCol!=colleges.size()-1)
//        totalDistance += colleges.at(currCol).distanceTraveled;

//    ui->traveledD->clear();
//    ui->traveledD->setText(QString::number(totalDistance) + " miles");


/////////////////////////////////////////////////////////////////////////////////////////////////////////TABLE///////////////////////////////////////////////////////////

//    ui->label->setText(QString::fromStdString(colleges[currentCollege].getName()));

//        if (int(colleges.size()) < currentCollege || currentCollege < 0){
//            ui->tableWidget->clear();
//            return;
//        }
//        if (int(colleges.size()) < currentCollege || currentCollege < 0){
//            ui->tableWidget->clear();
//            return;
//        }
//        ui->tableWidget->clear();
//        int skipped = 0;
//        for(int i = 0; i < 7; i++){
//            if(QString::fromStdString(colleges.at(currentCollege).getSouvenir(i).souvenir) == "a" || QString::fromStdString(colleges.at(currentCollege).getSouvenir(i).souvenir) == "\r" || QString::fromStdString(colleges.at(currentCollege).getSouvenir(i).souvenir) == ""){
//                skipped++;
//            }else{

//            if(i+skipped < 7){
//                QTableWidgetItem *s = new QTableWidgetItem(QString::fromStdString(colleges.at(currentCollege).getSouvenir(i+skipped).souvenir));
//                QTableWidgetItem *c = new QTableWidgetItem("$" + QString::number(colleges.at(currentCollege).getSouvenir(i+skipped).cost));
//                s->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled );
//                c->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);



//    //        ui->tableWidget->setItem(i,1, new QTableWidgetItem(QString::fromStdString(colleges.at(currentCollege).getSouvenir(i+skipped).souvenir)));
//    //        ui->tableWidget->setItem(i,0, new QTableWidgetItem("$" + QString::number(colleges.at(currentCollege).getSouvenir(i+skipped).cost)));

//                ui->tableWidget->setItem(i,1, s);
//                ui->tableWidget->setItem(i,0, c);

//            QTableWidgetItem *item = new QTableWidgetItem(QString::number(0));
//            item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled|Qt::ItemIsEditable );

//            ui->tableWidget->setItem(i,2, item);
//            }
//            }

//        }
//        for(int i = 7-skipped; i < 7; i ++){
//            QTableWidgetItem *b0 = new QTableWidgetItem("");
//            b0->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
//            QTableWidgetItem *b1 = new QTableWidgetItem("");
//            b1->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
//            QTableWidgetItem *b2 = new QTableWidgetItem("");
//            b2->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);

//            ui->tableWidget->setItem(i,0, b0);
//            ui->tableWidget->setItem(i,1, b1);
//            ui->tableWidget->setItem(i,2, b2);
//        }
//    /////////////////////////////////////////////////////////////////////////////////////////////////////TABLE/////////////////////////////////////////////////////////////////


//    currentCollege++;

//    if(currentCollege == int(colleges.size()))
//        ui->nextButton->setText("View Summary");
//}
