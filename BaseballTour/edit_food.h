#ifndef EDIT_FOOD_H
#define EDIT_FOOD_H

#include <QDialog>

namespace Ui {
class edit_food;
}

class edit_food : public QDialog
{
    Q_OBJECT

public:
    explicit edit_food(QWidget *parent = nullptr);
    ~edit_food();

private:
    Ui::edit_food *ui;
};

#endif // EDIT_FOOD_H
