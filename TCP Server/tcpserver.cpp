#include "tcpserver.h"
#include "ui_tcpserver.h"
#include "user_data.h"
TCPSERVER::TCPSERVER(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TCPSERVER)
{
    ui->setupUi(this);
    Serv = new QTcpServer(this);
    if(Serv->listen(QHostAddress::Any, 8080)){
        connect(Serv, &QTcpServer::newConnection, this, &TCPSERVER::NewConnection);
    }
    else{
        QMessageBox::critical(this,"Server", QString("Unable to start new server: %1.").arg(Serv->errorString()));
    }
}
void TCPSERVER::sendToclient(QTcpSocket* socket, QString data)
{
    if(socket)
    {
        //cout<<"opened"<<endl;
        if(socket->isOpen())
        {
            //cout<<"opened in new"<<endl;
            QDataStream socketStream(socket);
            QByteArray byteArray = data.toUtf8();
            socketStream << byteArray;
        }
        else
            QMessageBox::critical(this,"Server","Socket is not open");
    }
    else
        QMessageBox::critical(this,"Server","Not connected");
}
void TCPSERVER::readFromSocket()
{

    QTcpSocket *socket = reinterpret_cast<QTcpSocket*>(sender());
    QByteArray server_msg;
    QDataStream socketStream(socket);
    socketStream.startTransaction();
    socketStream >> server_msg;

    if(!socketStream.commitTransaction())
    {
        QString message = "Waiting";
        AppendMessage(message);
        return;
    }
    //AppendMessage(server_msg);
    QString msg = QString::fromStdString(server_msg.toStdString());
    if (msg[0] == 'L'||msg[0] == 'N'){
        ProcessClientData(socket,msg);
    }
    else if (msg[0] == 'B') {sendBalance(socket,msg);}
    else if (msg[0] == 'U') updateBalance(socket,msg.remove(0,1));
    else if (msg[0] == 'G') sendTransactions(socket,msg.remove(0,1));
    else if (msg[0] == 'R') {
        float balance = record->remove_last_trans();
        sendToclient(socket, QString::fromStdString("B" + record->getBalance()));
        AppendMessage("----------------------------");
        AppendMessage(QString::fromStdString("Canceled Transaction\nName: "+record->getName()+
                                             "\nNational ID:"+to_string(record->getID())+
                                             "\nAmount:"+to_string(balance)));
        AppendMessage("----------------------------");
    }
}
void TCPSERVER::ProcessClientData(QTcpSocket *socket, QString user_msg){
    //Sent data when the user login
    string msg = user_msg.toStdString();
    //AppendMessage(user_msg);
    if(msg[0]=='N'){
        QString ID = QString::number(User_data(msg).getID());
        if (records.count(ID)) {
            AppendMessage("User Found");
            sendToclient(socket,"F");
        }
        else {
            AppendMessage("New User Created");
            records[ID] = new User_data(msg);
            sendToclient(socket,"C");
        }
    }
    else if(msg[0]=='L'){
        QString ID;
        int coma=0;
        string temp_ID="",temp_pass="";
        for(int i = 0; i < (int)msg.size(); i++){
            if (msg[i] == ',') {
                coma++;
                continue;
            }
            else  if(coma==1){
                temp_ID+=msg[i];
            }
            else if(coma==2){
                temp_pass+=msg[i];
            }
        }
        QString ID_1=QString::number(stoi(temp_ID));
        //AppendMessage(ID_1);
        if (records.count(ID_1)&&(temp_pass==records[ID_1]->getPass())) {
            record = records[ID_1];
            AppendMessage("----------------------------");
            AppendMessage("New Login");
            AppendMessage(QString::fromStdString("Name: " + record->getName() +
                                                 "\nAge:" + to_string(record->getAge()) +
                                                 "\nNational ID: " + to_string(record->getID())));
            AppendMessage("----------------------------");
            QString clientData = QString::fromStdString("k" + record->getName()+ ","+to_string(record->getID()));
            sendToclient(socket, clientData); //send name and nationalID back to client
        }
        else{
            sendToclient(socket, "Q");
        }

    }

}
void TCPSERVER::AppendMessage(QString msg)
{
    ui->textBrowser->append(msg);
    std::ofstream file("log.txt", std::ios_base::app);
    if(!file.is_open()){
        QMessageBox::information(this,"Error","File Not found");
    }
    file<<msg.toStdString()<<std::endl;
    file.close();
}

void TCPSERVER::NewConnection()
{
    while(Serv->hasPendingConnections()){
        AddToSockets(Serv->nextPendingConnection());
    }
}

void TCPSERVER::AddToSockets(QTcpSocket *socket)
{
    sockets.append(socket);
    connect(socket, &QTcpSocket::readyRead, this, &TCPSERVER::readFromSocket);
    connect(socket, &QTcpSocket::disconnected, this, &TCPSERVER::CloseSockcet);
    //write ID of client connected
    AppendMessage("----------------------------");
    AppendMessage("New client connected with ID:"+QString::number(socket->socketDescriptor()));
    AppendMessage("----------------------------");
}

void TCPSERVER::CloseSockcet()
{
    QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(sender());
    int index=sockets.indexOf(socket);
    if(index >-1){
        sockets.removeAt(index);
    }
    socket->deleteLater();
}

void TCPSERVER::sendBalance(QTcpSocket *socket,QString user_msg)
{
    QString balance;
    user_msg.remove(0,1);
    string num=user_msg.toStdString();
    QString ID = QString::number(stoi(num));
    //AppendMessage(ID);
    record=records[ID];
    balance = QString::fromStdString("B" +record->getBalance());
    sendToclient(socket, balance); //sent name and nationalID back to client
}
void TCPSERVER::sendTransactions(QTcpSocket *socket,QString user_msg)
{
    //Send transactions for the client
    string num=user_msg.toStdString();
    QString ID = QString::number(stoi(num));
    record=records[ID];
    stack<float> temp_stack = record->getTransaction();
    int size = temp_stack.size();
    string trans_str = "T";
    while (!temp_stack.empty()) {
        if (temp_stack.top() > 0) trans_str += ("**" + to_string(size) + " Deposite: " + to_string(temp_stack.top()) + "\n");
        else trans_str += ("**" + to_string(size) + " Withdraw: " + to_string(-1*temp_stack.top()) + "\n");
        temp_stack.pop();
        size--;
    }
    sendToclient(socket, QString::fromStdString(trans_str));
}
void TCPSERVER::updateBalance(QTcpSocket *socket,QString trans)
{
    vector<string>Bal_ID=getClientDetails(trans);
    float bal = stof(Bal_ID[0]);
    QString ID=QString::fromStdString(Bal_ID[1]);
    //AppendMessage(QString::fromStdString(to_string(bal)));
    record=records[ID];
    record->setBalance(bal);
    AppendMessage("----------------------------");
    AppendMessage(QString::fromStdString("New Transaction\nName: "+record->getName()+
                                         "\nNational ID:"+to_string(record->getID())+
                                         "\nAmount:"+to_string(bal)));
    AppendMessage("----------------------------");
    QString New_bal=QString::fromStdString("B" + record->getBalance());
    sendToclient(socket, New_bal);
    Bal_ID.clear();
}
vector<string> TCPSERVER::getClientDetails(QString info){
    vector<string> Bal_ID;
    string temp_ID="",temp_bal="";
    int coma=0;
    string msg=info.toStdString();
    for(int i = 0; i < (int)msg.size(); i++){
        if (msg[i] == ',') {
            coma++;
            continue;
        }
        else  if(coma==0){
            temp_bal+=msg[i];
        }
        else if(coma==1) temp_ID+=msg[i];
    }
    Bal_ID.push_back(temp_bal);
    Bal_ID.push_back(temp_ID);
    // AppendMessage(QString::fromStdString(temp_bal));
    // AppendMessage(QString::fromStdString(temp_ID));
    return Bal_ID;
}
void TCPSERVER::AnalyzeClientsInfo()
{
    // Calculate statistics
    float totalBalance = 0;
    int totalClients = records.size();
    int totalDeposits = 0;
    int totalWithdrawals = 0;

    for(auto const&rec : records)
    {
        User_data *recUser=rec.second;
        totalBalance += stof(recUser->getBalance());
        stack<float> transactions = recUser->getTransaction();
        while(!transactions.empty())
        {
            float trans = transactions.top();
            if(trans > 0)
                totalDeposits++;
            else
                totalWithdrawals++;
            transactions.pop();
        }
    }
    // Show statistics
    QString stats = QString("Total Clients: %1\nTotal Deposits: %2\nTotal Withdrawals: %3\ntotalBalance: %4 $")
                        .arg(totalClients)
                        .arg(totalDeposits)
                        .arg(totalWithdrawals)
                        .arg(QString::number(totalBalance, 'f', 3));

    ui->statistics->setText("Statistics:");
    ui->statistics->setText(stats);
    // ui->graph->clearGraphs();;
    // ui->graph->addGraph();
    // ui->graph->graph(0)->addData(totalClients, (int)totalBalance);
    // ui->graph->xAxis->setLabel("totalClients");
    // ui->graph->yAxis->setLabel("totalBalance");
    // ui->graph->xAxis->setRange(0,500);
    // ui->graph->yAxis->setRange(0, 100000);
    // ui->graph->replot();
}
void TCPSERVER::on_statistcs_button_clicked()
{
    AnalyzeClientsInfo();
}
TCPSERVER::~TCPSERVER()
{
    foreach (QTcpSocket* socket, sockets)
    {
        socket->close();
        socket->deleteLater();
    }

    Serv->close();
    Serv->deleteLater();
    delete ui;
}
