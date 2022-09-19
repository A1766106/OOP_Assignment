#include "Investor.h"
#include "User.h"
#include "Broker.h"
#include "Share.h"
#include "Currency.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

Investor::Investor()
{
    User_Name = "Guest";
    User_ID = 0;
    User_Password = "";
    Investor_Broker = Broker();
    Cost_Base = 0;
    Share_Count = 0;
    Portfolio = new Share[20]; 
}
Investor::Investor(std::string User_Name, int User_ID, std::string User_Password, Broker Investor_Broker)
{
    User_Name = User_Name;
    User_ID = User_ID;
    User_Password = User_Password;
    Investor_Broker = Investor_Broker;
    Cost_Base = 0;
    Share_Count = 0;
    Portfolio = new Share[20]; 
}
int Investor::Get_Cost_Base()
{
    return Cost_Base;
}
void Investor::Change_Cost_Base(int Change)
{
    Cost_Base = Cost_Base + Change;
}
void Investor::Set_Broker(Broker Chosen_Broker)
{
    Investor_Broker = Chosen_Broker;
}
Broker Investor::Return_Broker()
{
    return Investor_Broker;
}
Share *Investor::Get_Portfolio()
{
    return Portfolio;
}
void Investor::Buy(string ASX_code, int Cost_Base)
{
    if(Share_Count<20)
    {
        Portfolio[Share_Count] = Share(ASX_code);
        Share_Count++;
        Change_Cost_Base(Cost_Base);
        cout << "Share added" << endl;
    }
    else
    {
        cout << "You have the maximum amount of shares" << endl;
    }
}
void Investor::Sell(string ASX_code)
{
    for(int i=0;i<20;i++)
    {
        if(ASX_code == Portfolio[i].Get_Code())
        {
            cout << "You sold " << ASX_code << endl;
            Portfolio[i] = Share();
        }
    }
    Share *Temp_Portfolio = new Share[20];
    int Temp_Counter = 0;
    for(int i=0;i<20;i++)
    {
        if (Portfolio[i].Get_Code() != "N/A")
        {
            Temp_Portfolio[Temp_Counter] = Portfolio[i];
            Temp_Counter++;
        }
    }
    Portfolio = Temp_Portfolio;

}

Investor::~Investor(){}