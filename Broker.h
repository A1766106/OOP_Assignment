#ifndef BROKER_H
#define BROKER_H
#include "User.h"
#include "Investor.h"
#include <iostream>
#include <string>
#include <stdlib.h>

class Broker: public User
{
    private:
        int Commission;
        Investor *Clients;
        int Client_Count;
    public:
        Broker(); // Default constructor
        Broker(std::string User_Name, int User_ID, std::string User_Password, int Commission); // Constructor noting a max of 10 clients
        bool Add_Client(Investor Client); // Add's client
        Investor *Get_Current_Clients(); // Returns list of clients
        void Set_Commision(int Commission); // Changes Brokers Commision
        int Get_Commsion(); // Changes Brokers Commision
        ~Broker(); // Destructor
};

#endif