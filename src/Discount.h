#ifndef DISCOUNT_H
#define DISCOUNT_H

#include "Time.h"
#include <iostream>
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
    DiscountType type;
    int discountID;
    int pointThreshold;
    char *couponCode;
    int percentage;
    bool available;
public:
    Discount(int discountid,char *couponCode, int percentage, bool available);
    Discount(int percentage);
    Discount(int discountid, int pointThreshold, int percentage, bool available);
    
    ~Discount();
    Discount();
     const char* DiscountTypeToString(DiscountType type) const ;
    int getPercentage() const;
    static int getNumberOfDiscount();
    static void setNumberOfDiscount(int value);
    DiscountType getType() const;
    void setType(DiscountType newType);
    int getDiscountID() const;
    void setDiscountID(int newDiscountID);
    int getPointThreshold() const;
    void setPointThreshold(int newPointThreshold);
    char *getCouponCode() ;
    void setCouponCode(char *newCouponCode);
    void setPercentage(int newPercentage);
  
    bool isAvailable() const;
    void setAvailable(bool newAvailable);
    friend std::istream &operator>>(std::istream &is, Discount &discount);
    friend std::ostream &operator<<(std::ostream &os, const Discount &discount);
    void WriteDataToFile(std::ostream &file) const;
    void ReadDataFromFile(std::istream &file);
    void Display_01(std::ostream&) ;
};

#endif
