#include "client.h"
#include "ui_client.h"

client::client(QWidget *parent,QString info)
    : QDialog(parent)
    , ui(new Ui::client)
{
    ui->setupUi(this);
    CSocket=new QTcpSocket(this);
    CSocket->connectToHost(QHostAddress::LocalHost,8080);
    connect(CSocket, &QTcpSocket::readyRead, this, &client::readFromServer);
    connect(CSocket, &QTcpSocket::disconnected, this, &client::CloseSockcet);
    if(!CSocket->waitForConnected())
    {
        QMessageBox::critical(this,"Client", QString("The following error occurred: %1.").arg(CSocket->errorString()));
        exit(EXIT_FAILURE);
    }
    vector <string> Name_ID=getClientInfo(info);
    ui->client_label->setText("Welcome " + QString::fromStdString(Name_ID[0]));
    ClientID=stoi(Name_ID[1]);
}

client::~client()
{
    if(CSocket->isOpen()){
        CSocket->close();}
    delete ui;
}
void client::readFromServer()
{
    QByteArray data;
    QDataStream socketStream(CSocket);
    socketStream.startTransaction();
    socketStream >> data;
    if(!socketStream.commitTransaction())
    {
        QString message = QString("Waiting");
        return;
    }
    QString msg = QString::fromStdString(data.toStdString());
    // if (msg[0] == 'k'){
    //     msg.remove(0,1);
    //     QString clientName=msg;
    //     ui->client_label->setText("Welcome " + clientName);
    // }
    if(msg[0] == 'B'){
        msg.remove(0,1);
        ui->Balance_label->setText(msg+" $");
    }
    else if (msg[0] == 'T'){
        msg.remove(0,1);
        ui->Transactions->append(msg);
    }
}
void client::sendData(QString data){
    if(CSocket){
        if(CSocket->isOpen()){
            QDataStream socketStream(CSocket);
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
void client::CloseSockcet()
{
    CSocket->deleteLater();
    CSocket=nullptr;
}

void client::on_get_balance_clicked()
{
    sendData(QString::fromStdString("B"+std::to_string(ClientID)));
}




void client::on_Deposit_clicked()
{
    if(ui->deposit_value->text() != "") {
        bool isNumber = false;
        float Value = ui->deposit_value->text().toFloat(&isNumber); //Check if value is number
        if(isNumber) {
            QString num = QString::number(ClientID);
            QString data=QString::fromStdString("U" + ui->deposit_value->text().toStdString() + "," + num.toStdString());
            sendData(data);
        }
        else QMessageBox::information(this, "Error!", "Please enter a valid number");
        ui->deposit_value->clear();
    }
    else QMessageBox::information(this, "Error!", "Please enter the amount of money to deposite");
}


void client::on_Withdraw_clicked()
{
    if(ui->withdraw_value->text() != "") {
        bool isNumber = false;
        float Value = ui->withdraw_value->text().toFloat(&isNumber);
        if(isNumber) {
            QString num = QString::number(ClientID);
            QString data=QString::fromStdString("U-" + ui->withdraw_value->text().toStdString() + "," + num.toStdString());
            sendData(data);
        }
        else QMessageBox::information(this, "Error", "Please enter a valid number");
        ui->withdraw_value->clear();
    }
    else QMessageBox::information(this, "Error", "Please enter the amount of money to withdraw");
}


void client::on_get_transactions_clicked()
{
    sendData(QString::fromStdString("G"+std::to_string(ClientID)));
}

vector<string> client::getClientInfo(QString info){
    string temp_ID="",temp_name="";
    int coma=0;
    vector<string> Data;
    string msg=info.toStdString();
    for(int i = 0; i < (int)msg.size(); i++){
        if (msg[i] == ',') {
            coma++;
            continue;
        }
        else if(coma==0) temp_name+=msg[i];
        else  if(coma==1){
            temp_ID+=msg[i];
        }
    }
    Data.push_back(temp_name);
    Data.push_back(temp_ID);
    return Data;
}
void client::on_Undo_trans_clicked()
{
    sendData("R");
}

