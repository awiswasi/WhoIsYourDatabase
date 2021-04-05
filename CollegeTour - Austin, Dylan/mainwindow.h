#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dataBase.h"

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

private slots:
    void showColleges(int index);
    void displaySouvenirs(int index);
    void editSouvenirs(int index);
    void getCollegeIndex(int index);

    void on_pushButton_clicked();

    void on_actionLogin_triggered();

    void on_actionLog_Out_triggered();

    //void onactionAdd_from_file_triggered();

    void on_addButton_clicked();


    void on_saveButton_clicked();

    void on_actionSave_triggered();

private:
    Ui::MainWindow *ui;
    bool isAdmin;
    int collegeIndex;
};

#endif // MAINWINDOW_H
