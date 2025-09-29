/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_client
{
public:
    QLabel *client_label;
    QLabel *label_2;
    QLineEdit *deposit_value;
    QLineEdit *withdraw_value;
    QLabel *label_5;
    QPushButton *Deposit;
    QPushButton *Withdraw;
    QLabel *Balance_label;
    QPushButton *get_balance;
    QPushButton *Undo_trans;
    QLabel *label_3;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QTextBrowser *Transactions;
    QLabel *label_4;
    QPushButton *get_transactions;

    void setupUi(QDialog *client)
    {
        if (client->objectName().isEmpty())
            client->setObjectName(QString::fromUtf8("client"));
        client->resize(753, 548);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("applications-development")));
        client->setWindowIcon(icon);
        client_label = new QLabel(client);
        client_label->setObjectName(QString::fromUtf8("client_label"));
        client_label->setGeometry(QRect(300, 30, 151, 41));
        QFont font;
        font.setPointSize(14);
        client_label->setFont(font);
        label_2 = new QLabel(client);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 90, 151, 31));
        label_2->setFont(font);
        deposit_value = new QLineEdit(client);
        deposit_value->setObjectName(QString::fromUtf8("deposit_value"));
        deposit_value->setGeometry(QRect(190, 130, 271, 26));
        withdraw_value = new QLineEdit(client);
        withdraw_value->setObjectName(QString::fromUtf8("withdraw_value"));
        withdraw_value->setGeometry(QRect(190, 180, 271, 26));
        label_5 = new QLabel(client);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 180, 99, 31));
        label_5->setFont(font);
        Deposit = new QPushButton(client);
        Deposit->setObjectName(QString::fromUtf8("Deposit"));
        Deposit->setGeometry(QRect(510, 130, 101, 31));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        Deposit->setFont(font1);
        Deposit->setStyleSheet(QString::fromUtf8("color:green"));
        Withdraw = new QPushButton(client);
        Withdraw->setObjectName(QString::fromUtf8("Withdraw"));
        Withdraw->setGeometry(QRect(510, 180, 101, 29));
        Withdraw->setFont(font1);
        Withdraw->setStyleSheet(QString::fromUtf8("color:red"));
        Balance_label = new QLabel(client);
        Balance_label->setObjectName(QString::fromUtf8("Balance_label"));
        Balance_label->setGeometry(QRect(190, 90, 221, 31));
        Balance_label->setFont(font);
        get_balance = new QPushButton(client);
        get_balance->setObjectName(QString::fromUtf8("get_balance"));
        get_balance->setGeometry(QRect(510, 90, 111, 29));
        get_balance->setFont(font1);
        get_balance->setStyleSheet(QString::fromUtf8("color:blue\n"
""));
        Undo_trans = new QPushButton(client);
        Undo_trans->setObjectName(QString::fromUtf8("Undo_trans"));
        Undo_trans->setGeometry(QRect(180, 230, 371, 29));
        Undo_trans->setFont(font1);
        Undo_trans->setAutoFillBackground(false);
        Undo_trans->setStyleSheet(QString::fromUtf8("background-color: red;"));
        label_3 = new QLabel(client);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 130, 85, 31));
        label_3->setFont(font);
        layoutWidget = new QWidget(client);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 271, 661, 271));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        Transactions = new QTextBrowser(layoutWidget);
        Transactions->setObjectName(QString::fromUtf8("Transactions"));
        Transactions->setFont(font1);

        formLayout->setWidget(2, QFormLayout::SpanningRole, Transactions);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::SpanningRole, label_4);

        get_transactions = new QPushButton(layoutWidget);
        get_transactions->setObjectName(QString::fromUtf8("get_transactions"));
        get_transactions->setFont(font1);
        get_transactions->setStyleSheet(QString::fromUtf8("color:blue"));

        formLayout->setWidget(1, QFormLayout::SpanningRole, get_transactions);

        label_3->raise();
        layoutWidget->raise();
        client_label->raise();
        deposit_value->raise();
        withdraw_value->raise();
        label_5->raise();
        Deposit->raise();
        Withdraw->raise();
        get_balance->raise();
        Balance_label->raise();
        label_2->raise();
        Undo_trans->raise();

        retranslateUi(client);

        QMetaObject::connectSlotsByName(client);
    } // setupUi

    void retranslateUi(QDialog *client)
    {
        client->setWindowTitle(QCoreApplication::translate("client", "ClientApp", nullptr));
        client_label->setText(QCoreApplication::translate("client", "Text", nullptr));
        label_2->setText(QCoreApplication::translate("client", "Balance", nullptr));
        label_5->setText(QCoreApplication::translate("client", "Withdraw", nullptr));
        Deposit->setText(QCoreApplication::translate("client", "Deposit", nullptr));
        Withdraw->setText(QCoreApplication::translate("client", "Withdraw", nullptr));
        Balance_label->setText(QString());
        get_balance->setText(QCoreApplication::translate("client", "Get Balance", nullptr));
        Undo_trans->setText(QCoreApplication::translate("client", "Undo last Transaction", nullptr));
        label_3->setText(QCoreApplication::translate("client", "Deposit ", nullptr));
        label_4->setText(QCoreApplication::translate("client", "Transactions", nullptr));
        get_transactions->setText(QCoreApplication::translate("client", "Get Transactions", nullptr));
    } // retranslateUi

};

namespace Ui {
    class client: public Ui_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
