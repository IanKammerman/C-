#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
#include "DeliveryOrder.h"
#include "BobaOrder.h"
#include "FoodOrder.h"
#include "Account.h"
#include "InvalidInput.h"

//Function to calculate discount
float applyDiscount(DeliveryOrder* order, const Account& account) {
    string status = account.getStatus();

    //Apply discount for Owner 
    if (status == "Owner") {
        float totalBalance = order->getTotalBalance();
        return 0.1 * totalBalance;
    //Apply discount for VIP
    } 
    else if (status == "VIP") {
        float vipDiscount = order->VIPdiscount();
        float totalBalance = order->getTotalBalance();
        return vipDiscount * totalBalance;
    } 
    //Apply no discount for regular customers
    else{
        return order->getTotalBalance();
    }
}

int main(){
    //Create accounts for Stuart, Kevin and Bob
    const Account ownerAccount("Stuart", "Owner");
    Account vipAccount("Kevin", "VIP");
    Account regularAccount("Bob");

    //Create DeliveryOrder pointer
    DeliveryOrder* order;

    //Initialize Kevin's order and assign Kevin's address to pointer order
    cout << "Kevin is placing order.\n";
    BobaOrder Kevin("Kevin", "11/20/2023", "123-456-0000", 10.4, "M Tea");
    order = &Kevin;
    try {
        Kevin.addDrink("Green Tea Latte");
        Kevin.addDrink("Brown Sugar Pearl Milk", false);
        Kevin.addDrink("Brown Sugar Boba Milk", false, 2);
        Kevin.addDrink("Iron Goddess");
    } catch (const InvalidInput& InvalidDrink) {
        InvalidDrink.reason();
        cout << "\nNot serving requested drinks. Drink order ignored.\n\n";
    }

    //Output Kevin's order
    cout << fixed << setprecision(2);
    order->receipt();
    cout << "Balance: $" << order->getTotalBalance() << endl;
    cout << "Discounted Balance: $" << applyDiscount(order, vipAccount) << endl << endl;

    //Initalize Stuart's order and assign's Stuart's address to pointer order
    cout << "Stuart is placing order.\n";
    FoodOrder Stuart("Stuart", "11/20/2023", "123-456-1111", 25.5, "Tavern Green");
    order = &Stuart;
    try {
        Stuart.addFood("Thick Cauliflower Steaks", 1, true);
        Stuart.addFood("Organic Scottish Salmon");
        Stuart.addFood("Rack of Lamb", 0, true);
    } catch (const InvalidInput& InvalidFood) {
        InvalidFood.reason();
        cout << "Not serving requested food. Food order ignored.\n\n";
    }

    //Print Stuart's order
    order->receipt();
    cout << "Balance: $" << order->getTotalBalance() << endl;
    cout << "Discounted Balance: $" << applyDiscount(order, ownerAccount) << endl << endl;
    cout << "Bob decided to log in to his account and see whether he can afford ordering the same order as Stuart.\n";

    //Print Bob's attempt of ordering the same food as Stuart
    order->receipt();
    cout << "Balance: $" << order->getTotalBalance() << endl;
    cout << "Discounted Balance: $" << applyDiscount(order, regularAccount) << endl;
    cout << "Bob upset, cancelling order :(\n\n";
    cout << "Total order placed: 2.\n\n";

    return 0;
}