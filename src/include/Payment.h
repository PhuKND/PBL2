#include <string>
#include "Customer.h" 
#include "Order.h"
#include "Store.h"

class Payment {
private:
    int PaymentID;
    char* PaymentMethod;
    double PaymentAmount;
    char* PaymentDate;
    char* PaymentStatus;

public:
    Payment(int = 0  , char* = "" ,  double = 0  , char* = " " , char* =" ");
    ~Payment();

    char* GetPaymentID() const;
    void SetPaymentID(const char* &id);

    char* GetPaymentMethod() const;
    void SetPaymentMethod(const char* &method);

    double GetPaymentAmount() const;
    void SetPaymentAmount(double amount);

    char* GetPaymentDate() const;
    void SetPaymentDate(const char* &date);

    char* GetPaymentStatus() const;
    void SetPaymentStatus(const char* &status);

    void MakePayment(const Customer &customer, const Order &order, const Store &store);
};
