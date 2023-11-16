#pragma once
#include "Person.h"
#include "Order.h"

class Customer : public Person
{
private:
    int CustomerID;
    int Point;
    char *CustomerType;
    Vector_Class<Order> orderHistory;

public:
    
    Customer();
    Customer(int, char *, char *, int, char *, char *, char *, char *, int, char *);
    ~Customer();

    int GetCustomerID() const;
    void SetCustomerID(int);

    int GetPoint() const;
    void SetPoint(int);

    char *getCustomerType() const;
    void setCustomerType(char *type);

    // void AddToPurchaseHistory(const Order& order);

    // void ReturnProduct(Order& order, const Product& product);

    // void ExchangeProduct(Order& order, const Product& oldProduct, const Product& newProduct);

    // void MakePayment(Order& order);

    // void ViewOrderHistory() const;

    // void ViewPurchaseHistory() const;
    template <class T>

    friend std::ostream &operator<<(ostream &, const Customer &);
    void Display();
    void Display_01(ostream &);
    void GetInformation();
    friend std::istream &operator>>(istream &, Customer &);
    void WriteDataToFile(std::ostream &file) const override;
    void ReadDataFromFile(std::istream &file) override;
    void add_to_orders(const Order&); 
    void BuyProduct(Order& order, Food& obj, int sl);
    void BuyProduct(Order& order,  ElectricalProduct& obj, int sl);
    void BuyProduct(Order& order, Houseware& obj, int sl);
    Order Last_Order() ; 
    int getOrd_Size() ; 
};
 