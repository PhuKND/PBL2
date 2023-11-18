#pragma once
#include"Customer.h"
#include"Employee.h"
#include"DataManager.h"
// Define text color escape codes
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
class Menu {
private:
    DataManager<Customer> customerManager ; 
    DataManager<Employee> employeeManager ;
    DataManager<Food> foodManager ; 
    DataManager<ElectricalProduct> electricalproductManager ;
    DataManager<Houseware> housewareManager ;
    DataManager<Order> orderManager ; 
    const char* key = "admin" ; 
    int customerChoiceCount;
    int managerChoiceCount;
    int employeeChoiceCount;

public:
    Menu();
    ~Menu() ; 


    void displayEmployeeMenu(int) ; 
    void displayCustomerMenu(Customer&,Order&) ; 
    void displayManagerMenu()  ;
    

    void run();

    static bool areEqual(const char *, const char *) ;
    static void getInput(char*& , istream&,int = 100) ;
    static void readAttributeTillDelimiter(char* &attribute, std::istream& file);
};

