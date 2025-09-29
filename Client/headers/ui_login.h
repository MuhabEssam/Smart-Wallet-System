/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QPushButton *login;
    QPushButton *register_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *ID_1;
    QLineEdit *pass_1;
    QLabel *label_3;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(680, 323);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("applications-internet")));
        Login->setWindowIcon(icon);
        login = new QPushButton(Login);
        login->setObjectName(QString::fromUtf8("login"));
        login->setGeometry(QRect(230, 210, 93, 29));
        register_2 = new QPushButton(Login);
        register_2->setObjectName(QString::fromUtf8("register_2"));
        register_2->setGeometry(QRect(380, 210, 93, 29));
        label = new QLabel(Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 100, 151, 20));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(Login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 150, 151, 20));
        label_2->setFont(font);
        ID_1 = new QLineEdit(Login);
        ID_1->setObjectName(QString::fromUtf8("ID_1"));
        ID_1->setGeometry(QRect(230, 100, 241, 26));
        pass_1 = new QLineEdit(Login);
        pass_1->setObjectName(QString::fromUtf8("pass_1"));
        pass_1->setGeometry(QRect(230, 150, 241, 26));
        label_3 = new QLabel(Login);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 20, 281, 41));
        QFont font1;
        font1.setPointSize(16);
        label_3->setFont(font1);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login widnow", nullptr));
        login->setText(QCoreApplication::translate("Login", "Log in", nullptr));
        register_2->setText(QCoreApplication::translate("Login", "Register", nullptr));
        label->setText(QCoreApplication::translate("Login", "National ID", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "Password", nullptr));
        label_3->setText(QCoreApplication::translate("Login", "Smart Wallet Log in", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
