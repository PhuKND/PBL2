#include "Product.h"
#include <string>

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

        TechnicalSpecification(int resX, int resY, int cap, double size, int watt, const char*& os)
            : resolutionX(resX), resolutionY(resY), capacity(cap), screenSize(size), wattage(watt), operatingSystem(os) {}
    };

private:
    TechnicalSpecification techSpec;

public:
    ElectricalProduct();
    ElectricalProduct(const char*& name, int id, double price, int stock, const char*& manufacturer, const char*& description,
                      const TechnicalSpecification& tech);
    ~ElectricalProduct();

    TechnicalSpecification GetTechnicalSpecification() const;
    void SetTechnicalSpecification(const TechnicalSpecification& tech);
    void Display();
};
