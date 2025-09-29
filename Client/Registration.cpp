#include "Registration.h"
#include "ui_Registration.h"
#include <iostream>
Registration::Registration(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Registration)
{
    ui->setupUi(this);
    RSocket=new QTcpSocket(this);
    RSocket->connectToHost(QHostAddress::LocalHost,8080);
    connect(RSocket, &QTcpSocket::readyRead, this, &Registration::Read);
    connect(RSocket, &QTcpSocket::disconnected, this, &Registration::CloseSockcet);
    if(!RSocket->waitForConnected())
    {
        QMessageBox::critical(this,"Client", QString("The following error occurred: %1.").arg(RSocket->errorString()));
        exit(EXIT_FAILURE);
    }
}

Registration::~Registration()
{
    if(RSocket->isOpen()){
        RSocket->close();
    }
    RSocket->deleteLater();
    delete ui;
}

void Registration::Read()
{
    QByteArray data;
    QDataStream socketStream(RSocket);
    socketStream.startTransaction();
    socketStream >> data;
    if(!socketStream.commitTransaction())
    {
        QString message = QString("Waiting");
        return;
    }
    QString msg = QString::fromStdString(data.toStdString());
    if(msg[0]=='F'){
        QMessageBox::information(this,"Error","User Found");
    }
    else if(msg[0]=='C'){
        QMessageBox::information(this,"New user","Registeration complete");
    }
}
void Registration::sendData(QString data){
    if(RSocket){
        if(RSocket->isOpen()){
            QDataStream socketStream(RSocket);
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
void Registration::CloseSockcet()
{
    RSocket->deleteLater();
    RSocket=nullptr;
}
void Registration::on_Register_clicked()
{
    QString Name = ui->name->text();
    QString Age = ui->age->text();
    QString ID = ui->ID->text();
    QString Phone=ui->phone->text();
    QString Password = ui->pass->text();
    //Here we check if the fields are empty or not
    if (Name.isEmpty() || Age.isEmpty() || ID.isEmpty() || Password.isEmpty()||Phone.isEmpty()){
        QMessageBox::critical(this, "Error", "All fields are required!");
        return;
    }
    QString Client_info = "N"+Name + "," + Age + "," + ID + ","+ Phone+ ","+ Password; //Combine data toegther to send it to server
    sendData(Client_info);
}

