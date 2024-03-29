#include "include/Employee.h"
#include"include/Menu.h"
#define MAX_LENGTH 256
#include <iostream>
#include <fstream>
#include <iomanip>
#include<limits>

Employee::Employee() : Person(), employeeID(0), position(const_cast<char*>("")), salary(0), isWorking(true) {
}

  

Employee::Employee(int ID, char* fullName, char* Gender, int age,  Date& dayofbirth, char* address, char* phoneNumber, char* email, char* position, int salary, Date& startDay,  Date& endDay, bool isWorking)
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

const Date& Employee::GetStartDay() const
{
    return startDay;
}

void Employee::SetStartDay(const Date&start)
{
    startDay = start;
}

const Date& Employee::GetEndDay() const
{
    return endDay;
}

void Employee::SetEndDay(const Date& end)
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
void Employee::Display_01(ostream& out){
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
    std::cin >> DayOfBirth ; 
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
    std::cin >> startDay ; 
    std::cout << "End day : ";
    std::cin >> endDay ; 
    std::cout << "Is working (1 for Yes, 0 for No): ";
    std::cin >> isWorking;
}

void Employee::WriteDataToFile(std::ostream &file) const
{
    file << GetEmployeeID() <<"," 
    << GetFullName()<<"," <<GetGender()<< "," <<GetAge()<<
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
        file >> DayOfBirth >> comma;
        Menu::readAttributeTillDelimiter(address, file);
        Menu::readAttributeTillDelimiter(phoneNumber, file);
        Menu::readAttributeTillDelimiter(email, file);
        Menu::readAttributeTillDelimiter(position, file);
        file >> salary >> comma;
        file >> startDay >> comma;
        file >> endDay >> comma;
        file >> isWorking  ; 
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }