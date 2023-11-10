#include <string>

class importBill
{
private:
    int importID;
    int supplierID;
    char* importDate;
    double totalAmount;

public:
    importBill(int, int , char* , double);
    ~importBill();

    char* GetImportDate() const;
    void SetImportDate(const char* &newImportDate);

    double GetTotalAmount() const;
    void SetTotalAmount(double newTotalAmount);
    void Display() ; 


};
