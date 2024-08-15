// FoodOrder.h
//
// This is the declarataion of FoodOrder class
// Which has the values of DeliveryOrder class, restarauntName, and food count
// Member functions ovveride functions from deliveryOrder, add food, invalid input, add these values to orderBalance, and return food count

#ifndef FOODORDER_H
#define FOODORDER_H
#include <string>
#include "DeliveryOrder.h"
using namespace std;

//Public inhertiance of class DeliveryOrder
class FoodOrder : public DeliveryOrder {
//Public members of class FoodOrder
    public:
        FoodOrder(const string& N, const string& D, const string& PN, float M, const string& restaurant);
        ~FoodOrder();
        void receipt() const;
        float VIPdiscount() const;
        void addFood(const string& mainCourse, int numOfSides = 0, bool addSoup = false);
//Private members of class FoodOrder
    private:
        string restaurantName;
        int foodCount;
        float orderBalance;
};

#endif