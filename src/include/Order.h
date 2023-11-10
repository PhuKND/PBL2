#include "Product.h"
#include"Vector.h"
#include <string>
class Order
{
private:
    int OrderID;
    int CustomerID;
    std::vector<Product> OrderedProduct;
    int totalAmount;
    char* orderDate;
    char* orderStatus;
    bool HoanThanh ;  
    char* PaymentMethod;
    char* ShippingAddress;
    bool delivery ; 
public:
    Order(int = 0  , int = 0 , int = 0  , char* = "" , char* = "" ,  bool = false  ,char* =" " , char* = "" , bool = false );
    ~Order();
    int GetOrderID() const;
    void SetOrderID(int OrderID);
    char* GetCustomer() const;
    void SetCustomer(char* Customer);
    Vector<Product> GetOrderProduct() const;
    void SetOrderProduct(Vector<Product> OrderProduct);
    int GetTotalAmount() const;
    void SetTotalAmount(int totalAmount);
    char* GetOrderDate() const;
    void SetOrderDate(char* orderDate);
    char* GetOrderStatus() const;
    void SetOrderStatus(char* orderStatus);
    char* GetPaymentMethod() const;
    void SetPaymentMethod(char* PaymentMethod);
    char* GetShippingAddress() const;
    void SetShippingAddress(char* ShippingAddress);
    bool useDelivery() ; 
};
