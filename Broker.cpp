#include "Broker.h"
#include "User.h"
#include "Investor.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

Broker::Broker()
{
    User_Name = "Guest";
    User_ID = 0;
    User_Password = "";
    Commission = 0;
    Clients = new Investor[10];
    Client_Count = 0;
}
Broker::Broker(std::string User_Name, int User_ID, std::string User_Password, int Commission)
{
    this->User_Name = User_Name;
    this->User_ID = User_ID;
    this->User_Password = User_Password;
    this->Commission = Commission;
    Clients = new Investor[10];
}
bool Broker::Add_Client(Investor Client)
{
    if(Client_Count < 10)
    {
        Clients[Client_Count] = Client;
        Client_Count++;
        return true;
    }
    return false;
}
Investor *Broker::Get_Current_Clients()
{
    return Clients;
}
void Broker::Set_Commision(int Commission)
{
    this->Commission = Commission;
}
int Broker::Get_Commsion()
{
    return Commission;
}
Broker::~Broker(){}
