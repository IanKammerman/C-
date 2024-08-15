#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
#include "Minion.h"

//Overload << operator
ostream& operator<<(ostream& output, const Minion &minion){
    output << "The minion " << minion.name << " is " << minion.height << " inches tall, has " << minion.eyes << " eye(s), and owns " << minion.bananasOwned << " banana(s).";
    return output;
}
//Function to initialize minions
Minion createMinion(ifstream& myfile){
    string name;
    float height;
    int eyes, bananasOwned;
    myfile >> name >> height >> eyes >> bananasOwned;
    return Minion(name, height, eyes, bananasOwned);
}

int main(){
    //open file
    ifstream myfile("Minions.txt");

    //Initialize variables
    string name;
    float height;
    int eyes;
    int bananasOwned;

    //Check if file is open
     if (!myfile.is_open()){
        cout << "File did not open" << endl;
        return 0;
    }
    //Read data from text file and initialize
    myfile >> name;
    myfile >> height;
    myfile >> eyes;
    myfile >> bananasOwned;
    //Initialize const minion 1
    const Minion minion1(name, height, eyes, bananasOwned);
    //Call function to initialize minion2 and minion3
    Minion minion2 = createMinion(myfile);
    Minion minion3 = createMinion(myfile);

    //Close file
    myfile.close();

    //Output
    //Find the taller minion
    if (minion1 > minion2) {
        cout << minion1.getName() << " is taller than " << minion2.getName();
    } 
    if (minion2 < minion3) {
        cout << minion3.getName() << " is taller than " << minion2.getName();
    }
    cout << endl << endl;

    //Print minion2 values
    cout << minion2 << "\n";
    cout << minion2.getName() << " getting bananas" << "\n";
    cout << "The minion now has " << (++(++minion2)).getBananas() << " banana(s).\n" << endl; 
    //Print minion3 values
    cout << minion3 << "\n";
    cout << minion3.getName() << " getting bananas" << "\n";
    cout << "Before getting bananas, the minion had " << minion3++.getBananas() << " banana(s).\n";
    cout << "After getting bananas, the minion has " << minion3.getBananas() << " banana(s).\n" << endl;
    //Print minion count
    minion3.printMinionCount();
}
