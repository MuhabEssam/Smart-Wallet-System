/********************************************************************************
** Form generated from reading UI file 'Register.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *name;
    QLineEdit *age;
    QLabel *label_3;
    QLineEdit *ID;
    QLabel *ID_3;
    QLabel *Pass1;
    QLineEdit *phone;
    QPushButton *Register;
    QLabel *Pass1_2;
    QLineEdit *pass;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(810, 405);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("applications-development")));
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(250, 0, 291, 40));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 60, 79, 40));
        label_2->setFont(font);
        label_2->setAutoFillBackground(false);
        name = new QLineEdit(centralwidget);
        name->setObjectName("name");
        name->setGeometry(QRect(200, 70, 361, 26));
        name->setAutoFillBackground(false);
        age = new QLineEdit(centralwidget);
        age->setObjectName("age");
        age->setGeometry(QRect(200, 120, 361, 26));
        age->setAutoFillBackground(false);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 110, 53, 40));
        label_3->setFont(font);
        label_3->setAutoFillBackground(false);
        ID = new QLineEdit(centralwidget);
        ID->setObjectName("ID");
        ID->setGeometry(QRect(200, 170, 361, 26));
        ID->setAutoFillBackground(false);
        ID_3 = new QLabel(centralwidget);
        ID_3->setObjectName("ID_3");
        ID_3->setGeometry(QRect(30, 160, 151, 40));
        ID_3->setFont(font);
        ID_3->setAutoFillBackground(false);
        Pass1 = new QLabel(centralwidget);
        Pass1->setObjectName("Pass1");
        Pass1->setGeometry(QRect(30, 250, 125, 40));
        Pass1->setFont(font);
        Pass1->setAutoFillBackground(false);
        phone = new QLineEdit(centralwidget);
        phone->setObjectName("phone");
        phone->setGeometry(QRect(200, 260, 361, 26));
        phone->setAutoFillBackground(false);
        Register = new QPushButton(centralwidget);
        Register->setObjectName("Register");
        Register->setGeometry(QRect(220, 310, 311, 29));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        Register->setFont(font1);
        Register->setAutoFillBackground(false);
        Register->setStyleSheet(QString::fromUtf8("color:green\n"
""));
        Pass1_2 = new QLabel(centralwidget);
        Pass1_2->setObjectName("Pass1_2");
        Pass1_2->setGeometry(QRect(30, 210, 125, 40));
        Pass1_2->setFont(font);
        Pass1_2->setAutoFillBackground(false);
        pass = new QLineEdit(centralwidget);
        pass->setObjectName("pass");
        pass->setGeometry(QRect(200, 220, 361, 26));
        pass->setAutoFillBackground(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 810, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Register window", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Smart Wallet Register", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Age", nullptr));
        ID_3->setText(QCoreApplication::translate("MainWindow", "National ID", nullptr));
        Pass1->setText(QCoreApplication::translate("MainWindow", "Phone", nullptr));
        Register->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        Pass1_2->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
