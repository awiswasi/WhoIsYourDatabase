/********************************************************************************
** Form generated from reading UI file 'triptake.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIPTAKE_H
#define UI_TRIPTAKE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_TripTake
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *nextButton;
    QLabel *label;
    QTableWidget *tableWidget;
    QPushButton *buyButton;
    QLabel *label_2;
    QLabel *traveledD;

    void setupUi(QDialog *TripTake)
    {
        if (TripTake->objectName().isEmpty())
            TripTake->setObjectName(QString::fromUtf8("TripTake"));
        TripTake->resize(746, 580);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TripTake->sizePolicy().hasHeightForWidth());
        TripTake->setSizePolicy(sizePolicy);
        TripTake->setMinimumSize(QSize(670, 580));
        buttonBox = new QDialogButtonBox(TripTake);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(390, 530, 341, 21));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel);
        nextButton = new QPushButton(TripTake);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setGeometry(QRect(490, 60, 231, 91));
        label = new QLabel(TripTake);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 621, 41));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        tableWidget = new QTableWidget(TripTake);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QFont font1;
        font1.setPointSize(18);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 7)
            tableWidget->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem9->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tableWidget->setItem(0, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFlags(Qt::ItemIsEnabled);
        tableWidget->setItem(0, 1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem11->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsEnabled);
        tableWidget->setItem(1, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFlags(Qt::ItemIsEnabled);
        tableWidget->setItem(1, 1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem13->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tableWidget->setItem(2, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsEnabled);
        tableWidget->setItem(2, 1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem15->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tableWidget->setItem(3, 0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tableWidget->setItem(3, 1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem17->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tableWidget->setItem(4, 0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tableWidget->setItem(4, 1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tableWidget->setItem(5, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tableWidget->setItem(5, 1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tableWidget->setItem(6, 0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tableWidget->setItem(6, 1, __qtablewidgetitem22);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setGeometry(QRect(20, 60, 441, 450));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy1);
        tableWidget->setMinimumSize(QSize(400, 450));
        QFont font2;
        font2.setPointSize(18);
        font2.setKerning(true);
        tableWidget->setFont(font2);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setVisible(false);
        buyButton = new QPushButton(TripTake);
        buyButton->setObjectName(QString::fromUtf8("buyButton"));
        buyButton->setGeometry(QRect(490, 160, 231, 51));
        label_2 = new QLabel(TripTake);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(490, 410, 181, 41));
        label_2->setFont(font);
        traveledD = new QLabel(TripTake);
        traveledD->setObjectName(QString::fromUtf8("traveledD"));
        traveledD->setGeometry(QRect(490, 450, 251, 41));
        QFont font3;
        font3.setPointSize(14);
        traveledD->setFont(font3);

        retranslateUi(TripTake);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, TripTake, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, TripTake, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(TripTake);
    } // setupUi

    void retranslateUi(QDialog *TripTake)
    {
        TripTake->setWindowTitle(QCoreApplication::translate("TripTake", "Dialog", nullptr));
        nextButton->setText(QCoreApplication::translate("TripTake", "Next", nullptr));
        label->setText(QCoreApplication::translate("TripTake", "College Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("TripTake", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("TripTake", "Item", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("TripTake", "row1", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("TripTake", "row2", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("TripTake", "row3", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("TripTake", "row4", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("TripTake", "row5", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("TripTake", "row6", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("TripTake", "row7", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(0, 0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("TripTake", "$25", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(0, 1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("TripTake", "A beanie", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(1, 0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("TripTake", "$5,000", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(1, 1);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("TripTake", "A horse", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(2, 0);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("TripTake", "$24", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(2, 1);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("TripTake", "Pants", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(3, 0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("TripTake", "$12", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(3, 1);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("TripTake", "A pant", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(4, 0);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("TripTake", "priceless", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(4, 1);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("TripTake", ":)", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        buyButton->setText(QCoreApplication::translate("TripTake", "Buy Selections", nullptr));
        label_2->setText(QCoreApplication::translate("TripTake", "Distance Traveled:", nullptr));
        traveledD->setText(QCoreApplication::translate("TripTake", "0 miles", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TripTake: public Ui_TripTake {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIPTAKE_H
