#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ballparkdb.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QtDebug>
#include <QFile>
#include <QFileDialog>
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QWidget>
#include <QMessageBox>
#include <QSortFilterProxyModel>
#include "logindialog.h"
#include "addsouvenir.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QTableWidget>
#include <iostream>
#include "editteam.h"
#include "tripplan.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    BallparkDB conn;

    if(!conn.connOpen())
    {
        ui->label_dbstatus->setText("Put DB's in build/databases/ folder");
        qDebug() << "Put databases in " << QString(QCoreApplication::applicationDirPath()) << " / databases/";
    }
    else
        ui->label_dbstatus->setText("Database connected");
    QSqlQueryModel * modal = new QSqlQueryModel();

   // conn.connOpen();
    QSqlQuery * qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from _MLBinfo");
    qry->exec();

    modal->setQuery(*qry);

    ui->tableView->setModel(modal);
    ui->combo_team->setModel(modal);
    int row = 0;
    while(qry->next () == true)
    {
        row++;
    }
    int total = 0;
    QString str;
    for(int i = 0; i < row + 1; i++)
    {
        total += modal->record(i).value(2).toInt();
    }
    str = QString::number(total);
    ui->capacityLabel->setText(str);

    // DISTANCES
    // ==========================================================================================================
    DistanceInfo tempdist;
    DistanceInfo tempvert;


    qry->prepare("select * from _DISTANCES");
    qry->exec();

    int count = 0;


     // Reading in edges
    while(qry->next()) //these seem to be coming out in alphabetical order by default
    {
        tempdist.startStad = qry->value(0).toString();
        tempdist.endStad = qry->value(1).toString();
        tempdist.distance = qry->value(2).toInt();
        distances.push_back(tempdist);
        count++;
    }
    // ADDING VERTEX
    while(qry->next())
    {
        tempvert.startStad = qry->value(0).toString();
    }

    conn.connClose();

    this->statusBar()->setSizeGripEnabled(false);


    ui->actionLog_Out->setEnabled(false);

    ui->addButton->setVisible(false);
    ui->saveButton->setVisible(false);
    ui->editButton->setVisible(false);
    ui->addSouvenirButton->setVisible(false);
    ui->tableView->resizeColumnsToContents();

}

MainWindow::~MainWindow()
{
    delete ui;
}
/***********************
 * COMBO BOX FUNCTIONS *
 ***********************/
void MainWindow::on_combo_sort_activated(const QString &arg1)
{

    BallparkDB conn;
    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery(conn.mydb);

    // QMessageBox::information(this, "Title", ui->combo_sort->currentText());
     if(ui->combo_sort->currentText() == "Team")
     {
             qry->prepare("select * from _MLBinfo order by teamName");
     }
     else if (ui->combo_sort->currentText() == "Stadium")
     {
             qry->prepare("select * from _MLBinfo order by stadiumName");
     }
     else if (ui->combo_sort->currentText() == "Typology")
     {
             qry->prepare("select * from _MLBinfo order by ballparkTypology");
     }
     else if (ui->combo_sort->currentText() == "Stadium Age")
     {
              qry->prepare("select * from _MLBinfo order by dateOpened");
     }
     else if (ui->combo_sort->currentText() == "Capacity")
     {
             qry->prepare("select * from _MLBinfo order by seatingCapacity");
     }
     else if (ui->combo_sort->currentText() == "Location")
     {
           qry->prepare("select * from _MLBinfo order by location");
     }
     else if (ui->combo_sort->currentText() == "Surface")
     {
        qry->prepare("select * from _MLBinfo order by playingSurface");
     }
     else if (ui->combo_sort->currentText() == "League")
     {
        qry->prepare("select * from _MLBinfo order by league");
     }
     else if (ui->combo_sort->currentText() == "Center Field")
     {
         qry->prepare("select * from _MLBinfo order by distanceToCenter");
     }
     else
     {
        qry->prepare("select * from _MLBinfo order by roofType");
     }
     qry->exec();
     modal->setQuery(*qry);
     ui->tableView->setModel(modal);
     conn.connClose();
     //ignore this
}
void MainWindow::on_combo_team_activated(const QString &arg1)
{
    BallparkDB conn;
    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery(conn.mydb);

    if(ui->combo_team->currentText() == "Arizona Diamondbacks")
   {

        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'Arizona Diamondbacks'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Boston Red Sox")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'Boston Red Sox'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Baltimore Orioles")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'Baltimore Orioles'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Atlanta Braves")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'Atlanta Braves'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Chicago White Sox")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'Chicago White Sox'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Chicago Cubs")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'Chicago Cubs'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Cincinnati Reds")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'Cincinnati Reds'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Milwaukee Brewers")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'Milwaukee Brewers'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Miami Marlins")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'Miami Marlins'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Los Angeles Dodgers")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'Los Angeles Dodgers'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Los Angeles Angels")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'Los Angeles Angels'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Kansas City Royals")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'Kansas City Royals'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Houston Astros")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'Houston Astros'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Detroit Tigers")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'Detroit Tigers'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Colorado Rockies")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'Colorado Rockies'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Cleveland Indians")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'Cleveland Indians'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Washington Nationals")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'Washington Nationals'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Toronto Blue Jays")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'Toronto Blue Jays'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Texas Rangers")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'Texas Rangers'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "St.Louis Cardinals")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'St.Louis Cardinal'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Seattle Mariners")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'Seattle Mariners'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "San Francisco Giants")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'San Francisco Giants'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "San Diego Padres")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'San Diego Padres'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Pittsburgh Pirates")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'Pittsburgh Pirates'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Philadelphia Phillies")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'Philadelphia Phillies'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Oakland Athletics")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'Oakland Athletics'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "New York Yankees")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'New York Yankees'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "New York Mets")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'New York Mets'");;
        qry->exec();
    }
    else
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where teamName = 'Minnesota Twins'");;
        qry->exec();
    }
    modal->setQuery(*qry);
    QSortFilterProxyModel *m = new QSortFilterProxyModel(this);
    m->setSourceModel(modal);
    ui->tableView->setModel(m);
    ui->tableView->setSortingEnabled(true);
    conn.connClose();

}
/******************************
 *  Mutator Functions
 * ****************************/
void MainWindow::setName(QString teamName)
{
    team = teamName;
}
void  MainWindow::setStad(QString stadiumName)
{
    stad = stadiumName;
}
void  MainWindow::setCap(QString seatingCapacity)
{
    seat = seatingCapacity;
}
void  MainWindow::setLoc(QString location)
{
    loc = location;
}
void  MainWindow::setDate(QString dateOfOpening)
{
    date = dateOfOpening;
}
void  MainWindow::setDist(QString distanceToCenter)
{
    Center = distanceToCenter;
}
void  MainWindow::setSurface(QString surfaceType)
{
    surface = surfaceType;
}

/******************************
 *  Accessor Functions
 * ****************************/
QString MainWindow::getName()
{
    return team;
}
QString MainWindow::getStad()
{
    return stad;
}
QString MainWindow:: getCap()
{
    return seat;
}
QString MainWindow::getLoc()
{
    return loc;
}
QString MainWindow::getDate()
{
    return date;
}
QString MainWindow::getDist()
{
    return Center;
}
QString MainWindow::getSurf()
{
    return surface;
}


void MainWindow::on_tableView_activated(const QModelIndex &index)
{

}

void MainWindow::on_reload_button_clicked()
{
    ui->setupUi(this);

    BallparkDB conn;

    if(!conn.connOpen())
    {
        ui->label_dbstatus->setText("Put DB's in build/databases/ folder");
        qDebug() << "Put databases in " << QString(QCoreApplication::applicationDirPath()) << " / databases/";
    }
    else
        ui->label_dbstatus->setText("Database connected");
    QSqlQueryModel * modal = new QSqlQueryModel();

   // conn.connOpen();
    QSqlQuery * qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from _MLBinfo");
    qry->exec();

    modal->setQuery(*qry);

    ui->tableView->setModel(modal);
    ui->combo_team->setModel(modal);

    conn.connClose();
}

void MainWindow::on_Ami_League_Button_clicked()
{
    BallparkDB conn;
    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery(conn.mydb);
    qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where league = 'American' order by teamName ASC");
   //A qry->prepare("select * from _MLBinfo order by teamName");
    qry->exec();
    modal->setQuery(*qry);
    QSortFilterProxyModel *m = new QSortFilterProxyModel(this);
    m->setSourceModel(modal);
    ui->tableView->setModel(m);
    ui->tableView->setSortingEnabled(true);

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
}

void MainWindow::on_Nat_Leagu_Button_clicked()
{
    BallparkDB conn;
    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery(conn.mydb);

     qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from _MLBinfo where league = 'National' order by stadiumName ASC");
    //qry->prepare("select * from _MLBinfo order by stadiumName");
  //  qry->prepare("select * from _MLBinfo where league = 'National' order by teamName");
    qry->exec();
    modal->setQuery(*qry);
    QSortFilterProxyModel *m = new QSortFilterProxyModel(this);
    m->setSourceModel(modal);
    ui->tableView->setModel(m);
    ui->tableView->setSortingEnabled(true);

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
}

void MainWindow::on_Open_Roof_Button_clicked()
{

    BallparkDB conn;

    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery(conn.mydb);
    //QStringList data;
    QString data = " ";

    qry->prepare("select * from _MLBinfo where roofType = 'Open'");
    qry->exec();

    int openRoofTotal = 0;
    QString openRoofStr;

    while(qry->next () == true) {
        openRoofTotal++;
      }
    openRoofStr = QString::number(openRoofTotal);
    ui->openRoofLabel->setText(openRoofStr);

    modal->setQuery(*qry);
    QSortFilterProxyModel *m = new QSortFilterProxyModel(this);
    m->setSourceModel(modal);
    ui->tableView->setModel(m);
    ui->tableView->setSortingEnabled(true);

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
}

void MainWindow::on_pushButton_clicked()
{
    BallparkDB conn;

    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery(conn.mydb);


    qry->prepare("select * from _MLBinfo order by dateOpened");
    qry->exec();

    modal->setQuery(*qry);
    QSortFilterProxyModel *m = new QSortFilterProxyModel(this);
    m->setSourceModel(modal);
    ui->tableView->setModel(m);
    ui->tableView->setSortingEnabled(true);

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
}

void MainWindow::on_actionLogin_triggered()
{
    loginDialog *loginWindow = new loginDialog;
    loginWindow->exec();
    isAdmin = loginWindow->getLoggedIn();

    if (isAdmin)
    {
//        ui->actionAdd_from_file->setEnabled(true);
        ui->actionLog_Out->setEnabled(true);
        ui->addButton->setVisible(true);
        ui->editButton->setVisible(true);
        ui->addSouvenirButton->setVisible(true);
        ui->actionLogin->setEnabled(false);

//        ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
        ui->saveButton->setVisible(true);
    }
    delete loginWindow;
}
void MainWindow::on_actionLog_Out_triggered()
{
    isAdmin = false;
//    ui->actionAdd_from_file->setEnabled(false);
    ui->actionLog_Out->setEnabled(false);
    ui->actionLogin->setEnabled(true);
    ui->addButton->setVisible(false);
//    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->saveButton->setVisible(false);
    ui->editButton->setVisible(false);
    ui->addSouvenirButton->setVisible(false);
}


void MainWindow::on_push_souvenirs_clicked()
{
//    souvenirsDB.open();

//        MainWindow souvenirObj;
//        QSqlQueryModel * model=new QSqlQueryModel();

//        QSqlQuery * qry=new QSqlQuery(souvenirObj.souvenirsDB);
//        qry->prepare("select souvenir, price from souvenirs");

//        qry->exec();

//        model->setQuery(*qry);
//        ui->tableView->setModel(model);

    QSqlTableModel *GetTable = new QSqlTableModel(ui->tableView);

//    QString arg1 = ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0).data().toString();

    QString arg1 = ui->combo_team->currentText();
    qDebug() << arg1;
    //QString test = "Hi";
    //qDebug() << test;
    if (arg1 == "")
        return;

    BallparkDB conn;

    if(!conn.connOpen())
    {
        ui->label_dbstatus->setText("Put DB's in build/databases/ folder");
        qDebug() << "Put databases in " << QString(QCoreApplication::applicationDirPath()) << " / databases/";
    }
    else
        ui->label_dbstatus->setText("Database connected");
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from \"" + arg1 + "\"");
    qry->exec();

    modal->setQuery(*qry);

    ui->tableView->setModel(modal);
    conn.connClose();
}

void MainWindow::on_addSouvenirButton_clicked()
{
    // open a new dialog window to add a souvenir
    QString arg1 = ui->combo_team->currentText();

    addSouvenirs = new addsouvenir(this);
    addSouvenirs->setData(arg1);
    addSouvenirs->show();



}

void MainWindow::on_editButton_clicked()
{
    editTeam *addTeam = new editTeam(this);
    addTeam->show();


//    QSqlTableModel *GetTable = new QSqlTableModel(ui->tableView);

////    QString arg1 = ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0).data().toString();

//    QString arg1 = ui->combo_team->currentText();
//    qDebug() << arg1;
//    QString test = "Hi";
//    qDebug() << test;
//    if (arg1 == "")
//        return;

//    BallparkDB conn;

//    if(!conn.connOpen())
//    {
//        ui->label_dbstatus->setText("Put DB's in build/databases/ folder");
//        qDebug() << "Put databases in " << QString(QCoreApplication::applicationDirPath()) << " / databases/";
//    }
//    else
//        ui->label_dbstatus->setText("Database connected");
//    QSqlQueryModel * modal = new QSqlQueryModel();
//    QSqlQuery * qry = new QSqlQuery(conn.mydb);


//    qry->prepare("select * from \"" + arg1 + "\"");
//    qry->exec();
///////////
//    QString teamName;
//    QString stadiumName;
//    int     seatingCapacity;
//    QString location;
//    QString playingSurface;
//    QString league;
//    int     dateOpened;
//    int     distanceToCenter;
//    QString ballparkTypology;
//    QString roofType;



//    QString changes;
//    changes.append("UPDATE _MLBinfo SET teamName='"+teamName+"', stadiumName='"+stadiumName+"', seatingCapacity='"+seatingCapacity+"', location='"+location+"', playingSurface='"+playingSurface+"', league='"+league+"', dateOpened='"+dateOpened+"', distanceToCenter='"+distanceToCenter+"', ballparkTypology='"+ballparkTypology+"', roofType='"+roofType+"'");


//    QSqlQuery update;
//    update.prepare(changes);

//    if(update.exec()){
//        qDebug()<<"the student is successful update.";
//    }else{
//        qDebug()<<"the student is NOT successful update.";
//        qDebug()<<"ERROR! " << update.lastError();
//    }
/////////////
//    modal->setQuery(*qry);

//    ui->tableView->setModel(modal);


//    conn.connClose();


}


void MainWindow::on_push_plan_clicked()
{
    planTrip = new TripPlan(this);
    planTrip->show();
}


void MainWindow::on_showGreatest_clicked()
{
    BallparkDB conn;
    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from _MLBinfo order by distanceToCenter DESC limit 2");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
}


void MainWindow::on_showSmallest_clicked()
{
    BallparkDB conn;
    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery * qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from _MLBinfo order by distanceToCenter ASC limit 2");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
}
//showMST *mst;

void MainWindow::on_showMSTButton_clicked()
{
    mst = new showMST(this);
    mst->show();
}

//void MainWindow::mst()
//{
//    DistanceInfo tempdist;
//    DistanceInfo tempvert;
//    BallparkDB conn;
//    conn.connOpen();
//    QSqlQuery * qry = new QSqlQuery(conn.mydb);

//    qry->prepare("select * from _DISTANCES");
//    qry->exec();

//    int count = 0;


// // Reading in edges
//    while(qry->next()) //these seem to be coming out in alphabetical order by default
//    {
//        tempdist.startStad = qry->value(0).toString();
//        tempdist.endStad = qry->value(1).toString();
//        tempdist.distance = qry->value(2).toInt();
//        distances.push_back(tempdist);
//        count++;
//    }

//    while(qry->next())
//    {
//        tempvert.startStad = qry->value(0).toString();
//    }

//    conn.connClose();
//}


//void MainWindow::graphmst()
//{
//    vertexCount = 0;

//    // Initializing all city names to a blank space
//    for (int index = 0; index < 32; index++)
//    {
//        vertexList[index] = " ";
//    }


//    // initializing all distances to 0
//    for (unsigned int row = 0; row < 32; row++)
//    {
//        for (unsigned int col = 0; col < 32; col++)
//        {
//            graph[row][col] = 0;
//        }
//    }

//}

//// destructor
//graphmst::~graphmst(){}


//void graphmst::insertEdge(const QString inCity1, const QString inCity2, const int inDistance)
//{
//    int row = 0;
//    int col = 0;
//    bool found = false;


//    // finding where to insert (row should be inCity1, col should be inCity2)
//    while (row < MAX_CITIES && !found)
//    {
//        while (col < MAX_CITIES && !found)
//        {
//            if (vertexList[row] == inCity1 && vertexList[col] == inCity2)
//            {
//                found = true;

//                // stores the distance between i and j
//                graph[row][col] = inDistance;
//                graph[col][row] = inDistance;

//            }
//            else
//            {
//                col++;
//            }
//        }

//        // resetting columns
//        col = 0;

//        if(!found)
//        {
//            row++;
//        }
//    }

//    if (!found)
//    {
//        cout << "\n\nMUST INSERT CITIES FIRST\n\n";
//    }
//}


//void graphmst::insertVertex(const QString inCity)
//{

//    if (vertexCount != MAX_CITIES)
//    {
//        vertexList[vertexCount] = inCity;
//        vertexCount++;
//    }
//    else
//    {
//        cout << "\n\nGraph is full!\n\n";
//    }
//}


//// A utility function to find the vertex with minimum key value, from
//// the set of vertices not yet included in MST
//int graphmst::minKey(int key[], bool mstSet[])
//{
//   // Initialize min value
//   int min = INT_MAX, min_index;

//   for (int v = 0; v < MAX_CITIES; v++)
//   {
//       if (mstSet[v] == false && key[v] < min)
//       {
//           min = key[v], min_index = v;
//       }
//   }


//   return min_index;
//}



//void graphmst::DisplayMST(int parent[], int n, QTextBrowser *inTable)
//{

//        int totalDistance = 0;
//        stringstream ss;

//        ss << left;

//        ss << "Creating MST and printing edges and total mileage...\n\n";
//        ss << "(FORMAT INFORMATION)\n";
//        ss << setw(14) << "Initial City" << "---->  "
//             << setw(14) << "Ending City" << "   - Distance: (Distance between)";
//        ss << "\n\n";


//        for (int index = 1; index < vertexCount; index++)
//        {
//            ss << setw(14) << vertexList[parent[index]].toStdString() << "---->  "
//                 << setw(14) << vertexList[index].toStdString() << "   - Distance: " << graph[parent[index]][index];
//            ss << "\n";

//            totalDistance += graph[parent[index]][index];
//        }

//        ss << "\nTotal Distance: " << totalDistance << endl;


//        ss << right;

//        inTable->setText(QString::fromStdString(ss.str()));
//}


//// Function to construct and print MST for a graph represented using adjacency
//// matrix representation
//void graphmst::primMST(QTextBrowser *inTable)
//{
//     int parent[vertexCount]; // Array to store constructed MST
//     int key[vertexCount];   // Key values used to pick minimum weight edge in cut
//     bool mstSet[vertexCount];  // To represent set of vertices not yet included in MST

//     // Initialize all keys as INFINITE
//     for (int i = 0; i < vertexCount; i++)
//     {
//         key[i] = INT_MAX, mstSet[i] = false;
//     }

//     // Always include first 1st vertex in MST.
//     key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
//     parent[0] = -1; // First node is always root of MST

//     // The MST will have MAX_CITIES vertices
//     for (int count = 0; count < vertexCount-1; count++)
//     {
//        // Pick the minimum key vertex from the set of vertices
//        // not yet included in MST
//        int u = minKey(key, mstSet);

//        // Add the picked vertex to the MST Set
//        mstSet[u] = true;

//        // Update key value and parent index of the adjacent vertices of
//        // the picked vertex. Consider only those vertices which are not yet
//        // included in MST
//        for (int v = 0; v < vertexCount; v++)
//        {
//            // graph[u][v] is non zero only for adjacent vertices of m
//            // mstSet[v] is false for vertices not yet included in MST
//            // Update the key only if graph[u][v] is smaller than key[v]
//           if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
//           {
//              parent[v]  = u, key[v] = graph[u][v];
//           }
//        }

//     }

//     // print the constructed MST
//     DisplayMST(parent, vertexCount, inTable);
//}


//bool graphmst::CityExists(const QString& inCity)
//{
//    bool found = false;
//    int index = 0;

//    while (index < MAX_CITIES && !found)
//    {
//        if (vertexList[index] == inCity)
//        {
//            found = true;
//        }
//        else
//        {
//            index++;
//        }
//    }

//    return found;


//}


//void graphmst::ReadInfo(QVector<DistanceInfo> edgeList)
//{

//    // Reading in city names
//    for (int index = 0; index < edgeList.size(); index++)
//    {
//        if (!CityExists(edgeList[index].startStad))
//        {
//            insertVertex(edgeList[index].startStad);
//        }
//    }




//    // Reading in edges
//    for (int index = 0; index < edgeList.size(); index++)
//    {
//        insertEdge(edgeList[index].startStad, edgeList[index].endStad, edgeList[index].distance);
//    }
//}

void MainWindow::on_DFSBFS_Button_clicked()
{
    dfs = new dfsbfs(this);
    dfs->show();
}
