#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlDatabase souvenirsDB;

private slots:
    void on_actionLogin_triggered();


    void on_push_souvenirs_clicked();

private:
    Ui::MainWindow *ui;
    bool isAdmin;

};
#endif // MAINWINDOW_H
