#pragma once 
#include"Person.h"
class Employee : public Person {
private:
    int employeeID;
    char* position;
    int salary;
    char* startDay;
    char* endDay;
    bool isWorking;
public:
    Employee()  ; 

Employee(int ID ,char* fullName , char* Gender , int age , char* dayofbirth , char* address , char* phoneNumber , char* email
                    , char* position , int salary , char* startDay , char* endDay , bool isWorking );
~Employee(); 
    int GetEmployeeID() const;
    char* GetPosition() const;
    int GetSalary() const;
    char* GetStartDay() const;
    char* GetEndDay() const;
    bool IsWorking() const;
    void SetEmployeeID(int id);
    void SetPosition( char*& pos);
    void SetSalary(int sal);
    void SetStartDay(char*& start);
    void SetEndDay( char*& end);
    void SetIsWorking(bool working);
    void Display() ; 
    void Display_01(ostream&) ;
    void GetInformation();
    friend ostream& operator<<(ostream&,const Employee&); 
    void WriteDataToFile(std::ostream& file) const override ; 
     void ReadDataFromFile(std::istream& file) override ; 
};