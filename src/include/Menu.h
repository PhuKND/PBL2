#pragma once
#include"Customer.h"
#include"Employee.h"
#include"Discount.h"
#include"DataManager.h"
#include<fstream>
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define CYAN    "\033[1;36m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define BRIGHT_MAGENTA "\033[1;95m"
#define BOLD_BLUE "\033[1;34m"
#define WIDTH 40
class Customer;
class Employee;
class Food;
class ElectricalProduct;
class Houseware;
class Order;
class Discount;
class Menu {
private:
    DataManager<Customer> customerManager ; 
    DataManager<Employee> employeeManager ;
    DataManager<Food> foodManager ; 
    DataManager<ElectricalProduct> electricalproductManager ;
    DataManager<Houseware> housewareManager ;
    DataManager<Order> orderManager ; 
    DataManager<Discount> discountManager ; 
    const char* key = "admin" ; 
    int customerChoiceCount;
    int managerChoiceCount;
    int employeeChoiceCount;
public:
    Menu();
    ~Menu() ; 
    void displayEmployeeMenu(Employee& employee) ; 
    void displayCustomerMenu(Customer&,Order&) ; 
    void displayManagerMenu()  ;
    void run();
    static bool areEqual(const char *, const char *) ;
    static void getInput(char*& , std::istream&,int = 100) ;
    static void readAttributeTillDelimiter(char* &attribute, std::istream& file);
};

