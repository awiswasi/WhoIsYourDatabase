/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_loginDialog
{
public:
    QPushButton *loginButton;
    QPushButton *cancelButton;
    QLineEdit *userEdit;
    QLineEdit *passEdit;
    QLabel *userLabel;
    QLabel *passLabel;

    void setupUi(QDialog *loginDialog)
    {
        if (loginDialog->objectName().isEmpty())
            loginDialog->setObjectName(QString::fromUtf8("loginDialog"));
        loginDialog->resize(400, 142);
        loginButton = new QPushButton(loginDialog);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(200, 100, 83, 25));
        loginButton->setFocusPolicy(Qt::StrongFocus);
        cancelButton = new QPushButton(loginDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(300, 100, 83, 25));
        cancelButton->setFocusPolicy(Qt::StrongFocus);
        userEdit = new QLineEdit(loginDialog);
        userEdit->setObjectName(QString::fromUtf8("userEdit"));
        userEdit->setGeometry(QRect(140, 20, 201, 25));
        passEdit = new QLineEdit(loginDialog);
        passEdit->setObjectName(QString::fromUtf8("passEdit"));
        passEdit->setGeometry(QRect(140, 60, 201, 25));
        passEdit->setEchoMode(QLineEdit::Password);
        userLabel = new QLabel(loginDialog);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));
        userLabel->setGeometry(QRect(30, 20, 81, 21));
        QFont font;
        font.setPointSize(11);
        userLabel->setFont(font);
        passLabel = new QLabel(loginDialog);
        passLabel->setObjectName(QString::fromUtf8("passLabel"));
        passLabel->setGeometry(QRect(30, 60, 81, 21));
        passLabel->setFont(font);
        loginButton->raise();
        cancelButton->raise();
        passEdit->raise();
        userLabel->raise();
        passLabel->raise();
        userEdit->raise();
        QWidget::setTabOrder(userEdit, passEdit);
        QWidget::setTabOrder(passEdit, loginButton);
        QWidget::setTabOrder(loginButton, cancelButton);

        retranslateUi(loginDialog);

        QMetaObject::connectSlotsByName(loginDialog);
    } // setupUi

    void retranslateUi(QDialog *loginDialog)
    {
        loginDialog->setWindowTitle(QCoreApplication::translate("loginDialog", "Dialog", nullptr));
        loginButton->setText(QCoreApplication::translate("loginDialog", "Login", nullptr));
        cancelButton->setText(QCoreApplication::translate("loginDialog", "Cancel", nullptr));
        userLabel->setText(QCoreApplication::translate("loginDialog", "Username", nullptr));
        passLabel->setText(QCoreApplication::translate("loginDialog", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginDialog: public Ui_loginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
