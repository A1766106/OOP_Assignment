#include "Currency.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

Currency::Currency()
{
    Code = "N/A";
    Currency_Name = "N/A";
    Active_Status = 0;
}

Currency::Currency(std::string Code)
{
    this->Code = Code;
    Set_Details(Code);
}

std::string Currency::Get_Currency_Name()
{
    return Currency_Name;
}
std::string Currency::Get_Code()
{
    return Code;
}
bool Currency::Get_Active_Status()
{
    if(Active_Status == 1)
    {
        return true;
    }
    return false;
}
void Currency::Set_Details(std::string Code)
{
    ifstream CurrencyList;
    CurrencyList.open("Currencies.csv");
    if(!CurrencyList.is_open()){
        Currency_Name = "N/A";
        Active_Status = 0;
        cout << "File Failed To Open" << endl;
    }
    
    string Temp_Code;
    string Temp_Currency_Name;
    int Temp_Active_Status;
    string line;
    string myLine;

    while(getline(CurrencyList, line)){
        stringstream ss(line);
        getline(ss, Temp_Currency_Name, ',');
        getline(ss, Temp_Code, ',');
        getline(ss, myLine, ',');
        Temp_Active_Status = stoi(myLine);
        if(Temp_Code == Code)
        {
            Currency_Name = Temp_Currency_Name;
            Active_Status = Temp_Active_Status;
            break;
        }
    }
    CurrencyList.close();  
}
Currency::~Currency(){}