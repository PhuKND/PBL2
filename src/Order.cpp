#include "include/Order.h"
#include "C:\Users\nguye\Downloads\Ky3\PBL2\src\Time.h"
Order::Order(int OrderID, int CustomerID, int totalAmount, Time orderTime, char *orderStatus, bool HoanThanh, char *PaymentMethod, char *ShippingAddress, bool delivery)
{
    this->OrderID = OrderID;
    this->CustomerID = CustomerID;
    this->orderTime = Time();
    this->totalAmount = totalAmount;
    this->orderTime = orderTime;
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
int Order::getNumberOrder()
{
    return numberofOrder;
}
void Order::setNumberOrder()
{
    numberofOrder++;
}
int Order::GetOrderID() const
{
    return OrderID;
}
int Order::getCustomerID()
{
    return CustomerID;
}
void Order::setCustomerID(int id)
{
    this->CustomerID = id;
}
void Order::SetOrderID(int OrderID)
{
    this->OrderID = OrderID;
    setNumberOrder();
}

int Order::GetTotalAmount() const
{
    return totalAmount;
}

void Order::SetTotalAmount(int totalAmount)
{
    this->totalAmount = totalAmount;
}

Time Order::GetOrderTime() const
{
    return orderTime;
}

void Order::SetOrderTime(Time &orderTime)
{
    this->orderTime = orderTime;
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
void Order::Display(std::ostream &o, char *name)
{
    int total;
    int stt = 1;
    o << "============================================================================" << std::endl;
    o << "                                INVOICE" << std::endl;
    o << "============================================================================" << std::endl;
    o << "Order id : ";
    o << GetOrderID() << std::endl;
    o << "Order time : ";
    orderTime.updateRealTime();
    o << orderTime.getRealTime() << std::endl;
    o << "------------------------------------------------------------------------------" << std::endl;
    o << "Customer ID :" << getCustomerID() << std::endl;
    o << "Customer name : " << name << std::endl;
    o << "------------------------------------------------------------------------------" << std::endl;
    o << "STT" << std::right << std::setw(2) << "|";
    o << "Product ID" << std::right << std::setw(4) << "|";
    o << "Product name" << std::right << std::setw(16) << "|";
    o << "Unit price" << std::right << std::setw(2) << "|";
    o << "Quantity" << std::right << std::setw(1) << "|";
    o << "Total" << std::right << std::setw(5) << "|";
    o << std::endl;
    o << "------------------------------------------------------------------------------" << std::endl;
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
    o << "------------------------------------------------------------------------------" << std::endl;
    o << "                              Total before apply discount : "
      << "$" << CalculateTotalAmount() << std::endl;
    o << "                              Total after apply discount : ";

    o << "$" << getTotalAfterDiscount()<< std::endl;
    o << "------------------------------------------------------------------------------" << std::endl;
    o << "                              Thank you!" << std::endl;
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
void Order::Display_List(std::ostream &o)
{
    o << std::setw(8) << GetOrderID() << "|"
      << std::setw(13) << "$" << GetTotalAmount() << "|"
      << std::setw(15) << GetOrderTime() << "|"
      << std::setw(12) << HoanThanh << "|"
      << std::endl;
}
void Order::ReadDataFromFile(std::istream &file)
{
    char comma;
    file >> OrderID >> comma;
    file >> CustomerID >> comma;
    file >> totalAmount >> comma;
    file >> HoanThanh;
    SetOrderID(OrderID);
}
void Order::WriteDataToFile(std::ostream &file)
{
    file << GetOrderID() << ","
         << getCustomerID() << ","
         << GetTotalAmount() << ","
         << HoanThanh << std::endl;
}
void Order::Display_file(const char *filename, char *name)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        int total;
        int stt = 1;
        file << "=============================================================" << std::endl;
        file << "                       INVOICE" << std::endl;
        file << "=============================================================" << std::endl;
        file << "Order ID : ";
        file << GetOrderID() << std::endl;
        file << "Order time : ";
        file << orderTime.getRealTime() << std::endl;
        file << "-------------------------------------------------------------" << std::endl;
        file << "Customer ID : " << getCustomerID() << std::endl;
        file << "Customer name : " << name << std::endl;
        file << "-------------------------------------------------------------" << std::endl;
        file << "STT" << std::right << std::setw(2) << "|";
        file << "Product ID" << std::right << std::setw(4) << "|";
        file << "Product name" << std::right << std::setw(16) << "|";
        file << "Unit price" << std::right << std::setw(2) << "|";
        file << "Quantity" << std::right << std::setw(1) << "|";
        file << "Total" << std::right << std::setw(5) << "|";
        file << std::endl;
        file << "------------------------------------------------------------" << std::endl;
        for (size_t i = 0; i < OrderedElectricalProduct.getSize(); i++)
        {
            file << stt << "   | ";
            OrderedElectricalProduct.at(i).Display_Order(file);
            stt++;
        }
        for (size_t i = 0; i < OrderedFood.getSize(); i++)
        {
            file << stt << "   | ";
            OrderedFood.at(i).Display_Order(file);
            stt++;
        }
        for (size_t i = 0; i < OrderedHouseware.getSize(); i++)
        {
            file << stt << "   | ";
            OrderedHouseware.at(i).Display_Order(file);
            stt++;
        }

        file << std::endl;
        file << std::endl;
        file << "----------------------------------------" << std::endl;
        file << "  Total : "
             << "$" << CalculateTotalAmount() << std::endl;
              file << "                              Total after apply discount : ";

    file << "$" << getTotalAfterDiscount()<< std::endl;
        file << "----------------------------------------" << std::endl;
        file << "          Thank you!" << std::endl;
    }
    else
    {
        std::cerr << "Can't open file " << std::endl;
    }
}

void Order::ApplyDiscount(Discount &discount)
{
    if (discount.isAvailable())
    {
        int newtotalAmount;
        newtotalAmount = totalAmount - discount.getPercentage() * totalAmount / 100;
        setTotalAfterDiscount(newtotalAmount) ; 
        
        discount.setQuantity(discount.getQuantity() - 1);
        std::cout << "Apply Discount Successfully" << std::endl;
    }
    else
    {
        std::cout << "Invalid Discount" << std::endl;
    }
}
void Order::setTotalAfterDiscount(double newtotal){
    this -> totalAfterDiscount = newtotal ;
}
double Order::getTotalAfterDiscount(){
    return totalAfterDiscount; 
}