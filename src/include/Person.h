#pragma once
#include <iostream>
using namespace std;
class Person
{
protected:
    int ID;
    char* fullName;
    char* Gender;
    int age;
    char* DayOfBirth;
    char* address;
    char* phoneNumber;
    char* email;
public:
    Person(int = 0, char* =  const_cast<char*> (""), char* =  const_cast<char*> (""), int = 0,
         char* =  const_cast<char*> (""), char* =  const_cast<char*> (""), char* =  const_cast<char*> (""), char* =  const_cast<char*> (""));
    ~Person();
    char* GetFullName() const;
    void SetFullName(char* fullName) ;
    int GetAge() const;
    void SetAge(int age) ;
    char* GetGender()const;
    void SetGender(char* Gender);
    char* GetDayOfBirth()const;
    void SetDayOfBirth(char* DayOfBirth);
    int GetID()const;
    void SetID(int ID);
    char* GetAddress()const;
    void SetAddress(char* address);
    char* GetPhoneNumber()const;
    void SetPhoneNumber(char* phoneNumber);
    char* GetEmail()const;
    void SetEmail(char* email);
    // virtual void Display() ;
    // virtual void Display() = 0 ; 
    // void ReadFromFile();
    // void SaveToFile();
    // friend istream& operator>>(istream&, Person&);
    // friend ostream& operator<<(ostream&, Person);
    virtual void WriteDataToFile(std::ostream& file) const = 0;
    virtual void ReadDataFromFile(std::istream& file) = 0;

};