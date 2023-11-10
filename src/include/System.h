#include "Product.h" 
#include"Customer.h"
#include"Employee.h"
#include"Vector.h"
class System {
private:
    Vector<Product> products; 
    Vector<Customer> customers;
    Vector<Order> orders;
    Vector<Employee> employees; 

public:
    void addProduct(const Product& product) {
        products.pushBack(product);
    }

    void addCustomer(const Customer& customer) {
        customers.pushBack(customer);
    }

    void createOrder(const Order& order) {
        orders.push_back(order);
    }

    void addEmployee(const Employee& employee) {
        employees.push_back(employee);
    }


    void displayProducts() {
        std::cout << "Danh sách sản phẩm:\n";
        for (const Product& product : products) {
            std::cout << product.getName() << " - " << product.getPrice() << " VND\n";
        }
    }

    void displayCustomers() {
        std::cout << "Danh sách khách hàng:\n";
        for (const Customer& customer : customers) {
            std::cout << customer.getName() << " - " << customer.getEmail() << "\n";
        }
    }

};
