// FoodOrder.cpp
//
// This is the source of FoodOrder Class
// This overrides the receipt output function, calculates order balance, and returns order count

#include "FoodOrder.h"
#include <iostream>
#include "InvalidInput.h"
using namespace std;

//Constructor
FoodOrder::FoodOrder(const string& N, const string& D, const string& PN, float M, const string& restaurant)
    : DeliveryOrder(N, D, PN, M), restaurantName(restaurant), foodCount(0), orderBalance(0.0) {}

//Overload receipt 
void FoodOrder::receipt() const {
    DeliveryOrder::receipt();
    cout << "\tFood Count: " << foodCount << endl;
}

//Calculate VIP discount
float FoodOrder::VIPdiscount() const {
    if (orderBalance > 50)
        return 0.8;
    else if (orderBalance > 30)
        return 0.9;
    else if (orderBalance > 20)
        return 0.95;
    else
        return 1.0;
}

//Add food to order, calculate total cost, and keep track of order count
void FoodOrder::addFood(const string& mainCourse, int numOfSides, bool addSoup) {
    float cost = 0.0;
    if (mainCourse == "Thick Cauliflower Steaks") {
        cost = 15.0;
    } else if (mainCourse == "Rack of Lamb") {
        cost = 38.0;
    } else if (mainCourse == "Organic Scottish Salmon") {
        cost = 23.0;
    } else if (mainCourse == "Grilled Lobster Risotto") {
        cost = 46.0;
    } else {
        throw InvalidInput(mainCourse);
    }

    if (addSoup) {
        cost += 5.0;
    }

    cost += numOfSides * 6.0; 
    DeliveryOrder::orderBalance += cost;
    foodCount += 1;
}

//Destructor
FoodOrder::~FoodOrder() {
    cout << "FoodOrder destroyed.\n";
}