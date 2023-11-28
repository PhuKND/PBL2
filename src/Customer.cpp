#include <iomanip>
#include <limits>
#include "include/Menu.h"
#include "include/Customer.h"
#define MAX_LENGTH 256

Customer::Customer(){

};
Customer::Customer(int CustomerID, char *fullName, char *Gender, int age, Date DayOfBirth, char *address, char *phoneNumber, char *email, int point, char *type) : Person(CustomerID, fullName, Gender, age, DayOfBirth, address, phoneNumber, email), Point(Point), CustomerType(type){};
void Customer::SetPoint(int Point)
{
    this->Point = Point;
}
int Customer::GetPoint() const
{
    return this->Point;
}
int Customer::GetCustomerID() const
{
    return this->CustomerID;
}
void Customer::SetCustomerID(int ID)
{
    this->CustomerID = ID;
}
char *Customer::getCustomerType() const
{
    return this->CustomerType;
}
void Customer::setCustomerType(char *type)
{
    this->CustomerType = type;
}
// void Customer::AddToPurchaseHistory(const Order& order){

// }
Vector_Class<Order>& Customer::getOrderHistory() {
    return orderHistory ;
} 
void Customer::Display()
{
    std::cout << "Customer Information : " << std::endl;
    std::cout << "Customer ID : " << GetCustomerID() << std::endl;
    std::cout << "Full name : " << GetFullName() << std::endl;
    std::cout << "Age : " << GetAge() << std::endl;
    std::cout << "Gender :" << GetGender() << std::endl;
    std::cout << "Day of birth: " << GetDayOfBirth() << std::endl;
    std::cout << "Address : " << GetAddress() << std::endl;
    std::cout << "Phone number : " << GetPhoneNumber() << std::endl;
    std::cout << "Email: " << GetEmail() << std::endl;
    std::cout << "Point : " << GetPoint() << std::endl;
    std::cout << "Customer Type : " << getCustomerType() << endl;
}
Customer::~Customer()
{
}
ostream &operator<<(ostream &os, const Customer &obj)
{
    os << obj.GetCustomerID() << "," << obj.GetFullName() << "," << obj.GetAge() << "," << obj.GetDayOfBirth() << "," << obj.GetAddress() << "," << obj.GetPhoneNumber() << "," << obj.GetEmail() << "," << obj.GetPoint() << "," << obj.getCustomerType() << endl;
    return os;
}
void Customer::Display_01(ostream &cout)
{
    cout << std::left << std::setw(15) << GetCustomerID() << " | ";
    cout << std::left << std::setw(20) << GetFullName() << " | ";
    cout << std::left << std::setw(4) << GetAge() << " | ";
    cout << std::left << std::setw(20) << GetDayOfBirth() << " | ";
    cout << std::left << std::setw(25) << GetAddress() << " | ";
    cout << std::left << std::setw(15) << GetPhoneNumber() << " | ";
    cout << std::left << std::setw(30) << GetEmail() << " | ";
    cout << std::left << std::setw(20) << GetPoint() << " | ";
    cout << std::left << std::setw(10) << getCustomerType() << " | ";
    cout << "\n";
}
// void Customer::DataFile(const Customer obj , const char* filename) {
//     cout << obj.GetCustomerID() << "," << obj.GetFullName() << "," << obj.GetAge() << "," << obj.GetDayOfBirth() << "," << obj.GetAddress() << "," << obj.GetPhoneNumber() << "," << obj.GetEmail() << "," << obj.getCustomerType() << "," << obj.getCustomerType()  << endl ;
// }
void Customer::WriteDataToFile(std::ostream &file) const
{
    file << GetCustomerID() << ","
         << GetFullName() << ","
         << GetGender() << ","
         << GetAge() << ","
         << GetDayOfBirth() << ","
         << GetAddress() << ","
         << GetPhoneNumber() << ","
         << GetEmail() << ","
         << GetPoint() << ","
         << getCustomerType() << std::endl;
}
void Customer::ReadDataFromFile(std::istream &file)
{
    char comma;
    file >> CustomerID >> comma;
    Menu::readAttributeTillDelimiter(fullName, file);
    Menu::readAttributeTillDelimiter(Gender, file);
    file >> age >> comma;
    file >> DayOfBirth >> comma ;
    Menu::readAttributeTillDelimiter(address, file);
    Menu::readAttributeTillDelimiter(phoneNumber, file);
    Menu::readAttributeTillDelimiter(email, file);
    file >> Point >> comma;
    Menu::readAttributeTillDelimiter(CustomerType, file);
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void Customer::BuyProduct( Order& order, Food& obj, int sl)
{
    obj.setSoLuongTonKho(obj.getSoLuongTonKho() - sl);
    obj.setSoLuongDaBan(obj.getSoLuongDaBan() + sl);
    obj.setSoLuongTrongGio(sl);
    order.Order_Food(obj) ; 
    cout << "Buy " << obj.getTenSanPham() << " Successfully"  << endl;
}
void Customer::BuyProduct( Order& order, ElectricalProduct& obj, int sl)
{
    obj.setSoLuongTonKho(obj.getSoLuongTonKho() - sl);
    obj.setSoLuongDaBan(obj.getSoLuongDaBan() + sl);
    obj.setSoLuongTrongGio(sl);
    order.Order_ElectricalProduct(obj); 
    cout << "Buy " << obj.getTenSanPham() << " Successfully"  << endl;
}

void Customer::BuyProduct( Order& order, Houseware& obj, int sl)
{
    obj.setSoLuongTonKho(obj.getSoLuongTonKho() - sl);
    obj.setSoLuongDaBan(obj.getSoLuongDaBan() + sl);
    obj.setSoLuongTrongGio(sl);
    order.Order_Houseware(obj) ; 
    cout << "Buy " << obj.getTenSanPham() << " Successfully"  << endl;
}
void Customer::add_to_orders(const Order& ord) {
    orderHistory.pushBack(ord) ; 
}
Order& Customer::Last_Order()  {
    return orderHistory.getLast(); 
}
int Customer::getOrd_Size(){
    return orderHistory.getSize() ; 
}
void Customer::Show_Orders_History(std::ostream& o) {
     o << "===========================================" << std::endl ;
     o << "                ORDERS HISTORY   " << std::endl;
     o << "===========================================" << std::endl;
     o << "Customer : " << GetFullName() << endl;
     o << "ID: " << GetCustomerID() << endl;
     o << "===========================================" << std::endl;
     o << std::setw(8) << "Order ID"
       << "|"
       << std::setw(13) << "Total Amount"
       << "|"
       << std::setw(15) << "Date"
       << "|"
       << std::setw(12) << "Is Complete"
       << "|"
       << std::endl
       << "------------------------------------------" << endl;

     for (int i = 0; i < orderHistory.getSize(); i++)
     {
         orderHistory.at(i).Display_List(o);
    }
}