#include "include/Person.h"
#include <fstream>

Person::Person(int ID ,char* fullName, char* Gender, int age, char* DayOfBirth,char* address, char* phoneNumber, char* email)
    : ID(ID) ,fullName(fullName), Gender(Gender), age(age), DayOfBirth(DayOfBirth),  address(address), phoneNumber(phoneNumber), email(email) {
}

Person::~Person() {
}

char* Person::GetFullName() const{
    return fullName;
}

void Person::SetFullName(char* fullName){
    this->fullName = fullName;
}

int Person::GetAge()const {
    return age;
}

void Person::SetAge(int age) {
    this->age = age;
}

char* Person::GetGender() const{
    return Gender;
}

void Person::SetGender(char* Gender) {
    this->Gender = Gender;
}

char* Person::GetDayOfBirth()const {
    return DayOfBirth;
}

void Person::SetDayOfBirth(char* DayOfBirth) {
    this->DayOfBirth = DayOfBirth;
}

int Person::GetID()const {
    return ID;
}

void Person::SetID(int ID) {
    this->ID = ID;
}

char* Person::GetAddress()const {
    return address;
}

void Person::SetAddress(char* address) {
    this->address = address;
}

char* Person::GetPhoneNumber() const{
    return phoneNumber;
}

void Person::SetPhoneNumber(char* phoneNumber) {
    this->phoneNumber = phoneNumber;
}

char* Person::GetEmail() const{
    return email;
}

void Person::SetEmail(char* email) {
    this->email = email;
}

// void Person::Display() const {
    // std::cout << "Thông tin người" << std::endl ; 
    // std::cout << "ID : " << this -> ID << std::endl ; 
    // std::cout << "Full Name : " << this -> fullName << std::endl ; 
    // std::cout << "Age : "  << this ->  age  << std::endl ; 
    // std::cout << "Day Of Birth : " << this ->DayOfBirth << std::endl ; 
    // std::cout << "Address : "  << this ->address  << std::endl ; 
    // std::cout << "Phone Number : "  << this -> phoneNumber << std::endl ; 
    // std::cout << "Email : "  << this -> email  << std::endl ; 
// }

// void Person::ReadFromFile() {
//     std::ifstream file("person.txt");
//     if (file.is_open()) {
// Đọc dữ liệu từ file, tách các trường bằng dấu phẩy
//         std::getline(file, fullName, ',');
//         std::getline(file, Gender, ',');
//         file >> age;
//         file.ignore(); // Bỏ qua ký tự ngắn cách sau age
//         std::getline(file, DayOfBirth, ',');
//         file >> ID;
//         file.ignore(); // Bỏ qua ký tự ngắn cách sau ID
//         std::getline(file, address, ',');
//         std::getline(file, phoneNumber, ',');
//         std::getline(file, email);
//         file.close();
//     }
// }
// void Person::SaveToFile() {
//     std::ofstream file("person.txt");
//     if (file.is_open()) {
        // Lưu các thuộc tính của Person vào file
//         file << fullName << " " << Gender << " " << age << " " << DayOfBirth << " " << ID << " " << address << " " << phoneNumber << " " << email;
//         file.close();
//     }
// }
