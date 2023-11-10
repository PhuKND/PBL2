#include "include/ElectricalProduct.h"
#include <iostream>

ElectricalProduct::ElectricalProduct()
    : Product(), techSpec() {}

ElectricalProduct::ElectricalProduct(const std::string& name, int id, double price, int stock, const std::string& manufacturer, const std::string& description, const TechnicalSpecification& tech)
    : Product(name, id, price, stock, manufacturer, description), techSpec(tech) {}

// Destructor
ElectricalProduct::~ElectricalProduct() {}

ElectricalProduct::TechnicalSpecification ElectricalProduct::GetTechnicalSpecification() const {
    return techSpec;
}

void ElectricalProduct::SetTechnicalSpecification(const TechnicalSpecification& tech) {
    techSpec = tech;
}

void ElectricalProduct::Display() {
    Product::Display();

    std::cout << "Technical Specification:" << std::endl;
    std::cout << "Resolution: " << techSpec.resolutionX << "x" << techSpec.resolutionY << std::endl;
    std::cout << "Capacity: " << techSpec.capacity << " GB" << std::endl;
    std::cout << "Screen Size: " << techSpec.screenSize << " inches" << std::endl;
    std::cout << "Wattage: " << techSpec.wattage << " watts" << std::endl;
    std::cout << "Operating System: " << techSpec.operatingSystem << std::endl;
}

std::ostream& operator<<(std::ostream& os, const ElectricalProduct& electricalProduct) {
    os << static_cast<const Product&>(electricalProduct);

    os << "Technical Specification:" << std::endl;
    os << "Resolution: " << electricalProduct.techSpec.resolutionX << "x" << electricalProduct.techSpec.resolutionY << std::endl;
    os << "Capacity: " << electricalProduct.techSpec.capacity << " GB" << std::endl;
    os << "Screen Size: " << electricalProduct.techSpec.screenSize << " inches" << std::endl;
    os << "Wattage: " << electricalProduct.techSpec.wattage << " watts" << std::endl;
    os << "Operating System: " << electricalProduct.techSpec.operatingSystem << std::endl;

    return os;
}

std::istream& operator>>(std::istream& is, ElectricalProduct& electricalProduct) {
    is >> static_cast<Product&>(electricalProduct);

    std::cout << "Enter Technical Specification:" << std::endl;
    std::cout << "Resolution (X Y): ";
    is >> electricalProduct.techSpec.resolutionX >> electricalProduct.techSpec.resolutionY;
    std::cout << "Capacity (GB): ";
    is >> electricalProduct.techSpec.capacity;
    std::cout << "Screen Size (inches): ";
    is >> electricalProduct.techSpec.screenSize;
    std::cout << "Wattage (watts): ";
    is >> electricalProduct.techSpec.wattage;
    std::cout << "Operating System: ";
    is >> electricalProduct.techSpec.operatingSystem;

    return is;
}
