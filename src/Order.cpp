#include "include/Order.h"

Order::Order(int OrderID, int CustomerID, int totalAmount, char *orderDate, char *orderStatus, bool HoanThanh, char *PaymentMethod, char *ShippingAddress, bool delivery)
{
    this->OrderID = OrderID;
    this->CustomerID = CustomerID;
    this->totalAmount = totalAmount;
    this->orderDate = orderDate;
    this->orderStatus = orderStatus;
    this->HoanThanh = HoanThanh;
    this->PaymentMethod = PaymentMethod;
    this->ShippingAddress = ShippingAddress;
    this->delivery = delivery;
}
int Order::numberofOrder = 0;

Order::~Order()
{
    // Destructor implementation
}
 int Order::getNumberOrder() {
    return numberofOrder ; 
}
void Order::setNumberOrder(){
  numberofOrder++ ; 
}
int Order::GetOrderID() const
{
    return OrderID;
}
int Order::getCustomerID() {
    return CustomerID; 
}
void Order::setCustomerID(int id){
    this -> CustomerID = id ; 
}
void Order::SetOrderID(int OrderID)
{
    this->OrderID = OrderID;
}

int Order::GetTotalAmount() const
{
    return totalAmount;
}

void Order::SetTotalAmount(int totalAmount)
{
    this->totalAmount = totalAmount;
}

char *Order::GetOrderDate() const
{
    return orderDate;
}

void Order::SetOrderDate(char *orderDate)
{
    this->orderDate = orderDate;
}

char *Order::GetOrderStatus() const
{
    return orderStatus;
}

void Order::SetOrderStatus(char *orderStatus)
{
    this->orderStatus = orderStatus;
}

char *Order::GetPaymentMethod() const
{
    return PaymentMethod;
}

void Order::SetPaymentMethod(char *PaymentMethod)
{
    this->PaymentMethod = PaymentMethod;
}

char *Order::GetShippingAddress() const
{
    return ShippingAddress;
}

void Order::SetShippingAddress(char *ShippingAddress)
{
    this->ShippingAddress = ShippingAddress;
}

bool Order::useDelivery()
{
    return delivery;
}
void Order::Order_Houseware(Houseware &obj)
{
    OrderedHouseware.pushBack(obj);
}
void Order::Order_ElectricalProduct(ElectricalProduct &obj)
{
    OrderedElectricalProduct.pushBack(obj);
}
void Order::Order_Food(Food &obj)
{
    OrderedFood.pushBack(obj);
}
void Order::Display(std::ostream &o)
{
    int total;
    int stt = 1;
    o << "===========================" ; 
    o << "INVOICE" << std::endl;
    o << "===========================" ;
    o << "Order id : ";
    o << GetOrderID() << std::endl;
    o << "----------------------" << std::endl;
    o << " ----------------------" << std::endl;

    o << "Invoice to : " << std::endl;
    o << "Customer ID " << getCustomerID() ; 
    o << "Make payment to : " << std::endl;
    // Class Supermaket tính sau
    o << "STT" << std::right << std::setw(2) << "|";
    o << "Product ID" << std::right << std::setw(7) << "|";
    o << "Product name" << std::right << std::setw(10) << "|";
    o << "Unit price" << std::right << std::setw(0) << "|";
    o << "Quantity" << std::right << std::setw(0) << "|";
    o << "Total" << std::right << std::setw(0) << "|";
    o << std::endl;
    o << "------------------------------------------------------------" << std::endl;
    for (size_t i = 0; i < OrderedElectricalProduct.getSize(); i++)
    {
        o << stt << "   | ";
        OrderedElectricalProduct.at(i).Display_Order(o);
        stt++;
    }
    for (size_t i = 0; i < OrderedFood.getSize(); i++)
    {
        o << stt << "   | ";
        OrderedFood.at(i).Display_Order(o);
        stt++;
    }
    for (size_t i = 0; i < OrderedHouseware.getSize(); i++)
    {
        o << stt << "   | ";
        OrderedHouseware.at(i).Display_Order(o);
        stt++;
    }

    o << std::endl;
    o << std::endl;
    o << "----------------------------------------" << std::endl;
    o << "========================================" << std::endl;
    o << "Total Amount  : " << CalculateTotalAmount() << std::endl;
    o << "----------------------------------------" << std::endl;
    o << "========================================" <<std:: endl;
    o << "Thank you!" << std::endl;
}
int Order::CalculateTotalAmount()
{
    totalAmount = 0;

    for (size_t i = 0; i < OrderedElectricalProduct.getSize(); i++)
    {
        int productTotal = OrderedElectricalProduct.at(i).getPrice() * OrderedElectricalProduct.at(i).getSoLuongTrongGio();
        totalAmount += productTotal;
    }

    for (size_t i = 0; i < OrderedFood.getSize(); i++)
    {
        int productTotal = OrderedFood.at(i).getPrice() * OrderedFood.at(i).getSoLuongTrongGio();
        totalAmount += productTotal;
    }

    for (size_t i = 0; i < OrderedHouseware.getSize(); i++)
    {
        int productTotal = OrderedHouseware.at(i).getPrice() * OrderedHouseware.at(i).getSoLuongTrongGio();
        totalAmount += productTotal;
    }

    return totalAmount;
}
