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

private slots:
    //void on_pushButton_clicked();

    void on_addSouvenirButton_clicked();

private:
    Ui::addsouvenir *ui;
};

#endif // ADDSOUVENIR_H
