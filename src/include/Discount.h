#include <iostream>
#include <string>

class Discount {
private:
    int discountID;
    int discountAmount;
    char* startDate;
    char* endDate;
    char* discountType;
    bool isExpired;
    char* description;

public:
    Discount();

    Discount(int id, int amount, const char*& start, const char*& end, const char*& type, bool expired, const char*& desc);

    ~Discount();

    void DisplayDiscountInfo() const;

    bool IsExpired() const;

    int GetDiscountID() const;

    void SetDiscountID(int id);
    
    int GetDiscountAmount() const;

    void SetDiscountAmount(int amount);

    char* GetStartDate() const;

    void SetStartDate(const char*& start);

    char* GetEndDate() const;

    void SetEndDate(const char*& end);

    char* GetDiscountType() const;

    void SetDiscountType(const char*& type);

    char* GetDescription() const;

    void SetDescription(const char*& desc);
};
