#ifndef CURRENCY_H
#define CURRENCY_H
#include <iostream>
#include <string>

class Currency
{
    protected:
        std::string Code;
        std::string Currency_Name;
        int Active_Status;
    public:
        Currency(); // Default Constructor
        Currency(std::string Code); // Constructor
        std::string Get_Currency_Name(); // Function which returns Currency Name
        std::string Get_Code(); // Function which returns Currency Code
        bool Get_Active_Status(); // Function which returns active status
        void Set_Details(std::string Code); // Function that sets Currency name and code from csv file
        ~Currency();
};

#endif