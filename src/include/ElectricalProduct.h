#ifndef ELECTRICALPRODUCT_H
#define ELECTRICALPRODUCT_H
#include "Product.h"
class ElectricalProduct : public Product {
public:
    class TechnicalSpecification {
    public:
        int resolutionX;
        int resolutionY;
        int capacity;
        double screenSize;
        int wattage;
        char* operatingSystem;

        TechnicalSpecification()
            : resolutionX(0), resolutionY(0), capacity(0), screenSize(0.0), wattage(0), operatingSystem("") {}

        TechnicalSpecification(int resX, int resY, int cap, double size, int watt,  char* os)
            : resolutionX(resX), resolutionY(resY), capacity(cap), screenSize(size), wattage(watt), operatingSystem(os) {}
    };

private:
    TechnicalSpecification techSpec;

public:
    ElectricalProduct();
    ElectricalProduct(int , int , char* , int , int , int , char* , char*
                      ,const TechnicalSpecification& tech);
    ~ElectricalProduct();

    TechnicalSpecification GetTechnicalSpecification() const;
    void SetTechnicalSpecification(const TechnicalSpecification& tech);
    void Display();
    void Display_01(std::ostream&) ;
    void WriteDataToFile(std::ostream&) const ;
    void ReadDataFromFile(std::istream&) ;
};
#endif