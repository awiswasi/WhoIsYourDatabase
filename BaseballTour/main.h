#ifndef MAIN_H
#define MAIN_H

#include <QDialog>

namespace Ui {
class main;
}

class main : public QDialog
{
    Q_OBJECT

public:
    explicit main(QWidget *parent = nullptr);
    ~main();

private:
    Ui::main *ui;
};

#endif // MAIN_H
