#ifndef INVESTOR_H
#define INVESTOR_H
#include "User.h"
#include "Broker.h"
#include "Share.h"
#include "Currency.h"
#include <iostream>
#include <string>
#include <stdlib.h>

class Investor: public User
{
    protected:
        Broker Investor_Broker;
        Share *Portfolio; // This will need to be changed to include currencies as well
        int Cost_Base;
        int Share_Count;
    public:
        Investor(); // Default Constructor
        Investor(std::string User_Name, int User_ID, std::string User_Password, Broker Investor_Broker); // Constructor
        int Get_Cost_Base(); // Returns cost base
        void Change_Cost_Base(int Change); // Increases or decreases cost base
        void Set_Broker(Broker Chosen_Broker); // Sets broker
        Broker Return_Broker(); // Function that returns broker
        Share *Get_Portfolio(); // Functions return broker
        void Buy(std::string ASX_code, int Cost_Base); // Investor buys stock
        void Sell(std::string ASX_code); // Investor sells stock
        ~Investor();
};


#endif