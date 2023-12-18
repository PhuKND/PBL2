#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Order.h"
#include "Person.h"
#include"Discount.h"
#include"Statistics.h"
class Order; 
class Discount;
class Customer : public Person
{
private:
    int CustomerID;
    int Point;
    char *CustomerType;
    Vector_Class<Order> orderHistory;
    Vector_Class<Discount> discounts;
    Statistics statistics ;
public:
    Customer();
    Customer(int, char *, char *, int, Date, char *, char *, char *, int, char *);
    ~Customer();
    Vector_Class<Order> &getOrderHistory();
    int GetCustomerID() const;
    void SetCustomerID(int);
    Statistics &getStatistics() ;
    int GetPoint() const;
    void SetPoint(int);

    char *getCustomerType() const;
    void setCustomerType(char *type);
    void Show_Orders_History(std::ostream &o);
    template <class T>
    friend std::ostream &operator<<(std::ostream &, const Customer &);
    void Display();
    void Display_01(std::ostream &);
    void GetInformation();
    friend std::istream &operator>>(std::istream &, Customer &);
    void WriteDataToFile(std::ostream &file) const ;
    void ReadDataFromFile(std::istream &file) ;
    void add_to_orders(const Order &);
    void BuyProduct(Order &order, Food &obj, int sl);
    void BuyProduct(Order &order, ElectricalProduct &obj, int sl);
    void BuyProduct(Order &order, Houseware &obj, int sl);
    Order &Last_Order();
    int getOrd_Size();
    void AddDiscount(Discount &discount);
    Vector_Class<Discount> &GetDiscounts();
    void ApplyDiscounts(Order &order);
    void UpdateStatistics(Time& start, Time& end) ; 
    void ViewStatistics(Time& start ,Time& end); 
};
#endif