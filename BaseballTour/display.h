#ifndef DISPLAY_H
#define DISPLAY_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class display;
}

class display : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit display(QWidget *parent = nullptr);
    ~display();

private slots:
    void on_pushButton_clicked();

private:
    Ui::display *ui;
};

#endif // DISPLAY_H
