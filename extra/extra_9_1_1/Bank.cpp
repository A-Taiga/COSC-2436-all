#ifndef CREDIT_CARD_H
#define CREDIT_CARD_H


#include "Bank.h"
#include <string>

using namespace std;

Bank::Bank(int sz){
    numAcc = sz;     //Initializes Account to SZ variable
}

//Create an Function to Add an Account to the Table
void Bank::addAccount(string nm, int id, int lim, int bal){
    //Your Code Starts Here 
    Credit_Card temp;
    Credit_Card *newTable = new Credit_Card[numAcc+1];

    temp.name = nm;
    temp.acc_id = id;
    temp.limit = lim;
    temp.balance = bal;

    if(this->Account_Table == nullptr) {
        newTable[0] = temp;
        this->Account_Table = newTable;
    } else {
        for(int i = 0; i < numAcc; i++) {
            newTable[i] = Account_Table[i];
        }
        delete[] Account_Table;
        Account_Table = nullptr;
        newTable[numAcc] = temp;
        Account_Table = newTable;
    }
    numAcc+=1;
    cout << temp.name << " Account has been created" << endl;
    //Your Code Ends Here    
}

//Create an Function to Add an Account to the Table
void Bank::removeAccount(int id){
   //Your Code Starts Here 
    Credit_Card *newTable = new Credit_Card[numAcc-1];
    Credit_Card temp;

    if(search(id) == -1) {
        cout << "Account was not found" << endl;
        return;
    }

    for(int i = search(id); i < numAcc; i++) {
        temp = Account_Table[i+1];
        Account_Table[i] = temp;
    }
    for(int i = 0; i < numAcc-1; i++) {
        newTable[i] = Account_Table[i];
    }
    delete[] Account_Table;
    Account_Table = nullptr;
    Account_Table = newTable;
    numAcc--;
    cout << "Account Removed" << endl;


    //Your Code Ends Here     
}   

int Bank::search(int id){
    for(int i = 0; i < numAcc; i++){
        if(Account_Table[i].acc_id == id){
            return i;
        }
    }

    return -1;
}

void Bank::printTable(){
    int count = 0;
    for(int k = 0; k < 65; k++){
        cout << "-";
    }
    cout << endl; 
    for(int i = 0; i < numAcc; i++){
       cout << "Name: " << Account_Table[i].name;

       for(int j = 0; j < 18 - (Account_Table[i].name).size(); j++){
            cout << " ";
       }
       
       cout << "|  Account Id: " << Account_Table[i].acc_id << " | Current Balance: " << Account_Table[i].balance << endl; 

       for(int k = 0; k < 65; k++){
            cout << "-";
       }

       cout << endl;     

    }

    
    
}

string Bank::getName(int id){
    return Account_Table[search(id)].name;
}

double Bank::getBalance(int id){
    return Account_Table[search(id)].balance;
}


bool Bank::chargeIt(int id, double price){
    //Your Code Starts Here 

    for(int i = 0; i < numAcc; i++) {
        if(Account_Table[i].acc_id == id) {
            Account_Table[i].balance += price;
            break;
        } else {
            return false;
        }
    }
    return true;
    //Your Code Ends Here    
}

void Bank::makePayment(int id, double payment){
    //Your Code Starts Here 
    if(search(id) == -1) {
        cout << "Accound was not found" << endl;
    } else {
        if( Account_Table[search(id)].balance < payment) {
            cout << "Limit Exceeded: Transaction Cancelled" << endl;
        } else {
            Account_Table[search(id)].balance -= payment;
        }
    }
    //Your Code Ends Here    
}



#endif