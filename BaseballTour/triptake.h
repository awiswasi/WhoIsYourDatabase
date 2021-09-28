#ifndef TRIPTAKE_H
#define TRIPTAKE_H

#include <QDialog>
//#include "trip.h"

namespace Ui {
class triptake;
}

class triptake : public QDialog
{
    Q_OBJECT

public:
    explicit triptake(QWidget *parent = nullptr);
    ~triptake();

private slots:
    void on_buttonBox_accepted();

    void on_back_button_clicked();

private:
    Ui::triptake *ui;
   // trip *tripp;
};

#endif // TRIPTAKE_H
