// Account.cpp
//
// This is the source of Account Class
// This retrieves account status

#include "Account.h"
#include <iostream>
using namespace std;

//Constructor 
Account::Account(const string& name, const string& S){
    username = name;
    status = S;
}

//Function to retreive account status
string Account::getStatus() const {
    return status;
}

//Destructor
Account::~Account() {
    cout << "Account removed.\n";
}