/********************************************************************************
** Form generated from reading UI file 'tripplan.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIPPLAN_H
#define UI_TRIPPLAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_TripPlan
{
public:
    QPushButton *takeTripButton;
    QSpinBox *spin_numColleges;
    QLabel *label_PlanForMe;
    QLabel *label_planTrip1;
    QLabel *label_planTrip2;
    QComboBox *dropdown_CollegeList;
    QPushButton *button_AutomaticTrip;
    QLabel *label_planCustom;
    QComboBox *dropdown_CollegeList_2;
    QPushButton *button_CustomTrip;
    QLabel *label_PlanForMe_2;

    void setupUi(QDialog *TripPlan)
    {
        if (TripPlan->objectName().isEmpty())
            TripPlan->setObjectName(QString::fromUtf8("TripPlan"));
        TripPlan->resize(820, 435);
        TripPlan->setMinimumSize(QSize(820, 435));
        takeTripButton = new QPushButton(TripPlan);
        takeTripButton->setObjectName(QString::fromUtf8("takeTripButton"));
        takeTripButton->setGeometry(QRect(680, 360, 131, 61));
        spin_numColleges = new QSpinBox(TripPlan);
        spin_numColleges->setObjectName(QString::fromUtf8("spin_numColleges"));
        spin_numColleges->setGeometry(QRect(120, 60, 51, 31));
        QFont font;
        font.setPointSize(10);
        spin_numColleges->setFont(font);
        spin_numColleges->setMinimum(1);
        label_PlanForMe = new QLabel(TripPlan);
        label_PlanForMe->setObjectName(QString::fromUtf8("label_PlanForMe"));
        label_PlanForMe->setGeometry(QRect(20, 10, 291, 41));
        QFont font1;
        font1.setPointSize(16);
        label_PlanForMe->setFont(font1);
        label_planTrip1 = new QLabel(TripPlan);
        label_planTrip1->setObjectName(QString::fromUtf8("label_planTrip1"));
        label_planTrip1->setGeometry(QRect(20, 60, 91, 31));
        label_planTrip1->setFont(font);
        label_planTrip2 = new QLabel(TripPlan);
        label_planTrip2->setObjectName(QString::fromUtf8("label_planTrip2"));
        label_planTrip2->setGeometry(QRect(180, 60, 141, 31));
        label_planTrip2->setFont(font);
        dropdown_CollegeList = new QComboBox(TripPlan);
        dropdown_CollegeList->setObjectName(QString::fromUtf8("dropdown_CollegeList"));
        dropdown_CollegeList->setGeometry(QRect(300, 61, 351, 31));
        dropdown_CollegeList->setFont(font);
        button_AutomaticTrip = new QPushButton(TripPlan);
        button_AutomaticTrip->setObjectName(QString::fromUtf8("button_AutomaticTrip"));
        button_AutomaticTrip->setGeometry(QRect(670, 50, 131, 51));
        label_planCustom = new QLabel(TripPlan);
        label_planCustom->setObjectName(QString::fromUtf8("label_planCustom"));
        label_planCustom->setGeometry(QRect(20, 200, 301, 31));
        label_planCustom->setFont(font);
        dropdown_CollegeList_2 = new QComboBox(TripPlan);
        dropdown_CollegeList_2->setObjectName(QString::fromUtf8("dropdown_CollegeList_2"));
        dropdown_CollegeList_2->setGeometry(QRect(320, 200, 331, 31));
        dropdown_CollegeList_2->setFont(font);
        button_CustomTrip = new QPushButton(TripPlan);
        button_CustomTrip->setObjectName(QString::fromUtf8("button_CustomTrip"));
        button_CustomTrip->setGeometry(QRect(670, 190, 131, 51));
        label_PlanForMe_2 = new QLabel(TripPlan);
        label_PlanForMe_2->setObjectName(QString::fromUtf8("label_PlanForMe_2"));
        label_PlanForMe_2->setGeometry(QRect(20, 150, 361, 41));
        label_PlanForMe_2->setFont(font1);

        retranslateUi(TripPlan);

        QMetaObject::connectSlotsByName(TripPlan);
    } // setupUi

    void retranslateUi(QDialog *TripPlan)
    {
        takeTripButton->setText(QCoreApplication::translate("TripPlan", "Peek all colleges", nullptr));
        label_PlanForMe->setText(QCoreApplication::translate("TripPlan", "Do the planning for me:", nullptr));
        label_planTrip1->setText(QCoreApplication::translate("TripPlan", "Plan a trip with ", nullptr));
        label_planTrip2->setText(QCoreApplication::translate("TripPlan", "colleges starting at", nullptr));
        button_AutomaticTrip->setText(QCoreApplication::translate("TripPlan", "Go!", nullptr));
        label_planCustom->setText(QCoreApplication::translate("TripPlan", "Plan a custom trip by selecting colleges starting at", nullptr));
        button_CustomTrip->setText(QCoreApplication::translate("TripPlan", "Continue", nullptr));
        label_PlanForMe_2->setText(QCoreApplication::translate("TripPlan", "I'd like to pick which colleges I visit:", nullptr));
        (void)TripPlan;
    } // retranslateUi

};

namespace Ui {
    class TripPlan: public Ui_TripPlan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIPPLAN_H
