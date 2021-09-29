#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QSqlDatabase>
#include <QDebug>

namespace Ui
{
    class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase mydb;

    void connClose()
    {
        mydb.close();
    }
    bool connOpen()
    {
        mydb=QSqlDatabase::addDatabase("QSQLITE");

        // PUT IN YOUR OWN FILE PATH!
        mydb.setDatabaseName("/Users/mered/OneDrive/Desktop/data.sqlite");

        if(!mydb.open())
        {
            qDebug() << "Failed to open the database";
               return false;
        }
        else
        {
            qDebug() << "Connected to database";
            return true;
        }
    }

    explicit login(QWidget *parent = nullptr);
    ~login();
private slots:
    /**
     * @brief on_pushButton_Login_clicked ensures correct login
     * and opens admin screen
     */
    void on_pushButton_Login_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
