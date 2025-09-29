#include "ClientApp.h"
#include "ui_ClientApp.h"
ClientApp::ClientApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClientApp)
{
    ui->setupUi(this);
}

ClientApp::~ClientApp()
{
    delete ui;
}
