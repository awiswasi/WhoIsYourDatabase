#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>


namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();

private slots:
    void on_edit_cities_clicked();

    void on_edit_food_clicked();

private:
    Ui::admin *ui;
};

#endif // ADMIN_H
