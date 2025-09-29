#include "user_data.h"
User_data::User_data(){


}
User_data::User_data(string msg)
{
    msg.erase(0,1);
    //cout<<msg<<endl;;
    int coma=0;
    string temp_age="",temp_ID="",temp_phone="";
    for(int i = 0; i < (int)msg.size(); i++){
        if (msg[i] == ',') {
            coma++;
            continue;
        }
        if(coma == 0) name += msg[i];
        else if(coma == 1) temp_age += msg[i];
        else if(coma == 2) temp_ID += msg[i];
        else if(coma == 3) temp_phone += msg[i];
        else if(coma == 4)  Pass+= msg[i];
    }
    //cout<<temp_ID<<endl;
    try {
        age = std::stoi(temp_age);
        national_ID = std::stoi(temp_ID);
        phone = std::stoi(temp_phone);
    } catch (const std::invalid_argument& e) {
        // Handle invalid argument exception (e.g., log error, set default values)
        std::cerr << "Invalid argument: " << e.what() << std::endl;
        age = 0; // Set default age
        national_ID = 0; // Set default national ID
    }
}

string User_data::getName()
{
    return name;
}


int User_data::getID()
{
    return national_ID;
}

int User_data::getPhone()
{
    return phone;
}
int User_data::getAge()
{
    return age;
}
string User_data::getBalance()
{
    return to_string(balance);
}

string User_data::getPass()
{
    return Pass;
}

void User_data::setBalance(float bal)
{
    balance += bal;
    transactions.push(bal);
}

stack<float> User_data::getTransaction()
{
    return transactions;
}

float User_data::remove_last_trans()
{
    float bal = transactions.top();
    balance -= bal;
    transactions.pop();
    return bal;
}
User_data::~User_data(){

}
