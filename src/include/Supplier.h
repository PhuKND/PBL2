#include"Product.h"
#include"Order.h"
#include"Payment.h"
#include"Entity.h"
class Supplier : public Entity 
{
private:
    int supplierID ;
    Vector<Product> productsSupplied  ; 
    Vector<Order> Orders ; 
public:
    Supplier(/* args */);
    ~Supplier();
    int getSupplierID() ; 
    void setSupplierID(int) ; 
    void addProduct(const Product) ; 
     

};
