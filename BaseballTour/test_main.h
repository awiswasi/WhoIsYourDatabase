#ifndef TEST_MAIN_H
#define TEST_MAIN_H

#include <QDialog>

namespace Ui {
class test_main;
}

class test_main : public QDialog
{
    Q_OBJECT

public:
    explicit test_main(QWidget *parent = nullptr);
    ~test_main();

private:
    Ui::test_main *ui;
};

#endif // TEST_MAIN_H
