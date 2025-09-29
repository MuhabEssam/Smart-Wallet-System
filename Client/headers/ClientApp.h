#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QVBoxLayout>
QT_BEGIN_NAMESPACE
namespace Ui {
class ClientApp;
}
QT_END_NAMESPACE

class ClientApp : public QMainWindow
{
    Q_OBJECT

public:
    ClientApp(QWidget *parent = nullptr);
    ~ClientApp();
private:
    Ui::ClientApp *ui;
};
#endif // MAINWINDOW_H
