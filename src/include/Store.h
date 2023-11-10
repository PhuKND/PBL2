#include "Product.h"
#include "Employee.h"
#include "Order.h"
#include "Entity.h"

class Store : public Entity
{
private:
    Vector<Product> productList;  
    Vector<Product> inventories; 
    Vector<Order> orders;      
    Vector<Employee> employees;   
public:
    Store(/* args */);
    ~Store();

    Vector<Product> GetProductList() const;
    void SetProductList(const Vector<Product> &newProductList);

    Vector<Product> GetInventories() const;
    void SetInventories(const Vector<Product> &newInventories);

    Vector<Order> GetOrders() const;
    void SetOrders(const Vector<Order> &newOrders);

    Vector<Employee> GetEmployees() const;
    void SetEmployees(const Vector<Employee> &newEmployees);
};
