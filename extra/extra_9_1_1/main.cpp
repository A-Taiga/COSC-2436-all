#include <iostream>
using namespace std;

#include "Bank.h"


//Don't make any changes to this file
int main(){

    Bank BofA(0);
    BofA.addAccount("Alejandro Alexis", 191827, 1000, 25000);
    BofA.addAccount("Heron Ana", 198372, 15000, 150000);
    BofA.addAccount("Joshi Jose", 178903, 2000, 6500);
    BofA.addAccount("Thomas Maria", 177536, 6000, 10000);
    BofA.addAccount("Bernal Austin", 128938, 3400, 250000);
    BofA.addAccount("Okafor Chinedu", 118836, 24600, 300000);
    BofA.addAccount("Khan Shadha", 134536, 10000, 150000);
    BofA.addAccount("Jobins Jose", 167874, 9050, 15000);
    BofA.addAccount("Pena Gonzalo", 177537, 3000, 20500);
    BofA.addAccount("Okafor Chinedu", 143656, 1000, 7000);

    cout << endl << endl;

    BofA.printTable();
    
    cout << endl << endl;

    cout << "Account Details " << BofA.getName(118836) << " has " << BofA.getBalance(118836) << " in their Account" << endl;
    cout << "Account Details " << BofA.getName(177537) << " has " << BofA.getBalance(177537) << " in their Account" << endl;
    cout << "Account Details " << BofA.getName(128938) << " has " << BofA.getBalance(128938) << " in their Account" << endl;
    cout << "Account Details " << BofA.getName(191827) << " has " << BofA.getBalance(191827) << " in their Account" << endl;

    cout << endl << endl;

    BofA.removeAccount(118836);
    BofA.removeAccount(167874);
    BofA.removeAccount(143656);
    BofA.removeAccount(118836);

    cout << endl;
    
    BofA.chargeIt(128938, 3500);
    BofA.chargeIt(191827, 500);
    BofA.makePayment(178903,  150000);
    
    cout << endl;
    
    BofA.printTable();

    

    return 0;
}
//-------------------------------------------------------------