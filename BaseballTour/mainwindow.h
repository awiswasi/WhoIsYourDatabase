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
    void createCList();
    QSqlDatabase souvenirsDB;

private slots:
//    void displaySouvenirs(int index);
//    void editSouvenirs(int index);

    void on_actionLogin_triggered();

    void on_actionLog_Out_triggered();

    //void onactionAdd_from_file_triggered();

//    void on_addButton_clicked();

//    void on_saveButton_clicked();

//    void on_actionSave_triggered();

    void on_push_souvenirs_clicked();

    void on_addSouvenirButton_clicked();

private:
    Ui::MainWindow *ui;
    bool isAdmin;
};

#endif // MAINWINDOW_H
