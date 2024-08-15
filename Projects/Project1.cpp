#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

 struct userAccount { //Struct to store information
    string username;
    string nationality;
    int age;
    double accountBalance;
};

int main(){
    userAccount input[20]; //Create struct with storage up to 20 accounts
    cout << "Please enter information to database in the format of <username> <nationality> <age> <accountbalance>, separated each user by a newline: " << endl;
    //Ask for input
    string username;
    string nationality;
    int age; 
    double accountBalance;
    int count = 0; //Initialize variables 
    double highestbalance = 0;
    double totalbalance = 0;
    int swedishcount = 0;
    int under21 = 0;
    while (cin >> username >> nationality >> age >> accountBalance){ //Store data from input into struct
        userAccount account;
        account.username = username;
        account.nationality = nationality;
        account.age = age;
        account.accountBalance = accountBalance;
        if (accountBalance > highestbalance){ //Loop to find highest account balance
            highestbalance = accountBalance;
        }
        totalbalance += accountBalance; //Calculate the value of all accounts balances combined
        if (nationality == "Swedish" or nationality == "swedish"){ //Check  if anybody is Swedish
            swedishcount += 1;
        }
        if (age < 21){ //Check if anybody is under 21
            under21 += 1;
        }
        input[count] = account; //Add count to move onto next struct
        count++;
    }
        //Output
        cout << "Q: What is the highest account balance among all users? \n";
        cout << setprecision(1) << fixed; //Set precision to 1 decimal place
        cout << "A: $" << highestbalance << "\n";
        cout << "Q: What's the sum of account balance of all users? \n";
        cout << setprecision(2) << fixed; //Set precision to 2 decimal places
        cout << "A: $" << totalbalance << "\n";
        cout << "Q: How many users come from Sweden? \n";
        cout << "A: " << swedishcount << "\n";
        cout << "Q: Do we have any user younger than 21? \n";
        if (under21 > 0){ //Check if any user is under 21 and print yes or no
            cout << "A: Yes \n";
        }
        else{
            cout << "A: No \n";
        }
    return 0;
}