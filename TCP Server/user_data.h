#ifndef USER_DATA_H
#define USER_DATA_H
#include <iostream>
#include <string>
#include <stack>
#include <QString>
using namespace std;
class User_data
{
private:
    string name;
    int age;
    float balance;
    string Pass;
    int national_ID;
    int phone;
    stack<float> transactions;
public:
    User_data();
    User_data(string msg);
    string getName();
    int getAge();
    int getID();
    int getPhone();
    string getBalance();
    string getPass();
    void setBalance(float bal);
    stack<float> getTransaction();
    float remove_last_trans();
    ~User_data();
};

#endif // USER_DATA_H
