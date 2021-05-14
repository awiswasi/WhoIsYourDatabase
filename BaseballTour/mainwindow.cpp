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

    qry->prepare("select * from MLBinfo");
    qry->exec();

    modal->setQuery(*qry);

    ui->tableView->setModel(modal);
    ui->combo_team->setModel(modal);

    conn.connClose();

    this->statusBar()->setSizeGripEnabled(false);

    QSqlDatabase souvenirsDB = QSqlDatabase::addDatabase("QSQLITE");
        souvenirsDB.setDatabaseName("../souvenirs.db");

        souvenirsDB.open();

    // Set table properties (resize to contents, fill the widget with last section, prevent editing)
//    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
//    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
//    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    ui->tableWidget->clear();
//    ui->tableWidget->insertRow ( ui->tableWidget->rowCount() );
//    ui->tableWidget->insertRow ( ui->tableWidget->rowCount() );


//    createCList();

//    ui->actionAdd_from_file->setEnabled(false);
    ui->actionLog_Out->setEnabled(false);

    ui->addButton->setVisible(false);
    ui->saveButton->setVisible(false);
    ui->editButton->setVisible(false);
    ui->addSouvenirButton->setVisible(false);

//    connect(ui->homeBox,SIGNAL(activated(int)), this, SLOT(showColleges(int)));
////    connect(ui->homeBox,SIGNAL(activated(int)), this, SLOT(displaySouvenirs(int)));
//    connect(ui->campusTable,SIGNAL(currentRowChanged(int)), this, SLOT(displaySouvenirs(int)));
//    connect(ui->campusTable,SIGNAL(currentRowChanged(int)), this, SLOT(getCollegeIndex(int)));

    //isAdmin = false;

    ui->tableView->resizeColumnsToContents();
//    ui->tableView->horizontalHeader()->stretchLastSection();

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
             qry->prepare("select * from MLBinfo order by teamName");
     }
     else if (ui->combo_sort->currentText() == "Stadium")
     {
             qry->prepare("select * from MLBinfo order by stadiumName");
     }
     else if (ui->combo_sort->currentText() == "Stadium Age")
     {
              qry->prepare("select * from MLBinfo order by dateOpened");
     }
     else if (ui->combo_sort->currentText() == "Capacity")
     {
             qry->prepare("select * from MLBinfo order by seatingCapacity");
     }
     else if (ui->combo_sort->currentText() == "Location")
     {
           qry->prepare("select * from MLBinfo order by location");
     }
     else if (ui->combo_sort->currentText() == "Surface")
     {
        qry->prepare("select * from MLBinfo order by playingSurface");
     }
     else if (ui->combo_sort->currentText() == "League")
     {
        qry->prepare("select * from MLBinfo order by league");
     }
     else if (ui->combo_sort->currentText() == "Center Field")
     {
         qry->prepare("select * from MLBinfo order by distanceToCenter");
     }
     else
     {
        qry->prepare("select * from MLBinfo order by roofType");
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

        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'Arizona Diamondbacks'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Boston Red Sox")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'Boston Red Sox'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Baltimore Orioles")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'Baltimore Orioles'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Atlanta Braves")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'Atlanta Braves'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Chicago White Sox")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'Chicago White Sox'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Chicago Cubs")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'Chicago Cubs'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Cincinnati Reds")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'Cincinnati Reds'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Milwaukee Brewers")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'Milwaukee Brewers'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Miami Marlins")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'Miami Marlins'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Los Angeles Dodgers")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'Los Angeles Dodgers'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Los Angeles Angels")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'Los Angeles Angels'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Kansas City Royals")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'Kansas City Royals'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Houston Astros")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'Houston Astros'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Detroit Tigers")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'Detroit Tigers'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Colorado Rockies")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'Colorado Rockies'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Cleveland Indians")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'Cleveland Indians'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Washington Nationals")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'Washington Nationals'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Toronto Blue Jays")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'Toronto Blue Jays'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Texas Rangers")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'Texas Rangers'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "St.Louis Cardinals")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'St.Louis Cardinal'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Seattle Mariners")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'Seattle Mariners'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "San Francisco Giants")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'San Francisco Giants'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "San Diego Padres")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'San Diego Padres'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Pittsburgh Pirates")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'Pittsburgh Pirates'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Philadelphia Phillies")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'Philadelphia Phillies'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "Oakland Athletics")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'Oakland Athletics'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "New York Yankees")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'New York Yankees'");;
        qry->exec();
    }
    else if(ui->combo_team->currentText() == "New York Mets")
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'New York Mets'");;
        qry->exec();
    }
    else
    {
        qry->prepare("select teamName, stadiumName, seatingCapacity, location, playingSurface, league, dateOpened, distanceToCenter, ballparkTypology, roofType from MLBinfo where teamName = 'Minnesota Twins'");;
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

    qry->prepare("select * from MLBinfo");
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
    qry->prepare("select * from MLBinfo where league = 'American'order by stadiumName");;

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

    qry->prepare("select * from MLBinfo where league = 'National' order by stadiumName");
  //  qry->prepare("select * from MLBinfo where league = 'National' order by teamName");
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

    qry->prepare("select * from MLBinfo where roofType = 'Open'");
    qry->exec();
    int i = 0;
    if(qry->isActive())
        while(qry->next())
            i++;

    data = i;
     ui->label_2->setText(data);
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


    qry->prepare("select * from MLBinfo order by dateOpened");
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
    souvenirsDB.open();

        MainWindow souvenirObj;
        QSqlQueryModel * model=new QSqlQueryModel();

        QSqlQuery * qry=new QSqlQuery(souvenirObj.souvenirsDB);
        qry->prepare("select souvenir, price from souvenirs");

        qry->exec();

        model->setQuery(*qry);
        ui->tableView->setModel(model);
}

void MainWindow::on_addSouvenirButton_clicked()
{
    // open a new dialog window to add a souvenir

    addSouvenirs = new addsouvenir(this);
    addSouvenirs->show();

}

void MainWindow::on_push_plan_clicked()
{

}
