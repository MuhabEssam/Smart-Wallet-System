#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    LSocket=new QTcpSocket(this);
    LSocket->connectToHost(QHostAddress::LocalHost,8080);
    connect(LSocket, &QTcpSocket::readyRead, this, &Login::ReadLogin);
    connect(LSocket, &QTcpSocket::disconnected, this, &Login::CloseSockcet);
    if(!LSocket->waitForConnected())
    {
        QMessageBox::critical(this,"Client", QString("The following error occurred: %1.").arg(LSocket->errorString()));
        exit(EXIT_FAILURE);
    }
    ui->setupUi(this);
}

Login::~Login()
{
    if(LSocket->isOpen()){
        LSocket->close();
    }
    delete ui;
}
void Login::ReadLogin()
{
    QByteArray data;
    QDataStream socketStream(LSocket);
    socketStream.startTransaction();
    socketStream >> data;
    if(!socketStream.commitTransaction())
    {
        QString message = QString("Waiting for more data to come..");
        return;
    }
    QString msg = QString::fromStdString(data.toStdString());
    if(msg[0]=='k'){
        msg.remove(0,1);
        hide();
        //QMessageBox::information(this,"Client",msg);
        User=new client(this,msg);
        User->show();

    }
    else if(msg[0]=='Q'){
        QMessageBox::information(this,"Error","User not found");
    }
}
void Login::sendUserData(QString data){
    if(LSocket){
        if(LSocket->isOpen()){
            QDataStream socketStream(LSocket);
            QByteArray byteArray = data.toUtf8();
            socketStream << byteArray;
        }
        else{
            QMessageBox::critical(this,"No","Established socket");
        }
    }
    else{
        QMessageBox::critical(this,"Client","Not connected");
    }

}
void Login::CloseSockcet()
{
    LSocket->deleteLater();
    LSocket=nullptr;
}
void Login::on_register_2_clicked()
{
    Reg1=new Registration(this);
    Reg1->show();
}


void Login::on_login_clicked()
{
    QString NationalID=ui->ID_1->text();
    QString Password=ui->pass_1->text();
    if(NationalID.isEmpty()||Password.isEmpty()){
        QMessageBox::critical(this,"Error","Please fill all fields");
    }
    QString UserData="L,"+NationalID+","+Password;
    sendUserData(UserData);
}

