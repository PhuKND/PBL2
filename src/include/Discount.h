#ifndef DISCOUNT_H
#define DISCOUNT_H

#include "C:\Users\nguye\Downloads\Ky3\PBL2\src\Time.h"
#include <iostream>
// #include"Menu.h"
#include "Vector_Class.h"
enum DiscountType
{
    DATE_BASED,
    POINT_BASED,
    COUPON_CODE_BASED
};

class Discount
{
private:
    static int numberofDiscount;
    int holderID ; 
    DiscountType type;
    int discountID;
    Time date;
    int pointThreshold;
    char *couponCode;
    int percentage;
    int quantity;
    bool available;
public:
    Discount(int discountid,int holderID, char *couponCode, int percentage, int quanity, bool available);
    Discount(int percentage);
    Discount(int discountid, int pointThreshold, int percentage, int quanity, bool available);
    
    ~Discount();
    Discount();
    int getHolderID() ;
    void setHolderID(int) ;
    int getPercentage() const;
    static int getNumberOfDiscount();
    static void setNumberOfDiscount(int value);
    DiscountType getType() const;
    void setType(DiscountType newType);
    int getDiscountID() const;
    void setDiscountID(int newDiscountID);
    Time getDate() const;
    void setDate(const Time &newDate);
    int getPointThreshold() const;
    void setPointThreshold(int newPointThreshold);
    char *getCouponCode() ;
    void setCouponCode(char *newCouponCode);
    void setPercentage(int newPercentage);
    int getQuantity() const;
    void setQuantity(int newQuantity);
    bool isAvailable() const;
    void setAvailable(bool newAvailable);
    friend std::istream &operator>>(std::istream &is, Discount &discount);
    friend std::ostream &operator<<(std::ostream &os, const Discount &discount);
    void WriteDataToFile(std::ostream &file) const;
    void ReadDataFromFile(std::istream &file);
    void Display_01(std::ostream&) ;
};

#endif
