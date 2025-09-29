#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QTcpSocket>
#include <QHostAddress>
#include <QString>
#include <QByteArray>
#include <QMessageBox>
#include <QDebug>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
namespace Ui {
class client;
}

class client : public QDialog
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr, QString info = "");
    ~client();

private:
    Ui::client *ui;
    QTcpSocket *CSocket;
    int ClientID; // Store client national ID
private slots:
    void sendData(QString data); // Send data to server
    void readFromServer(); // Read data from server
    void on_get_balance_clicked(); // Show client balance
    void on_Deposit_clicked(); // Deposit money to the account
    void on_Withdraw_clicked(); // Withdraw money from the account
    void on_get_transactions_clicked(); // Get the transctions of the clent
    void on_Undo_trans_clicked(); // Remove last transaction
    vector<string> getClientInfo(QString info); // Get name and national ID of client
    void CloseSockcet(); // Close any opened socket
};

#endif // CLIENT_H
