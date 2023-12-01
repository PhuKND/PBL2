#include "Entity.h"
#include "Product.h"
#include"Vector.h"
class Delivery : public Entity {
private:
    int deliveryID;
    char* deliveryMethod;
    char* startDate;
    Vector<Product> deliveriedProduct ; 

public:
    Delivery(int = 0 ,  char* = "" , char* = "" );
    ~Delivery();

    int GetDeliveryID() const;
    void SetDeliveryID(int id);

    char* GetDeliveryMethod() const;
    void SetDeliveryMethod(const char*& method);

    char* GetStartDate() const;
    void SetStartDate(const char*& date);

    void AddDeliveredProduct(const Product& product);

    Vector<Product> GetDeliveredProducts() const;

    void PerformDelivery();

    bool IsDeliveryComplete() const;
    
    void WriteDataToFile(std::ostream& file) const ; 
    void ReadDataFromFile(std::istream& file)  ; 
};
