#ifndef ADDSOUVENIR_H
#define ADDSOUVENIR_H

#include <QWidget>
#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

namespace Ui {
class addsouvenir;
}

class addsouvenir : public QWidget
{
    Q_OBJECT

public:
    explicit addsouvenir(QWidget *parent = nullptr);
    ~addsouvenir();

private:
    Ui::addsouvenir *ui;
};

#endif // ADDSOUVENIR_H
