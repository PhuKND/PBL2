#include "include/Employee.h"
#include"include/Menu.h"
#define MAX_LENGTH 256
#include <iostream>
#include <fstream>
#include <iomanip>
Employee::Employee() : Person(), employeeID(0), position(const_cast<char*>("")), salary(0), startDay(const_cast<char*>("")), endDay(const_cast<char*>("")), isWorking(true)
{

}

Employee::Employee(int ID, char* fullName, char* Gender, int age, char* dayofbirth, char* address, char* phoneNumber, char* email, char* position, int salary, char* startDay, char* endDay, bool isWorking)
    : Person(ID, fullName, Gender, age, dayofbirth, address, phoneNumber, email), position(position), salary(salary), startDay(startDay), endDay(endDay), isWorking(isWorking)
{
}

Employee::~Employee()
{
}

int Employee::GetEmployeeID() const
{
    return employeeID;
}

void Employee::SetEmployeeID(int id)
{
    employeeID = id;
}

char* Employee::GetPosition() const
{
    return position;
}

void Employee::SetPosition(char* &pos)
{
    position = pos;
}

int Employee::GetSalary() const
{
    return salary;
}

void Employee::SetSalary(int sal)
{
    salary = sal;
}

char* Employee::GetStartDay() const
{
    return startDay;
}

void Employee::SetStartDay(char* &start)
{
    startDay = start;
}

char* Employee::GetEndDay() const
{
    return endDay;
}

void Employee::SetEndDay(char* &end)
{
    endDay = end;
}

bool Employee::IsWorking() const
{
    return isWorking;
}

void Employee::SetIsWorking(bool working)
{
    isWorking = working;
}
// Show chi tiết
void Employee::Display()
{
    std::cout << "Employee Information : " << std::endl;
    std::cout << "Employee ID : " << GetEmployeeID() << std::endl;
    std::cout << "Full name : " << GetFullName() << std::endl;
    std::cout << "Age : " << GetAge() << std::endl;
    std::cout << "Day of birth: " << GetDayOfBirth() << std::endl;
    std::cout << "Address : " << GetAddress() << std::endl;
    std::cout << "Phone number : " << GetPhoneNumber() << std::endl;
    std::cout << "Email: " << GetEmail() << std::endl;
    std::cout << "Position : " << GetPosition() << std::endl;
    std::cout << "Salary : " << GetSalary() << std::endl;
    std::cout << "Start day : " << GetStartDay() << std::endl;
    std::cout << "End day : " << GetEndDay() << std::endl;
    std::cout << "Is working : " << (IsWorking() ? "Yes" : "No") << std::endl;
}
// Hàm show theo lists
void Employee::Display_01(ostream& cout){
       cout << std::left << std::setw(15) << GetEmployeeID() << " | ";
    cout << std::left << std::setw(20) << GetFullName() << " | ";
    cout << std::left << std::setw(4) << GetAge() << " | ";
    cout << std::left << std::setw(20) << GetDayOfBirth() << " | ";
    cout << std::left << std::setw(25) << GetAddress() << " | ";
    cout << std::left << std::setw(15) << GetPhoneNumber() << " | ";
    cout << std::left << std::setw(30) << GetEmail() << " | ";
    cout << std::left << std::setw(20) << GetPhoneNumber() << " | ";
    cout << std::left << std::setw(10) << GetSalary() << " | ";
    cout << std::left << std::setw(15) << GetStartDay() << " | ";
    cout << std::left << std::setw(15) << GetEndDay() << " | ";
    cout << std::left << std::setw(10) << (IsWorking() ? "Yes" : "No") << "\n";
}
// Hàm để xuất file để vừa đọc và ghi ngăn nhau bởi dấu ,
ostream &operator<<(ostream &o, const Employee &obj)
{
    // Hàm overload này lúc nào cần dùng sẽ định nghĩa lại
    o << obj.GetEmployeeID() << "," << obj.GetFullName() << "," << obj.GetAge() << "," << obj.GetDayOfBirth() << "," << obj.GetAddress() << "," << obj.GetPhoneNumber() << "," << obj.GetEmail() << "," << obj.GetPosition() << "," << obj.GetSalary()  << "," << obj.GetEndDay() << "," << obj.GetEndDay() << "," <<obj.IsWorking() << endl ; 
    return o;
}
// Nhập dữ liệu bằng tay
void Employee::GetInformation() {
    std::cout << "Employee Information : " << std::endl;
    std::cout << "Employee ID : ";
    std::cin >> employeeID;
    std::cout << "Full name : ";
    Menu::getInput(fullName,cin) ;
    std::cout << "Age : ";
    std::cin >> age;
    std::cout << "Day of birth: ";
    std::cin.ignore();
    Menu::getInput(DayOfBirth,cin) ;
    std::cout << "Address : ";
    std::cin.ignore();
    Menu::getInput(address,cin);
    std::cout << "Phone number : ";
    Menu::getInput(phoneNumber,cin); 
    std::cout << "Email: ";
    Menu::getInput(email,cin) ; 
    std::cout << "Position : ";
    Menu::getInput(position,cin) ;
    std::cout << "Salary : ";
    std::cin >> salary; 
    std::cout << "Start day : ";
    Menu::getInput(startDay,cin) ;
    std::cout << "End day : ";
    Menu::getInput(endDay,cin) ;
    std::cout << "Is working (1 for Yes, 0 for No): ";
    std::cin >> isWorking;
}

void Employee::WriteDataToFile(std::ostream &file) const
{
    file << GetEmployeeID() <<"," 
    << GetFullName()<<","<<GetAge()<<
    ","<<GetDayOfBirth()<<","<< GetAddress() << "," <<
    GetPhoneNumber() <<"," << GetEmail() <<","<<GetPosition()<<","
    <<GetSalary()<<","<<GetStartDay()<<","<<GetEndDay()<<
    ","<<IsWorking()<<endl ;
}
void Employee::ReadDataFromFile(std::istream &file) {
    char comma;
        file >> employeeID >> comma ;
        Menu::readAttributeTillDelimiter(fullName, file);
        Menu::readAttributeTillDelimiter(Gender, file);
        file >> age >> comma;
        Menu::readAttributeTillDelimiter(DayOfBirth, file);
        Menu::readAttributeTillDelimiter(address, file);
        Menu::readAttributeTillDelimiter(phoneNumber, file);
        Menu::readAttributeTillDelimiter(email, file);
        Menu::readAttributeTillDelimiter(position, file);
        file >> salary >> comma;
        Menu::readAttributeTillDelimiter(startDay, file);
        Menu::readAttributeTillDelimiter(endDay, file);
        file >> isWorking  ; 
    }