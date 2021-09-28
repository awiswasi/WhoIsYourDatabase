#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include "display.h"
#include "login.h"
#include "trip.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_displayCollegeButton_clicked(); // talia comment these out when using!

    void on_planYourTripButton_clicked();

    void on_pushButton_2_clicked();       // talia comment these out when using!

    void on_displayCities_clicked();

    void on_adminButton_clicked();

private:
    Ui::MainWindow *ui;
    display *disp;
    login *log;
    trip *trp;
};
#endif // MAINWINDOW_H
