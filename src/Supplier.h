#include "Order.h"
#include "Houseware.h"
#include "ElectricalProduct.h"
#include "Food.h"
class Supplier
{
private:
    int supplierID;
    char *name;
    char *address;
    char *phonenumber;
    char *email;
    Vector_Class<Houseware> housewareSupplied;
    Vector_Class<Food> foodSupplied;
    Vector_Class<ElectricalProduct> ElectricalProductSupplied;
public:
    Supplier();
    Supplier(int id, char *name, char *address, char *phonenumber, char *email);
    ~Supplier();
    int getSupplierID();
    void setSupplierID(int);
    char *getName();
    void setName(char *name);
    char *getAddress();
    void setAddress(char *address);
    char *getPhonenumber();
    void setPhonenumber(char *phonenumber);
    char *getEmail();
    void setEmail(char *email);
    void addProduct(const ElectricalProduct &);
    void addProduct(const Food &);
    void addProduct(const Houseware &);
    Vector_Class<ElectricalProduct> &getelectricalproductSupplied();
    Vector_Class<Food> &getfoodSupplied();
    Vector_Class<Houseware> &gethousewareSupplied();
    void WriteDataToFile(std::ostream& file) ;
    void ReadDataFromFile(std::istream& file) ;
};
