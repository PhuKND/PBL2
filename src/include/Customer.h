#pragma once
#include "Person.h"
// #include "Order.h"
#include <vector>

class Customer : public Person
{
private:
    int CustomerID;
    int Point;
    char *CustomerType;

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

    friend std::ostream &operator<<(ostream &, const Customer &);
    void Display();
    void Display_01(ostream &);
    void GetInformation();
    friend std::istream &operator>>(istream &, Customer &);
    void WriteDataToFile(std::ostream &file) const override;
    void ReadDataFromFile(std::istream &file) override;
};