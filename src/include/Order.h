#ifndef ORDER_H
#define ORDER_H
#include "Food.h"
#include "ElectricalProduct.h"
#include "Houseware.h"
#include "Vector_Class.h"
class Order
{
private:
    int OrderID;
    int CustomerID;

    int totalAmount;
    char *orderDate;
    char *orderStatus;
    
    char *PaymentMethod;
    char *ShippingAddress;
    bool delivery;
    static int numberofOrder ; 
     Vector_Class<Food> OrderedFood;
    Vector_Class<ElectricalProduct> OrderedElectricalProduct;
    Vector_Class<Houseware> OrderedHouseware;
public:
    static int getNumberOrder() ; 
    static void setNumberOrder() ; 
    bool HoanThanh = false ; 
    void Order_Food(Food& ) ;
    void Order_ElectricalProduct(ElectricalProduct&); 
    void Order_Houseware(Houseware& ); 
    Order(int = 0, int = 0, int = 0, char * = "", char * = "", bool = false, char * = " ", char * = "", bool = false);
    ~Order();
    int GetOrderID() const;
    void SetOrderID(int OrderID);
    int getCustomerID() ;
void setCustomerID(int);
    void SetOrderProduct(Vector_Class<Product> OrderProduct);
    int GetTotalAmount() const;
    void SetTotalAmount(int totalAmount);
    char *GetOrderDate() const;
    void SetOrderDate(char *orderDate);
    char *GetOrderStatus() const;
    void SetOrderStatus(char *orderStatus);
    char *GetPaymentMethod() const;
    void SetPaymentMethod(char *PaymentMethod);
    char *GetShippingAddress() const;
    void SetShippingAddress(char *ShippingAddress);
    bool useDelivery();
    void Display(std::ostream &o);
    int CalculateTotalAmount();
};
#endif
