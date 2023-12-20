#include "Discount.h"
#include "Menu.h"

Discount::Discount(int discountid,int holderID,   char *couponCode, int percentage, int quantity, bool available)
: discountID(numberofDiscount++),holderID(holderID) ,type(COUPON_CODE_BASED), pointThreshold(0), couponCode(""), percentage(percentage), quantity(quantity), available(available) {}
Discount::Discount(int percentage)
: discountID(numberofDiscount++), type(DATE_BASED), pointThreshold(0), couponCode(""), percentage(percentage), quantity(quantity), available(available) {}

Discount::Discount(int discountid, int pointThreshold, int percentage, int quantity, bool available)
: discountID(numberofDiscount++), type(POINT_BASED),  pointThreshold(pointThreshold), couponCode(""), percentage(percentage), quantity(quantity), available(available) {}

Discount::~Discount()
{
}
Discount::Discount() : Discount(0,-1, "", 0.0, 0, 1)
{
}
int Discount::getHolderID(){
    return holderID; 

}
void Discount::setHolderID(int id) {
    this -> holderID = id ;
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
os << "Discount ID : " ; 
os << discount.discountID << " " << std::endl ;

switch (discount.type)
{
case DATE_BASED:
    os <<   "Discount type : "  << " DATE_BASED " << std::endl ;
    break;
case POINT_BASED:
    os <<   "Discount type : "  << "POINT_BASED "  << std::endl ;
    break;
case COUPON_CODE_BASED:
    os << "Discount type : "  <<  "COUPON_CODE_BASED " << std::endl ;
    break;
}
os << "Percentage : " << discount.percentage << std::endl ;
os << std::endl;
return os;
}

std::istream &operator>>(std::istream &is, Discount &discount)
{
    std::cout << "Enter discount ID: ";
    is >> discount.discountID;
    
    std::cout << "Enter discount type (1 for DATE_BASED, 2 for POINT_BASED, 3 for COUPON_CODE_BASED): ";
    int typeChoice;
    is >> typeChoice;

    switch (typeChoice)
    {
    case 1:
        discount.type = DATE_BASED;
        break;
    case 2:
        discount.type = POINT_BASED;
        std::cout << "Enter discount point threshold: ";
        is >> discount.pointThreshold;
        break;
    case 3:
        discount.type = COUPON_CODE_BASED;
        std::cout << "Enter coupon code: ";
        Menu::getInput(discount.couponCode,is) ;
        break;
    default:
        std::cerr << "Invalid discount type choice. Please choose 1, 2, or 3." << std::endl;
        break;
    }

    std::cout << "Enter percentage: ";
    is >> discount.percentage;
    std::cout << "Enter quantity: ";
    is >> discount.quantity;
    std::cout << "Is available: ";
    is >> discount.available;

    return is;
}
const char* Discount::DiscountTypeToString(DiscountType type) const {
        switch (type) {
            case DATE_BASED:
                return "DATE_BASED";
            case POINT_BASED:
                return "POINT_BASED";
            case COUPON_CODE_BASED:
                return "COUPON_CODE_BASED";
            default:
                return "UNKNOWN";
        }
    }
void Discount::WriteDataToFile(std::ostream &file) const
{
file << discountID << "," << percentage <<"," << available << "," 
        << quantity << "," << holderID << "," << couponCode << std::endl ;
}
void Discount::ReadDataFromFile(std::istream &file)
{
    char comma;
    int typeCode;

    file >> discountID >> comma;
    type = static_cast<DiscountType>(2); 
    file >> percentage >> comma;
    file >> available >> comma;
    file >> quantity >> comma;
    file >> holderID >> comma;
    Menu::readAttributeTillDelimiter(couponCode, file);
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void Discount::Display_01(std::ostream& os){
    os << std::left << std::setw(15) << getDiscountID() << " | ";
    os << std::left << std::setw(20) << DiscountTypeToString(getType()) << " | ";
    os << std::left << std::setw(4) << getCouponCode() << " | ";
    os << std::left << std::setw(20) << getPercentage() << " | ";
    os << std::left << std::setw(25) << getQuantity() << " | ";
    os << std::left << std::setw(15) << isAvailable() << " | ";
    os << std::left << std::setw(30) << getHolderID()<< " | ";
    os << "\n";
}

