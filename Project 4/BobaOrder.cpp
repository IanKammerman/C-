// BobaOrder.cpp
//
// This is the source of BobaOrder Class
// This overrides the receipt output function, calculates order balance, and returns order count

#include "BobaOrder.h"
#include <iostream>
#include "InvalidInput.h"

using namespace std;

//Initialize static member
int BobaOrder::drinksCount = 0;

//Constructor
BobaOrder::BobaOrder(const string& N, const string& D, const string& PN, float M, const string& shop) : DeliveryOrder(N, D, PN, M), shopName(shop), orderBalance(0.0) {}

//Overload receipt function
void BobaOrder::receipt() const {
    DeliveryOrder::receipt();
    cout << "\tDrinks Count: " << drinksCount << endl;
}

//Calculate VIP discount
float BobaOrder::VIPdiscount() const {
    if (drinksCount > 10)
        return 0.8;
    else if (drinksCount > 5)
        return 0.9;
    else if (drinksCount > 2)
        return 0.95;
    else
        return 1.0;
}

//Add drink to order, total the cost for the order, and keep track of drink count
void BobaOrder::addDrink(const string& drinkName, bool addBoba, int count) {
    float cost = 0.0;
    if (drinkName == "Green Tea Latte") {
        cost = count * 5.8;
    } else if (drinkName == "Brown Sugar Boba Milk") {
        cost = count * 7.8;
    } else if (drinkName == "Brown Sugar Pearl Milk") {
        cost = count * 9.8;
    } else {
        throw InvalidInput(drinkName);
    }

    if (addBoba == true) {
        cost += 1.00;
    }
    drinksCount += count;
    DeliveryOrder::orderBalance += cost;
}

//Destructor
BobaOrder::~BobaOrder() {
    cout << "BobaOrder destroyed.\n";
}