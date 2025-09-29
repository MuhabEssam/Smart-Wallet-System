#ifndef REGISTER_H
#define REGISTER_H
#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QVBoxLayout>
#include <QTcpSocket>
#include <QHostAddress>
#include <QByteArray>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QTcpSocket *RSocket;
    ~MainWindow();

private slots:

    void on_Register_clicked();
    void Read();
    void sendData(QString data);
    void CloseSockcet();
private:
    Ui::MainWindow *ui;
};
#endif // REGISTER_H
