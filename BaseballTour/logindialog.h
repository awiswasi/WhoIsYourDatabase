#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit loginDialog(QWidget *parent = nullptr);
    ~loginDialog();
    bool getLoggedIn();

private slots:
    void on_cancelButton_clicked();

    void on_loginButton_clicked();

private:
    Ui::loginDialog *ui;
    bool loggedIn;
};

#endif // LOGINDIALOG_H
