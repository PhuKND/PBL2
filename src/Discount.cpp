#include "include/Discount.h"
#include "include/Menu.h"

Discount::Discount(int discountid,  char *couponCode, int percentage, int quantity, bool available)
    : discountID(numberofDiscount++), type(COUPON_CODE_BASED), date(), pointThreshold(0), couponCode(""), percentage(percentage), quantity(quantity), available(available) {}
Discount::Discount(int discountid, const Time &date, int percentage, int quantity, bool available)
    : discountID(numberofDiscount++), type(DATE_BASED), date(date), pointThreshold(0), couponCode(""), percentage(percentage), quantity(quantity), available(available) {}

Discount::Discount(int discountid, int pointThreshold, int percentage, int quantity, bool available)
    : discountID(numberofDiscount++), type(POINT_BASED), date(), pointThreshold(pointThreshold), couponCode(""), percentage(percentage), quantity(quantity), available(available) {}

Discount::~Discount()
{
    delete[] couponCode;
}
Discount::Discount() : Discount(0, "", 0.0, 0, 0)
{
}
int Discount::getPercentage() const
{
    return percentage;
}
int Discount::numberofDiscount = 0;
int Discount::getNumberOfDiscount()
{
    return numberofDiscount;
}

void Discount::setNumberOfDiscount(int value)
{
    numberofDiscount = value;
}

// Getter and setter for DiscountType
DiscountType Discount::getType() const
{
    return type;
}

void Discount::setType(DiscountType newType)
{
    type = newType;
}

// Getter and setter for discountID
int Discount::getDiscountID() const
{
    return discountID;
}

void Discount::setDiscountID(int newDiscountID)
{
    discountID = newDiscountID;
}

// Getter and setter for date
Time Discount::getDate() const
{
    return date;
}

void Discount::setDate(const Time &newDate)
{
    date = newDate;
}

// Getter and setter for pointThreshold
int Discount::getPointThreshold() const
{
    return pointThreshold;
}

void Discount::setPointThreshold(int newPointThreshold)
{
    pointThreshold = newPointThreshold;
}

char *Discount::getCouponCode() 
{
    return couponCode;
}

void Discount::setCouponCode(char *newCouponCode)
{
    couponCode = newCouponCode;
}

void Discount::setPercentage(int newPercentage)
{
    percentage = newPercentage;
}

// Getter and setter for quantity
int Discount::getQuantity() const
{
    return quantity;
}

void Discount::setQuantity(int newQuantity)
{
    quantity = newQuantity;
}

// Getter and setter for available
bool Discount::isAvailable() const
{
    return available;
}

void Discount::setAvailable(bool newAvailable)
{
    available = newAvailable;
}
std::ostream &operator<<(std::ostream &os, const Discount &discount)
{
    os << discount.discountID << " ";

    switch (discount.type)
    {
    case DATE_BASED:
        os << "DATE_BASED " << discount.date << " ";
        break;
    case POINT_BASED:
        os << "POINT_BASED " << discount.pointThreshold << " ";
        break;
    case COUPON_CODE_BASED:
        os << "COUPON_CODE_BASED " << discount.couponCode << " ";
        break;
    }

    os << discount.percentage << " " << discount.quantity << " " << discount.available;
    os << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Discount &discount)
{
    is >> discount.discountID;

    char *typeStr;
    is >> typeStr;

    if (typeStr == "DATE_BASED")
    {
        discount.type = DATE_BASED;
        is >> discount.date;
    }
    else if (typeStr == "POINT_BASED")
    {
        discount.type = POINT_BASED;
        is >> discount.pointThreshold;
    }
    else if (typeStr == "COUPON_CODE_BASED")
    {
        discount.type = COUPON_CODE_BASED;
        is >> discount.couponCode;
    }

    is >> discount.percentage >> discount.quantity >> discount.available;

    return is;
}
void Discount::WriteDataToFile(std::ostream &file) const
{
    file << discountID << "," << couponCode << "," << percentage
         << "," << quantity << "," << available << std::endl;
}
void Discount::ReadDataFromFile(std::istream &file)
{
    char comma;
    file >> discountID >> comma;
    file >> percentage >> comma;
    file >> available >> comma ;
    file >> quantity >> comma;
    Menu::readAttributeTillDelimiter(couponCode,file)   ;
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}