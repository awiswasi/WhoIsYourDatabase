#ifndef EDITTEAM_H
#define EDITTEAM_H

#include <QDialog>

namespace Ui {
class editTeam;
}

class editTeam : public QDialog
{
    Q_OBJECT

public:
    explicit editTeam(QWidget *parent = nullptr);
    ~editTeam();

private slots:
    void on_SaveButton_clicked();

private:
    Ui::editTeam *ui;
};

#endif // EDITTEAM_H
