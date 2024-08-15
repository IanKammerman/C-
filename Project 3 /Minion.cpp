// Minion.cpp
//
// This is the source of Minion Class
// This calculates the tallest minion, minion count, and banana count
#include <string>
#include <iostream>
using namespace std;
#include "Minion.h"

//Initialize static member
int Minion::minionCount = 0;

//Constructor
Minion::Minion(string N, float H, int E, int Bananas){
    name = N;
    height = H;
    eyes = E;
    bananasOwned = Bananas;
    minionCount += 1;
}
//Compare heights
bool Minion::operator>(const Minion &h) const {
    return this-> height > h.height;
}
//Compare heights
bool Minion::operator<(const Minion &h) const{
    return this-> height < h.height;
}
//Minion count output
void Minion::printMinionCount(){
    cout << minionCount << " minions created." << endl;
}
//Pre-increment operator
Minion& Minion::operator++(){
    this->bananasOwned++;
    return *this;
}
//Post-increment operator 
Minion Minion::operator++(int){
    Minion temp = *this;
    this->bananasOwned++;
    return temp;
}
//Getter function for Minion name
string Minion::getName() const{
    return name;
}
//Getter function for bananas owned
int Minion::getBananas() const{
    return bananasOwned;
}