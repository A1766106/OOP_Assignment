#include "Share.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    Share s1("ABP");
    cout << "The Name of this company is: " << s1.Get_Company() << endl;

    return 0;
}