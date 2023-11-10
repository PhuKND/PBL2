#include "include/Employee.h"
#include "DataManager.cpp"
#include"Vector.cpp"
#include"Vector_Class.cpp"
#include"Menu.cpp"

int main()
{
    // // Nhân viên
    // Employee employee1( 1, "Nguyen Ba Xuan An", "Male", 19, "19/09/2004", "Dak Lak",
    //                    "0818573466", "nguyenbaxuanan@employee.com", "Director", 50000, "01/01/2017", "NULL", true);
    // Employee employee2(2, "Tran B", "Female", 28, "02/02/1992", "HCMC", "9876543210", "tranB@gmail.com",
    //                    "Engineer", 40000, "02/02/2022", "02/02/2023", true);
    // // Khách hàng

    // Customer customer2(001,"Nguyen C" , "Male" , 50 , "14/10/1975" , "Khanh Hoa" ,
    //                     "0374174122" , "tranC1411@customer.com" , 1000 , "VIP") ; 
    // Customer customer1(001,"Tran P" , "Female" , 16 , "14/11/2007" , "Dak Lak" ,
    //                     "037417222" , "tranp1411@customer.com" , 0 , "Standard") ; 
    // DataManager<Employee> employeeManager;
    // DataManager<Customer> customerManager; 

    
    // employeeManager.AddToLists(employee1);
    // employeeManager.AddToLists(employee2);

    // customerManager.AddToLists(customer1) ; 
    // customerManager.AddToLists(customer2) ; 


    // employeeManager.SaveDataToFile(employeeManager.lists, "data/employee_lists.txt");
    // customerManager.SaveDataToFile(customerManager.lists , "data/customer_lists.txt") ; 

    // employee1.Display() ; 
    // Menu menu ; 
    // while(true){
    //     menu.run() ; 
    // }
    Menu menu ;
    while (true)
    {
        menu.run(); 
    }
        return 0;
}
