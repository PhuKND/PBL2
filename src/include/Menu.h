#include"Customer.h"
#include"Employee.h"
#include"DataManager.h"
class Menu {
private:
    DataManager<Customer> customerManager ; 
    DataManager<Employee> employeeManager ;
    const char* key = "admin" ; 
    int customerChoiceCount;
    int managerChoiceCount;
    int employeeChoiceCount;

public:
    Menu();
    ~Menu() ; 
    // void addCustomerMenuItem(const char* description);
    // void addManagerMenuItem(const char* description);
    // void addEmployeeMenuItem(const char* description);

    void displayEmployeeMenu(int) ; 
    void displayCustomerMenu(int) ; 
    void displayManagerMenu()  ;
    
    void run();
    // void customerFunction1() ; 
    // void customerFunction2() ;
    
    // void customerFunction2() ;
    // void managerFunctio\n1() ;
    static bool areEqual(const char *, const char *) ;
    static void getInput(char*& , istream&,int = 100) ;
    static void readAttributeTillDelimiter(char* &attribute, std::istream& file);
};

