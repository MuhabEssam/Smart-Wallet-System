#ifndef REGISTRATION_H
#define REGISTRATION_H
#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QVBoxLayout>
#include <QTcpSocket>
#include <QHostAddress>
#include <QByteArray>
QT_BEGIN_NAMESPACE
namespace Ui {
class Registration;
}
QT_END_NAMESPACE

class Registration : public QMainWindow
{
    Q_OBJECT

public:
    Registration(QWidget *parent = nullptr);
    ~Registration();

private slots:
    void on_Register_clicked();
    void Read(); // Read data from server and check if the user found
    void sendData(QString data); // Send Registtration data to server
    void CloseSockcet(); // Close socket
private:
    Ui::Registration *ui;
    QTcpSocket *RSocket;
};
#endif // REGISTRATION_H
