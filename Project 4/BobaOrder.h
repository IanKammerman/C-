// BobaOrder.h
//
// This is the declarataion of BobaOrder class
// Which has the values of DeliveryOrder class, shopName, and drinksCount
// Member functions ovveride functions from deliveryOrder, add drinks, invalid input, and add these values to orderBalance

#ifndef BOBAORDER_H
#define BOBAORDER_H
#include <string>
#include "DeliveryOrder.h"
using namespace std;

//Public inheritance of class DeliveryOrder
class BobaOrder : public DeliveryOrder {
//Public members of class BobaOrder
    public:
        BobaOrder(const string& N, const string& D, const string& PN, float M, const string& shop);
        ~BobaOrder();
        void receipt() const;
        float VIPdiscount() const;
        void addDrink(const string& drinkName, bool addBoba = true, int count = 1);
//Private members of class BobaOrder
    private:
        string shopName;
        static int drinksCount;
        float orderBalance;
};

#endif