#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QMainWindow>
#include <iostream>
#include <QMainWindow>
#include <QDebug>
#include <QTcpSocket>
#include <QTcpServer>
#include <QSet>
#include <QString>
#include <QMessageBox>
#include <QList>
#include <QMap>
#include <map>
#include <cstring>
#include <fstream>
#include "user_data.h"
#include "qcustomplot.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class TCPSERVER;
}
QT_END_NAMESPACE

class TCPSERVER : public QMainWindow
{
    Q_OBJECT

public:
    TCPSERVER(QWidget *parent = nullptr);
    ~TCPSERVER();

private:
    Ui::TCPSERVER *ui;
    QTcpServer * Serv;
    QList<QTcpSocket*> sockets;
    std::map<QString, User_data*> records; // Store users data
    User_data *record;
private slots:
    void ProcessClientData(QTcpSocket *socket, QString user_msg); // Process client login and registration messages
    void sendToclient(QTcpSocket* socket, QString data); // send data to the client
    void AppendMessage(QString msg); // append server logs in log file
    void readFromSocket(); //  read data from clients
    void NewConnection(); // Recieve  different connections
    void AddToSockets(QTcpSocket *socket); // Add new connected socckets to sockets list
    void CloseSockcet(); // Close any opened socket
    void sendBalance(QTcpSocket *socket,QString user_msg); // Send balance to the clients
    void updateBalance(QTcpSocket* socket,QString trans);  // Update balances  of the  clients in deposit and withdraw transactions
    void sendTransactions(QTcpSocket *socket,QString user_msg); // Send client transactions
    vector<string> getClientDetails(QString info); // Extracts balance and ID information from a QString
    void AnalyzeClientsInfo(); // Calculate statistics for all client  on the serve
    void on_statistcs_button_clicked(); //  Show statistics
};
#endif // TCPSERVER_H
