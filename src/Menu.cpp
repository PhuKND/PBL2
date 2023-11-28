#include "include/Menu.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstring>
using namespace std;
// 410
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
                file.unget();
            break;
        }
        if (index < MAX_LENGTH - 1)
        {
            attribute[index++] = ch;
        }
        else
        {
            break;
        }
    }
    attribute[index] = '\0';
}

Menu::Menu()
{

    customerManager.GetData(customerManager.lists, "data/input_output/customer.txt");
    employeeManager.GetData(employeeManager.lists, "data/input_output/employee.txt");
    housewareManager.GetData(housewareManager.lists, "data/input_output/houseware.txt");
    foodManager.GetData(foodManager.lists, "data/input_output/food.txt");
    electricalproductManager.GetData(electricalproductManager.lists, "data/input_output/electricalproduct.txt");
    orderManager.GetData(orderManager.lists, "data/input_output/order.txt");
    for (size_t i = 0; i < customerManager.lists.getSize(); i++)
    {
        for (size_t j = 0; j < orderManager.lists.getSize(); j++)
        {
            if (customerManager.lists.at(i).GetCustomerID() == orderManager.lists.at(j).getCustomerID())
            {
                customerManager.lists.at(i).getOrderHistory().pushBack(orderManager.lists.at(j));
            }
        }
    }
}
Menu::~Menu()
{
    // customerManager.SaveData(customerManager.lists, "data/input_output/customer.txt");
    // employeeManager.SaveData(employeeManager.lists, "data/input_output/employee.txt");
}
void Menu::displayCustomerMenu(Customer &cus, Order &order)
{
    std::cout << BLUE << "==============================" << endl;
    std::cout << "   " << BRIGHT_MAGENTA << "Customer Menu" << BLUE << endl;
    std::cout << "==============================" << endl;
    std::cout << "1. " << YELLOW << "View Personal Information\n";
    std::cout << "2. " << YELLOW << "Account Management\n";
    std::cout << "3. " << YELLOW << "Browse Products\n";
    std::cout << "4. " << YELLOW << "Purchase Orders\n";
    std::cout << "5. " << BLUE << "Statistics\n";
    std::cout << "6. " << BLUE << "View Order History\n";
    std::cout << "7. " << RESET << "Exit\n";
    std::cout << "==============================\n";
    int choice;
    int vitri;
    std::cin >> choice;
    system("CLS");
    switch (choice)
    {
    case 1:
        cus.Display();
        break;
    case 2:
    {
        std::cout << BLUE << "==============================\n";
        std::cout << " " << BRIGHT_MAGENTA << "Account Management" << BLUE << "   \n";
        std::cout << "==============================\n";
        std::cout << "Account ID: " << cus.GetCustomerID() << "\n";
        std::cout << "Please select the information you need to change:\n";
        std::cout << "1. " << YELLOW << "Full Name\n";
        std::cout << "2. " << YELLOW << "Gender\n";
        std::cout << "3. " << YELLOW << "Age\n";
        std::cout << "4. " << YELLOW << "Day of Birth\n";
        std::cout << "5. " << YELLOW << "Address\n";
        std::cout << "6. " << YELLOW << "Phone Number\n";
        std::cout << "7. " << YELLOW << "Email\n";
        std::cout << "8. " << BLUE << "Go back\n";
        std::cout << "==============================\n"
                  << RESET;
        int selection;
        std::cin >> selection;
        system("CLS");
        switch (selection)
        {
        case 1:
        {
            std::cout << "Enter your new full name : ";
            char *fullName;
            getInput(fullName, std::cin);
            cus.SetFullName(fullName);
            break;
        }
        case 2:
        {
            std::cout << "Enter your new gender :";
            char *gender;
            getInput(gender, std::cin);
            cus.SetGender(gender);
            break;
        }
        case 3:
        {
            int age;
            std::cout << "Enter your new age : ";
            std::cin >> age;
            cus.SetAge(age);
            break;
        }
        // ... (other cases)
        case 5:
        {
            std::cout << "Enter your new address";
            char *address;
            getInput(address, std::cin);
            cus.SetAddress(address);
            break;
        }
        case 6:
        {
            std::cout << "Enter your new phone number : ";
            char *phonenumber;
            getInput(phonenumber, std::cin);
            cus.SetPhoneNumber(phonenumber);
            break;
        }
        case 7:
        {
            std::cout << "Enter your new email : ";
            char *email;
            getInput(email, std::cin);
            cus.SetEmail(email);
            break;
        }
        case 8:
        {
            return;
            break;
        }

        default:
        {
            std::cout << "Invalid selection!";
            break;
        }
        }

        break;
    }
    case 3:
    {
        std::cout << BLUE << "==============================\n";
        std::cout << "   " << BRIGHT_MAGENTA << "Browse Products" << BLUE << "    \n";
        std::cout << "==============================\n";
        std::cout << "1. " << YELLOW << "View all products\n";
        std::cout << "2. " << YELLOW << "Search for a product\n";
        std::cout << "3. " << YELLOW << "Add a product to the cart\n";
        std::cout << "4. " << BLUE << "Go back\n";
        std::cout << "==============================\n"
                  << RESET;

        int browseChoice;
        std::cin >> browseChoice;
        system("CLS");
        switch (browseChoice)
        {
        case 1:
        {
            std::cout << BLUE << "==============================\n";
            std::cout << "  " << BRIGHT_MAGENTA << "Product Categories" << BLUE << "   \n";
            std::cout << "==============================\n";
            std::cout << "1. " << YELLOW << "View Houseware Products\n";
            std::cout << "2. " << YELLOW << "View Food Products\n";
            std::cout << "3. " << YELLOW << "View Electrical Products\n";
            std::cout << "4. " << BLUE << "Go back\n";
            std::cout << "==============================\n"
                      << RESET;

            int viewChoice;
            std::cin >> viewChoice;

            switch (viewChoice)
            {
            case 1:
                housewareManager.Display(housewareManager.lists);
                break;
            case 2:
                foodManager.Display(foodManager.lists);
                break;
            case 3:
                electricalproductManager.Display(electricalproductManager.lists);
                break;
            case 4:
                displayCustomerMenu(cus, order);
                break;
            default:
                std::cout << "Invalid selection!" << endl;
                break;
                cout << "Enter 0 to return " << endl;
                int is;
                cin >> is;
                system("CLS");
                if (is == 0)
                    return displayCustomerMenu(cus, order);
            }
            break;
        }

        case 2:
        {
            std::cout << BRIGHT_MAGENTA << "Enter product name or product id " << endl;
            std::cout << RED << "1. Product name " << endl;
            std::cout << RED << "2. Product id " << endl
                      << RESET;
            int selection;
            char *name;
            int proid;
            bool productFound = false;
            cin >> selection;
            system("CLS");
            if (selection == 1)
            {
                std::cout << "Enter product name  : ";
                getInput(name, cin);
                for (int i = 0; i < foodManager.lists.getSize(); i++)
                {
                    if (name == foodManager.lists.at(i).getTenSanPham())
                    {
                        foodManager.lists.at(i).Display();
                        productFound = true;
                        break;
                    }
                }
                for (int i = 0; i < electricalproductManager.lists.getSize(); i++)
                {
                    if (name == electricalproductManager.lists.at(i).getTenSanPham())
                    {
                        electricalproductManager.lists.at(i).Display();
                        productFound = true;
                        break;
                    }
                }
                for (int i = 0; i < housewareManager.lists.getSize(); i++)
                {
                    if (name == housewareManager.lists.at(i).getTenSanPham())
                    {
                        housewareManager.lists.at(i).Display();
                        productFound = true;
                        break;
                    }
                }
            }
            else if (selection == 2)
            {
                std::cout << "Enter product id : ";
                cin >> proid;
                system("CLS");
                for (int i = 0; i < foodManager.lists.getSize(); i++)
                {
                    if (proid == foodManager.lists.at(i).getMaSanPham())
                    {
                        foodManager.lists.at(i).Display();
                        productFound = true;
                        break;
                    }
                }
                for (int i = 0; i < electricalproductManager.lists.getSize(); i++)
                {
                    if (proid == electricalproductManager.lists.at(i).getMaSanPham())
                    {
                        electricalproductManager.lists.at(i).Display();
                        productFound = true;
                        break;
                    }
                }
                for (int i = 0; i < housewareManager.lists.getSize(); i++)
                {
                    if (proid == housewareManager.lists.at(i).getMaSanPham())
                    {
                        housewareManager.lists.at(i).Display();
                        productFound = true;
                        break;
                    }
                }
            }
            cout << "Enter 0 to return " << endl;
            int is;
            cin >> is;
            system("CLS");
            if (is == 0)
                return displayCustomerMenu(cus, order);

            break;
        }
        case 3:
        {
            std::cout << BRIGHT_MAGENTA << "Enter Product name or Product ID to get to cash" << endl;
            std::cout << RED << "1. Product name " << endl;
            std::cout << RED << "2. Product id " << endl
                      << RESET;
            int selection;
            char *name;
            int proid;
            bool productFound = false;
            cin >> selection;
            system("CLS");
            if (selection == 1)
            {
                int sl;
                std::cout << "Enter product name  : ";
                getInput(name, cin);
                for (int i = 0; i < foodManager.lists.getSize(); i++)
                {
                    if (name == foodManager.lists.at(i).getTenSanPham())
                    {
                        cout << "Product name : " << name << endl ;
                        cout << "Quantity of product remaining : " << foodManager.lists.at(i).getSoLuongTonKho() << endl ; 
                        std::cout << "Enter quanity =  ";
                        cin >> sl;
                        std::cout << "Do you want to buy "<< sl << " " << name << "(Y/N)" << endl;
                        char ch = getch();
                        if (ch == 'Y' || ch == 'y')
                        {
                            // Mua ;
                            cus.BuyProduct(order, foodManager.lists.at(i), sl);
                            cout << "Enter 0 to return " << endl;
                            int is;
                            cin >> is;
                            if (is == 0)
                                return displayCustomerMenu(cus, order);
                        }
                        productFound = true;
                        break;
                    }
                }
                for (int i = 0; i < electricalproductManager.lists.getSize(); i++)
                {
                    if (name == electricalproductManager.lists.at(i).getTenSanPham())
                    {
                        cout << "Product name : " << name << endl ;
                        cout << "Quantity of product remaining : " << electricalproductManager.lists.at(i).getSoLuongTonKho() << endl ; 
                        std::cout << "Enter quanity =  ";
                        cin >> sl;
                        std::cout << "Do you want to buy " << sl << " " << name <<  "(Y/N)" << endl;
                        char ch = getch();
                        if (ch == 'Y' || ch == 'y')
                        {
                            // Mua ;
                            cus.BuyProduct(order, electricalproductManager.lists.at(i), sl);
                            cout << "Enter 0 to return " << endl;
                            int is;
                            cin >> is;
                            if (is == 0)
                                return displayCustomerMenu(cus, order);
                        }
                        productFound = true;
                        break;
                    }
                }
                for (int i = 0; i < housewareManager.lists.getSize(); i++)
                {
                    if (name == housewareManager.lists.at(i).getTenSanPham())
                    {
                        cout << "Product name : " << name << endl;
                        cout << "Quantity of product remaining : " << housewareManager.lists.at(i).getSoLuongTonKho() << endl ; 
                        std::cout << "Enter quanity =  ";
                        cin >> sl;
                        std::cout << "Do you want to buy " << sl  <<  " "  << name << "(Y/N)" << endl;
                        char ch = getch();
                        if (ch == 'Y' || ch == 'y')
                        {
                           
                            cus.BuyProduct(order, housewareManager.lists.at(i), sl);
                            cout << "Enter 0 to return " << endl;
                            int is;
                            cin >> is;
                            if (is == 0)
                                return displayCustomerMenu(cus, order);
                        }
                        productFound = true;
                        break;
                    }
                }
            }
            else if (selection == 2)
            {
                int sl;
                std::cout << "Enter product id : ";
                cin >> proid;
                for (int i = 0; i < foodManager.lists.getSize(); i++)
                {
                    if (proid == foodManager.lists.at(i).getMaSanPham())
                    {
                        cout << "Product name : " << foodManager.lists.at(i).getMaSanPham() << endl ;
                        cout << "Quantity of product remaining : " << foodManager.lists.at(i).getSoLuongTonKho() << endl ; 
                        std::cout << "Enter quanity =  ";
                        cin >> sl;
                        std::cout << "Do you want to buy " << sl << " " << foodManager.lists.at(i).getTenSanPham() << "(Y/N)" << endl;
                        char ch = getch();
                        if (ch == 'Y' || ch == 'y')
                        {
                            // Mua ;

                            cus.BuyProduct(order, foodManager.lists.at(i), sl);
                            cout << "Enter 0 to return " << endl;
                            int is;
                            cin >> is;
                            if (is == 0)
                                return displayCustomerMenu(cus, order);
                        }
                        productFound = true;
                        break;
                    }
                }
                for (int i = 0; i < electricalproductManager.lists.getSize(); i++)
                {
                    if (proid == electricalproductManager.lists.at(i).getMaSanPham())
                    {
                        cout << "Product name : " << electricalproductManager.lists.at(i).getTenSanPham() << endl ;
                        cout << "Quantity of product remaining : " << electricalproductManager.lists.at(i).getSoLuongTonKho() << endl ; 
                        std::cout << "Enter quanity =  ";
                        cin >> sl;
                        std::cout << "Do you want to buy " << sl << " " <<electricalproductManager.lists.at(i).getTenSanPham() << "(Y/N)" << endl;
                        char ch = getch();
                        if (ch == 'Y' || ch == 'y')
                        {
                            // Mua ;
                            cus.BuyProduct(order, electricalproductManager.lists.at(i), sl);
                        }
                        cout << "Enter 0 to return " << endl;
                        int is;
                        cin >> is;
                        system("CLS");
                        if (is == 0)
                            return displayCustomerMenu(cus, order);
                        productFound = true;
                        break;
                    }
                }
                for (int i = 0; i < housewareManager.lists.getSize(); i++)
                {
                    if (proid == housewareManager.lists.at(i).getMaSanPham())
                    {
                         cout << "Product name : " << housewareManager.lists.at(i).getTenSanPham() << endl ;
                        cout << "Quantity of product remaining : " << housewareManager.lists.at(i).getSoLuongTonKho() << endl ; 
                        std::cout << "Enter quanity =  ";
                        cin >> sl;
                        std::cout << "Do you want to buy " << sl << " " << housewareManager.lists.at(i).getTenSanPham() << "(Y/N)" << endl;
                        char ch = getch();
                        if (ch == 'Y' || ch == 'y')
                        {
                            // Mua ;
                            cus.BuyProduct(order, housewareManager.lists.at(i), sl);
                        }
                        cout << "Enter 0 to return " << endl;
                        int is;
                        cin >> is;
                        if (is == 0)
                            return displayCustomerMenu(cus, order);
                        productFound = true;
                        break;
                    }
                }
            }
            cout << "Enter 0 to return " << endl;
            int is;
            cin >> is;
            system("CLS");
            if (is == 0)
                return displayCustomerMenu(cus, order);
            if (productFound == false)
            {
                std::cout << "Can not found!";
            }
            break;
        }

        case 4:
            displayCustomerMenu(cus, order);
            break;
        default:
            std::cout << "Invalid selection!" << endl;
            break;
        }

        break;
    }
    case 4:
    {
        order.Display(std::cout);
        cout << "Enter 0 to confirm " << endl;
        int is;
        cin >> is;
        if (is == 0)
        {
            order.HoanThanh = true;
            cout << "Do you want to export bill (Y/N)" << endl;
            char ch = getch();
            if (ch == 'Y' || ch == 'y')
            {
                int length = snprintf(nullptr, 0, "data/Order_list/Cus%d/%d_order.txt", order.getCustomerID(), order.GetOrderID());
        char *filename = new char[length + 1];
        snprintf(filename, length + 1, "data/Order_list/Cus%d/%d_order.txt", order.getCustomerID(), order.GetOrderID());
        cout << "File path " << filename  << endl ;  
        order.Display_file(filename);
            }
            Order::setNumberOrder();
            Order newOrder(Order::getNumberOrder(), cus.GetCustomerID());
            cus.add_to_orders(newOrder);
            

            return displayCustomerMenu(cus, cus.Last_Order());
            return;
        }
        break;
    }

    case 5:
        break;
    case 6:
    {
        cus.Show_Orders_History(std::cout);
        cout << "Enter 0 to return " << endl;
        int is;
        cin >> is;
        system("CLS");
        if (is == 0)
            return displayCustomerMenu(cus, order);
        break;
    }
    default:
        cout << "Invalid value. Please try again" << endl;

        break;
    }
}
void Menu::displayEmployeeMenu(int employeeid)
{
    std::cout << BLUE << "==============================\n";
    std::cout << "    " << BRIGHT_MAGENTA << "Employee Menu" << BLUE << "       \n";
    std::cout << "==============================\n";
    std::cout << "1. " << YELLOW << "View Personal Information\n";
    std::cout << "2. " << YELLOW << "Account Management\n";
    std::cout << "3. " << YELLOW << "Manage Inventory\n";
    std::cout << "4. " << RED << "View Orders\n";
    std::cout << "5. " << BLUE << "Confirm Orders\n";
    std::cout << "6. " << BLUE << "Statistics\n";
    std::cout << "7. " << RED << "Exit\n";
    std::cout << "==============================\n"
              << RESET;
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
        std::cout << "Invalid value. Please try again" << endl;
        break;
    }
}
//!
void Menu::displayManagerMenu()
{
    std::cout << BLUE << "==============================\n";
    std::cout << "     " << BRIGHT_MAGENTA << "Manager Menu" << BLUE << "       \n";
    std::cout << "==============================\n";
    std::cout << "1. " << YELLOW << "View lists\n";
    std::cout << "2. " << YELLOW << "Edit Information\n";
    std::cout << "3. " << YELLOW << "Add object\n";
    std::cout << "4. " << RED << "Delete object\n";
    std::cout << "5. " << BLUE << "Statistics\n";
    std::cout << "8. " << RED << "Exit\n";
    std::cout << "==============================\n"
              << RESET;

    int choice;
    std::cin >> choice;
    system("CLS");
    switch (choice)
    {
    case 1:
    {
        std::cout << BLUE << "==============================\n";
        std::cout << "    " << BRIGHT_MAGENTA << "MENU OPTIONS" << BLUE << "        \n";
        std::cout << "==============================\n";
        std::cout << "1. " << YELLOW << "View employee list\n";
        std::cout << "2. " << YELLOW << "View customer list\n";
        std::cout << "3. " << YELLOW << "View product list\n";
        std::cout << "4. " << RED << "View order list\n";
        std::cout << "5. " << BLUE << "Turn back\n";
        std::cout << "==============================\n"
                  << RESET;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            employeeManager.Display(employeeManager.lists);
            std::cout << "Do you want to export file  (Y/N)" << endl;
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
            std::cout << "Do you want to export file (Y/N)" << endl;
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
        std::cout << BRIGHT_MAGENTA << "=== Select object you want to add ===" << RESET << endl;
        std::cout << YELLOW << "1. Employee" << RESET << endl;
        std::cout << GREEN << "2. Customer" << RESET << endl;
        std::cout << BLUE << "3. Product" << RESET << endl;
        std::cout << CYAN << "4. Discount" << RESET << endl;
        std::cout << BLUE << "5. Delivery" << RESET << endl;
        std::cout << RED << "6. Turn back " << RESET << endl;
        std::cout << BRIGHT_MAGENTA << "-------------------------------------" << RESET << endl;

        int choose;
        std::cin >> choose;
        system("CLS");
        switch (choose)
        {
        case 1:
        {
            int numEmployees;
            std::cout << "Enter the number of employees to add: ";
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
        std::cout << "Invalid value. Please try again" << endl;
        break;
    }
}

//!
void Menu::run()
{
    bool exit = false;
    int userType;

    std::cout << BLUE << "=============================\n";
    std::cout << BRIGHT_MAGENTA << "   Select the user type:    \n";
    std::cout << BLUE << "=============================\n";
    std::cout << YELLOW << "1. Customer\n";
    std::cout << GREEN << "2. Manager\n";
    std::cout << RED << "3. Employee\n";
    std::cout << BLUE << "4. Turn back\n";
    std::cout << "=============================\n"
              << RESET;

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
            system("CLS");
            for (size_t i = 0; i < customerManager.lists.getSize(); i++)
            {
                if (customerid == customerManager.lists.at(i).GetCustomerID())
                {
                    validID = true;
                    Customer &cus = customerManager.lists.at(i);
                    if (cus.getOrderHistory().isEmpty())
                    {
                        Order ord(Order::getNumberOrder(), customerid);
                        cus.getOrderHistory().pushBack(ord);
                    }

                    Order &order = cus.Last_Order();
                    if (cus.Last_Order().HoanThanh)
                    {
                        Order newOrder(Order::getNumberOrder(), customerid);
                        cus.add_to_orders(newOrder);
                        displayCustomerMenu(cus, cus.Last_Order());
                        break;
                        return;
                    }
                    displayCustomerMenu(cus, order);
                    int choice;
                    std::cout << "Choose a number to continue or 0 to exit: ";
                    std::cin >> choice;
                    system("CLS");
                    if (choice == 0)
                    {
                        break; // Exit the loop if 0 is entered
                    }
                    else
                    {
                        // Use 'return' to restart the function
                        return run();
                    }
                }
            }

            if (validID)
            {
                break; // Break the loop if the ID is valid
            }
            else
            {
                std::cout << "Invalid ID! Do you want to try again? (Y/N): ";
                char tryAgain;
                std::cin >> tryAgain;
                system("CLS");
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
        std::cout << "Enter Manager Password: ";
        getInput(password, std::cin);

        if (areEqual(password, key))
        {
            system("CLS");
            displayManagerMenu();
            int choice;
            std::cout << "Choose a number to continue or 0 to exit: ";
            std::cin >> choice;

            if (choice == 0)
            {
                break;
            }
            else
            {
                // Use 'return' to restart the function
                return run();
            }
        }
        else
        {
            std::cout << "Invalid password!" << std::endl;
        }
        break;
    }
    case 3:
    {
        while (true)
        {
            int employeeid;
            std::cout << "Enter your Employee ID: ";
            std::cin >> employeeid;

            for (size_t i = 0; i < employeeManager.lists.getSize(); i++)
            {
                if (employeeid == employeeManager.lists.at(i).GetEmployeeID())
                {
                    system("CLS");
                    displayEmployeeMenu(employeeid);
                    int choice;
                    std::cout << "Choose a number to continue or 0 to exit: ";
                    std::cin >> choice;
                    system("CLS");
                    if (choice == 0)
                    {
                        break;
                    }
                    else
                    {
                        // Use 'return' to restart the function
                        return run();
                    }
                }
            }

            std::cout << "Invalid Employee ID! Do you want to try again? (Y/N): ";
            char tryAgain;
            std::cin >> tryAgain;
            system("CLS");
            if (tryAgain != 'Y' && tryAgain != 'y')
            {
                return;
            }
        }
        break;
    }
    case 4:
        exit = true;
        break;
    default:
        std::cout << "Invalid user type!" << std::endl;
        break;
    }
}