// Account.h
//
// This is the declarataion of Account class
// Which has the values of username and status
// Member function returns account status 

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
using namespace std;

class Account {
//Public members of class Account
    public:
        Account(const string& username, const string& status = "Regular");
        ~Account();
        string getStatus() const;

//Private members of class Account
    private:
        string username;
        string status;
};

#endif // ACCOUNT_H