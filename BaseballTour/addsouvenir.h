#ifndef ADDSOUVENIR_H
#define ADDSOUVENIR_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

namespace Ui {
class addsouvenir;
}

class addsouvenir : public QDialog
{
    Q_OBJECT

public:
    explicit addsouvenir(QWidget *parent = nullptr);
    ~addsouvenir();
    QSqlDatabase souvenirsDB;
    void setData(QString arg1);
    QString currentTeam;

private slots:
    //void on_pushButton_clicked();

    void on_addSouvenirButton_clicked();

    void on_deleteButton_clicked();

    void on_cancelButton_clicked();

    void on_connectButton_clicked();

    void on_editSouvenirButton_clicked();

private:
    Ui::addsouvenir *ui;
};

#endif // ADDSOUVENIR_H
