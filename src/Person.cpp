#include "Person.h"
#include <fstream>

Person::Person(int ID ,char* fullName, char* Gender, int age, const Date& DayOfBirth,char* address, char* phoneNumber, char* email)
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

const Date& Person::GetDayOfBirth() const {
    return DayOfBirth;
}

void Person::SetDayOfBirth(const Date& dayOfBirth) {
    // Set the day of birth directly
    DayOfBirth = dayOfBirth;
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
