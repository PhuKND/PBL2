#include"Product.h"
#include"Employee.h"
#include"Vector.h"

class Area
{
private:
    int AreaID ; 
    int ManagerID ;
    char* AreaName ; 
    bool isOpen ; 

public:
   
    Area(int areaID, int managerID,  const char* areaName, bool openStatus);
    
    void AddProduct(const Product& product);

    void RemoveProduct(const int ProductID );

    void UpdateAreaInfo(const char*newName, bool newOpenStatus);

    void DisplayAreaInfo() const;

    bool SearchArea(const char*searchTerm) const;

    int CountProducts() const;

    void GenerateReport() const;

    void ApplyDiscountOrPromotion();

    void CreateInvoice() const;
};




