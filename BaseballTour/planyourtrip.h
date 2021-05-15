#ifndef PLANYOURTRIP_H
#define PLANYOURTRIP_H

#include <QDialog>
#include "takeyourtrip.h"

namespace Ui {
class planyourtrip;
}

class planyourtrip : public QDialog
{
    Q_OBJECT

public:
    explicit planyourtrip(QWidget *parent = nullptr);
    ~planyourtrip();

private slots:
    void on_button_AutomaticTrip_clicked();

    void on_button_CustomTrip_clicked();

private:
    Ui::planyourtrip *ui;
    takeyourtrip *takeTrip;
};

#endif // PLANYOURTRIP_H
