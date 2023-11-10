#include "include/Menu.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;
bool Menu::areEqual(const char *str1, const char *str2)
{
    while (*str1 && *str2)
    {
        if (*str1 != *str2)
        {
            return false;
        }
        str1++;
        str2++;
    }
    return (*str1 == '\0' && *str2 == '\0');
}
// Đọc có dấu cách và  stop khi xuống dòng
void Menu::getInput(char *&str, istream &cin, int maxChar)
{
    char temp[maxChar];
    std::cin.ignore();
    char ch = ' ';
    int index = 0;
    while (ch != '\n' && index < maxChar - 1)
    {
        ch = std::cin.get();
        temp[index++] = ch;
    }
    temp[index - 1] = '\0';
    str = new char[index];
    for (int i = 0; i < index; ++i)
    {
        str[i] = temp[i];
    }
}
void Menu::readAttributeTillDelimiter(char *&attribute, std::istream &file)
{
    int MAX_LENGTH = 256;
    int index = 0;
    attribute = new char[MAX_LENGTH];
    char ch;
    bool done = false;

    while (file.get(ch))
    {
        if (ch == ',' || ch == '\n')
        {
            done = true;
            if (ch == '\n')
                file.unget(); // Di chuyển lại '\n' để xử lý kết thúc dòng
            break;
        }
        if (index < MAX_LENGTH - 1)
        {
            attribute[index++] = ch;
        }
        else
        {
            // Xử lý trường hợp vượt quá kích thước buffer hoặc đã đạt đến giới hạn tối đa
            break;
        }
    }
    attribute[index] = '\0'; // Nối kết thúc chuỗi
}

Menu::Menu()
{

    customerManager.GetData(customerManager.lists, "data/input_output/customer.txt");
    employeeManager.GetData(employeeManager.lists, "data/input_output/employee.txt");
}
Menu::~Menu()
{
    customerManager.SaveData(customerManager.lists, "data/input_output/customer.txt");
    employeeManager.SaveData(employeeManager.lists, "data/input_output/employee.txt");
}
void Menu::displayCustomerMenu(int customerid)
{
    cout << "Customer Menu " << endl;
    cout << "1. View Personal Information " << endl;
    cout << "2. Account Management" << endl;
    cout << "3. Browse Products" << endl;
    cout << "4. Purchase Orders" << endl;
    cout << "5. Confirm Orders" << endl;
    cout << "6. Statistics" << endl;
    cout << "7. View Order History" << endl;
    cout << "8. Exit" << endl;
    int choice;
    int vitri;
    std::cin >> choice;
    system("CLS");
    for (size_t i = 0; i < customerManager.lists.getSize(); i++)
    {
        if (customerManager.lists.at(i).GetCustomerID() == customerid)
        {
            vitri = i;
            break;
        }
    }
    switch (choice)
    {
    case 1:
        customerManager.lists.at(vitri).Display();
        break;
    case 2:
    {
        cout << "Account Management" << endl;
        cout << "Account ID" << customerid << endl;
        cout << "Please select the information you need to change" << endl;
        cout << "1. Full Name." << endl;
        cout << "2. Gender." << endl;
        cout << "3. Age." << endl;
        cout << "4. Day of birth." << endl;
        cout << "5. Address." << endl;
        cout << "6. Phone number." << endl;
        cout << "7. Email." << endl;
        cout << "8. Go back" << endl;
        int selection;
        std::cin >> selection;
        system("CLS");
        switch (selection)
        {
        case 1:
        {
            cout << "Enter your new full name : ";
            char *fullName;
            getInput(fullName, std::cin);
            customerManager.lists.at(vitri).SetFullName(fullName);
            break;
        }
        case 2:
        {
            cout << "Enter your new gender :";
            char *gender;
            getInput(gender, std::cin);
            customerManager.lists.at(vitri).SetGender(gender);
            break;
        }
        case 3:
        {
            int age;
            cout << "Enter your new age : ";
            std::cin >> age;
            customerManager.lists.at(vitri).SetAge(age);
            break;
        }
        case 4:
        {
            cout << "Enter your new day of birth : ";
            char *dob;
            getInput(dob, std::cin);
            customerManager.lists.at(vitri).SetDayOfBirth(dob);
            break;
        }
        case 5:
        {
            cout << "Enter your new address";
            char *address;
            getInput(address, std::cin);
            customerManager.lists.at(vitri).SetAddress(address);
        }
        case 6:
        {
            cout << "Enter your new phone number : ";
            char *phonenumber;
            getInput(phonenumber, std::cin);
            customerManager.lists.at(vitri).SetPhoneNumber(phonenumber);
            break;
        }
        case 7:
        {
            cout << "Enter your new email : ";
            char *email;
            getInput(email, std::cin);
            customerManager.lists.at(vitri).SetEmail(email);
            break;
        }
        case 8:
        {
            return;
            break;
        }

        default:
        {
            cout << "Invalid selection!";
            break;
        }
        }
        break;
    }
    case 3:
        break;
    default:
        cout << "Invalid value. Please try again" << endl;
        break;
    }
}
void Menu::displayEmployeeMenu(int employeeid)
{
    cout << "Employee Menu" << endl;
    cout << "1. View Personal Information" << endl;
    cout << "2. Account Management" << endl;
    cout << "3. Manage Inventory" << endl;
    cout << "4. View Orders" << endl;
    cout << "5. Confirm Orders" << endl;
    cout << "6. Statistics" << endl;
    cout << "7. Exit" << endl;
    int choice;
    std::cin >> choice;
    system("CLS");
    switch (choice)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    default:
        cout << "Invalid value. Please try again" << endl;
        break;
    }
}
//!
void Menu::displayManagerMenu()
{
    cout << "Manager Menu" << endl;
    cout << "1. View lists" << endl;
    cout << "2. Edit Information" << endl;
    cout << "3. Add object " << endl;
    cout << "4. Delete object" << endl;
    cout << " 5. Statistics" << endl;
    cout << " 6. Save data" << endl;
    cout << " 7. View Activity Log" << endl;
    cout << " 8. Exit" << endl;

    int choice;
    std::cin >> choice;
    system("CLS");
    switch (choice)
    {
    case 1:
    {
        cout << "1. View employee list" << endl;
        cout << "2. View customer list" << endl;
        cout << "3. View product list" << endl;
        cout << "4. View order list" << endl;
        cout << "5. Turn back" << endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            employeeManager.Display(employeeManager.lists);
            cout << "Do you want to export file  (Y/N)" << endl;
            char ch;
            std::cin >> ch;
            if (ch == 'Y' || ch == 'y')
            {
                employeeManager.ShowLists_file(employeeManager.lists, "data/employee_lists.txt");
            }

            break;
        }
        case 2:
        {
            customerManager.Display(customerManager.lists);
            cout << "Do you want to export file (Y/N)" << endl;
            char ch;
            std::cin >> ch;
            if (ch == 'Y' || ch == 'y')
            {
                customerManager.ShowLists_file(customerManager.lists, "data/customer_lists.txt");
            }

            break;
        }
        case 3:
        {
            // Show product
            break;
        }
        case 4:
        {
            // Show order
            break;
        }
        case 5:
        {
            return;
            break;
        }
        }
        break;
    }
    case 2:
        // Xử lý Edit Information
        break;
    case 3:
    {
        cout << "Select object you want to add" << endl;
        cout << "1. Employee" << endl;
        cout << "2. Customer" << endl;
        cout << "3. Product" << endl;
        cout << "4. Discount" << endl;
        cout << "5. Delivery" << endl;
        cout << "6. Turn back " << endl;
        int choose;
        std::cin >> choose;
        system("CLS");
        switch (choose)
        {
        case 1:
        {
            int numEmployees;
            cout << "Enter the number of employees to add: ";
            std::cin >> numEmployees;
            Employee *employees = new Employee[numEmployees];

            for (int i = 0; i < numEmployees; i++)
            {
                employees[i].GetInformation();

                employeeManager.AddToLists(employees[i]);
            }

            delete[] employees;
            break;
        }
        case 2:
        {

            break;
        }
        default:
            break;
        }
        break;
    }
    case 4:
        // Xử lý Delete object
        break;
    case 5:
        // Xử lý Statistics
        break;
    case 6:
        // Xử lý Save data
        break;
    case 7:
        // Thoát
        break;
    default:
        cout << "Invalid value. Please try again" << endl;
        break;
    }
}

//!
void Menu::run()
{
    int userType;
    std::cout << "Select the user type : " << std::endl;
    std::cout << "1. Customer" << std::endl;
    std::cout << "2. Manager" << std::endl;
    std::cout << "3. Employee" << std::endl;
    std::cout << "4. Turn back" << std::endl;
    std::cin >> userType;
    system("CLS");
    switch (userType)
    {
    case 1:
    {
        bool validID = false;
        while (true)
        {
            int customerid;
            cout << "Enter your CustomerID: ";
            std::cin >> customerid;
            for (size_t i = 0; i < customerManager.lists.getSize(); i++)
            {
                if (customerid == customerManager.lists.at(i).GetCustomerID())
                {
                    validID = true;
                    displayCustomerMenu(customerid);
                    int choice;
                    std::cout << "Choose a number to continue or 0 to exit: ";
                    choice = _getch();
                    if (choice == 0)
                    {
                        return; // Exit the function if 0 is entered
                    }
                }
            }
            if (validID)
            {
                break; // Break the loop if the ID is valid
            }
            else
            {
                cout << "Invalid ID! Do you want to try again? (Y/N): ";
                char tryAgain;
                std::cin >> tryAgain;
                if (tryAgain != 'Y' && tryAgain != 'y')
                {
                    return;
                }
            }
        }
        break;
    }
    case 2:
    {
        int maxChar = 100;
        char temp[maxChar];
        char *password; // assuming a maximum password length
        cout << "Enter Manager Password: ";
        getInput(password, std::cin);
        if (areEqual(password, key))
        {
            system("CLS");
            displayManagerMenu();
            int choice;
            cout << "Choose a number to continue or 0 to exit: ";
            std::cin >> choice;

            if (choice == 0)
            {
                return;
            }
            break;
        }
        else
        {
            cout << "Invalid password!" << endl;
        }
        break;
    }

    case 3:
    {
        while (true)
        {
            int employeeid;
            cout << "Enter your Employee ID: ";
            std::cin >> employeeid;
            for (size_t i = 0; i < employeeManager.lists.getSize(); i++)
            {
                if (employeeid == employeeManager.lists.at(i).GetEmployeeID())
                {
                    system("CLS");
                    displayEmployeeMenu(employeeid);
                    int choice;
                    cout << "Choose a number to continue or 0 to exit: ";
                    std::cin >> choice;

                    if (choice == 0)
                    {
                        return;
                    }
                }
            }
            cout << "Invalid Employee ID! Do you want to try again? (Y/N): ";
            char tryAgain;
            std::cin >> tryAgain;
            if (tryAgain != 'Y' && tryAgain != 'y')
            {
                return;
            }
        }
        break;
    }

    default:
        cout << "Invalid user type!" << endl;
        break;
    }
}