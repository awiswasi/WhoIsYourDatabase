#ifndef EDIT_CITIES_H
#define EDIT_CITIES_H

#include <QDialog>

namespace Ui {
class edit_cities;
}

class edit_cities : public QDialog
{
    Q_OBJECT

public:
    explicit edit_cities(QWidget *parent = nullptr);
    ~edit_cities();

private:
    Ui::edit_cities *ui;
};

#endif // EDIT_CITIES_H
