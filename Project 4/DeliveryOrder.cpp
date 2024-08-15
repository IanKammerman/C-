// DeliveryOrder.cpp
//
// This is the source of DeliveryOrder Class
// This prints the receipt, calculates order balance, and returns order count

#include <string>
#include <iostream>
using namespace std;
#include "DeliveryOrder.h"

//Initialize static variables
int DeliveryOrder::orderCount = 0;
const float DeliveryOrder::taxRate = 0.09;
const float DeliveryOrder::deliveryRate = 2.00;

//Constructor 
DeliveryOrder::DeliveryOrder(string N, string D, string PN, float M) : orderBalance(0.0) {
    name = N;
    date = D;
    phone = PN;
    miles = M;
    orderCount += 1;
}

//Print receipt
void DeliveryOrder::receipt() const{
    cout << "Order Detail:" << "\n";
    cout << "\tName: " << name << "\n";
    cout << "\tDate: " << date << "\n";
    cout << "\tPhone: " << phone << "\n";
    cout << "\tOrder Balance: $" << orderBalance << endl;
}

//Calcualte total balance 
float DeliveryOrder::getTotalBalance() const{
    return orderBalance * (1 + taxRate) + miles * deliveryRate;
}

//Return order count
int DeliveryOrder::getOrderCount(){
    return orderCount;
}

//Destructor
DeliveryOrder::~DeliveryOrder(){
    cout << "DeliveryOrder destroyed.\n";
}