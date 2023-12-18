#include "Order.h"
#include "Time.h"

Order::Order(int OrderID, int CustomerID, int totalAmount, Time orderTime, char *orderStatus, bool HoanThanh)
{
    this->OrderID = OrderID;
    this->CustomerID = CustomerID;
    this->orderTime = Time();
    this->totalAmount = totalAmount;
    this->orderTime = orderTime;
    this->orderStatus = orderStatus;
    this->HoanThanh = HoanThanh;
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
int Order::getQuanityProduct(){
    return quanityProduct; 
}
void Order::setQuanityProduct(int quanity){
    this -> quanityProduct = quanity ; 
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


int Order::GetImportPrice() const{
    return importPrice ;
}
void Order::SetImportPrice(int price){
    this -> importPrice = price ;
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
      
    if (CalculateTotalAmount() != getTotalAfterDiscount()) {
        o << "          Total : " << "$" << CalculateTotalAmount() << std::endl;
        o << "Total after appliable discount : " << "$" << getTotalAfterDiscount()<< std::endl;
        }
    else {
             o << "          Total : " << "$" << CalculateTotalAmount() << std::endl;
        }
    o << "------------------------------------------------------------------------------" << std::endl;
    o << "                              Thank you!" << std::endl;
}
int Order::CalculateTotalAmount()
{
    int totalAmount = 0 ; 
    for (size_t i = 0; i < OrderedElectricalProduct.getSize(); i++)
    {
        int productTotal = OrderedElectricalProduct.at(i).getPrice() * OrderedElectricalProduct.at(i).getSoLuongTrongGio();
        totalAmount += productTotal;
        quanityProduct += OrderedElectricalProduct.at(i).getSoLuongTrongGio() ;
    }

    for (size_t i = 0; i < OrderedFood.getSize(); i++)
    {
        int productTotal = OrderedFood.at(i).getPrice() * OrderedFood.at(i).getSoLuongTrongGio();
        totalAmount += productTotal;
        quanityProduct += OrderedFood.at(i).getSoLuongTrongGio();
    }

    for (size_t i = 0; i < OrderedHouseware.getSize(); i++)
    {
        int productTotal = OrderedHouseware.at(i).getPrice() * OrderedHouseware.at(i).getSoLuongTrongGio();
        totalAmount += productTotal;
        quanityProduct += OrderedHouseware.at(i).getSoLuongTrongGio() ;
    }

    return totalAmount;
}
int Order::CalculateTotalAmountOut()
{
    int importPrice = 0 ;
    for (size_t i = 0; i < OrderedElectricalProduct.getSize(); i++)
    {
        int productTotal = OrderedElectricalProduct.at(i).GetImportPrice() * OrderedElectricalProduct.at(i).getSoLuongTrongGio();
        importPrice += productTotal;
        quanityProduct += OrderedElectricalProduct.at(i).getSoLuongTrongGio() ;
    }

    for (size_t i = 0; i < OrderedFood.getSize(); i++)
    {
        int productTotal = OrderedFood.at(i).GetImportPrice() * OrderedFood.at(i).getSoLuongTrongGio();
        importPrice += productTotal;
        quanityProduct += OrderedFood.at(i).getSoLuongTrongGio();
    }

    for (size_t i = 0; i < OrderedHouseware.getSize(); i++)
    {
        int productTotal = OrderedHouseware.at(i).GetImportPrice() * OrderedHouseware.at(i).getSoLuongTrongGio();
        importPrice += productTotal;
        quanityProduct += OrderedHouseware.at(i).getSoLuongTrongGio() ;
    }

    return importPrice;
}
void Order::Display_List(std::ostream &o)
{
    o << std::setw(8) << GetOrderID() << "|"
      << std::setw(13) << "$" << GetTotalAmount() << "|"
      << std::setw(15) << GetOrderTime() << "|"
      << std::setw(12) << getQuanityProduct() << "|" 
      << std::setw(12) << HoanThanh << "|"
      << std::endl;
}
void Order::ReadDataFromFile(std::istream &file)
{
    char comma;
    file >> OrderID >> comma;
    file >> CustomerID >> comma;
    file >> totalAmount >> comma;
    file >> totalAfterDiscount >> comma; 
    file >> importPrice >> comma ;
    file >> quanityProduct >> comma ;
    file >> orderTime >> comma ; 
    file >> HoanThanh;
    SetOrderID(OrderID);
}
void Order::WriteDataToFile(std::ostream &file)
{
    // CalculateTotalAmountOut() ; 
    file << GetOrderID() << ","
         << getCustomerID() << ","
         << GetTotalAmount() << ","
        << getTotalAfterDiscount() << ","
        << GetImportPrice() << ","  
         << getQuanityProduct() << "," 
         << GetOrderTime() << "," 
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
        file << "Order ID: ";
        file << GetOrderID() << std::endl;
        file << "Order time: ";
        file << orderTime.getRealTime() << std::endl;
        file << "-------------------------------------------------------------" << std::endl;
        file << "Customer ID: " << getCustomerID() << std::endl;
        file << "Customer name: " << name << std::endl;
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
        
        if (CalculateTotalAmount() != getTotalAfterDiscount()) {
            file << "  Subtotal before discounts: "
             << "$" << CalculateTotalAmount() << std::endl;
        file << "          Total with applicable discounts: ";
        file << "$" << getTotalAfterDiscount()<< std::endl;
        }
        else {
            file << "  Total: "
             << "$" << CalculateTotalAmount() << std::endl;
        }
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
void Order::setTotalAfterDiscount(int newtotal){
    this -> totalAfterDiscount = newtotal ;
}
int Order::getTotalAfterDiscount(){
    return totalAfterDiscount; 
}
