// DeliveryOrder.h
//
// This is the declarataion of DeliveryOrder class
// Which has the values of name, date, phone, and miles
// Member functions print receipt, calculate total balance, and return order count 

#ifndef DeliveryOrder_H
#define DeliveryOrder_H
using namespace std;
class DeliveryOrder{

//Public members of class DeliveryOrder
    public:
        DeliveryOrder(string N, string D, string PN, float M);
        ~DeliveryOrder();
        virtual void receipt() const;
        virtual float getTotalBalance() const;
        static int getOrderCount();
        virtual float VIPdiscount() const = 0;


//Protected members of class DeliveryOrder
    protected:
        float orderBalance;
//Private members of class DeliveryOrder
    private:
        string name;
        string date;
        string phone;
        float miles;
        static int orderCount;
        static const float taxRate;
        static const float deliveryRate;
};

#endif