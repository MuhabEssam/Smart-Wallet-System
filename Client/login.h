#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include"Registration.h"
#include <QMessageBox>
#include <QString>
#include <QVBoxLayout>
#include <QTcpSocket>
#include <QHostAddress>
#include <QByteArray>
#include "client.h"
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    Registration *Reg1;
    client *User;
    QTcpSocket *LSocket;
    ~Login();

private slots:
    void on_register_2_clicked(); // Open register page
    void on_login_clicked();  // Login in to server
    void sendUserData(QString data); // Send Login credentials to server
    void ReadLogin(); // Check if credentials is correct
    void CloseSockcet(); // Close any socket opened
private:
    Ui::Login *ui;
};

#endif // LOGIN_H
