/********************************************************************************
** Form generated from reading UI file 'customtrip.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMTRIP_H
#define UI_CUSTOMTRIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomTrip
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QListWidget *listView;

    void setupUi(QDialog *CustomTrip)
    {
        if (CustomTrip->objectName().isEmpty())
            CustomTrip->setObjectName(QString::fromUtf8("CustomTrip"));
        CustomTrip->resize(559, 521);
        buttonBox = new QDialogButtonBox(CustomTrip);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(460, 440, 81, 71));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(CustomTrip);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 501, 31));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        listView = new QListWidget(CustomTrip);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(20, 50, 431, 441));

        retranslateUi(CustomTrip);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, CustomTrip, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, CustomTrip, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(CustomTrip);
    } // setupUi

    void retranslateUi(QDialog *CustomTrip)
    {
        CustomTrip->setWindowTitle(QCoreApplication::translate("CustomTrip", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("CustomTrip", "test test test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomTrip: public Ui_CustomTrip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMTRIP_H
