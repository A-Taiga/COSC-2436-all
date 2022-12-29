#ifndef BANK_H_
#define BANK_H_
#include<iostream>
#include<string>
using namespace std;

//Do Not Make Any Changes to This Section
struct Credit_Card{                        
    int acc_id;                                                             //Account ID
    string name;                                                            //Account Name
    int limit;                                                              //Account lIMIT
    double balance;                                                         //Account Balance
};
//-----------------------------------------

class Bank{
    public:
        Bank(int sz); 
        int search(int id);                                                   //Returns to index of an account on the table given the Account Id
        void addAccount(string nm, int id, int lim, int bal);                 //Adds an account into the table 
        void removeAccount(int id);                                           //Removes an Account from the table
        void printTable();                                                    //Prints Current State of the Credit Account Table
        string getName(int id);                                               //Returns the Account Name
        double getBalance(int id) ;                                           //Returns the Account Balance
        int    getLimit(int id);                                              //Returns the Account Limit
  
        bool chargeIt(int id, double price);                                  //Makes a Deduction from the Account
        void makePayment(int id, double payment);                             //Makes a Payment into the Account

        int getSize(){ return numAcc; }
    
    private:
        int numAcc = 0;                                                       //Number of Accounts in the table
        //Create a Dynamic Table called Account Table
        //Your Code Starts Here 
        Credit_Card *Account_Table = nullptr;
        //Your Code Ends Here 
};


#endif