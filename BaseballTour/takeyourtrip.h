#ifndef TAKEYOURTRIP_H
#define TAKEYOURTRIP_H

#include <QDialog>

namespace Ui {
class takeyourtrip;
}

class takeyourtrip : public QDialog
{
    Q_OBJECT

public:
    explicit takeyourtrip(QWidget *parent = nullptr);
    ~takeyourtrip();

private:
    Ui::takeyourtrip *ui;
};

#endif // TAKEYOURTRIP_H