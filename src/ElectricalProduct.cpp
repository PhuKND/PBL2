#include "include/ElectricalProduct.h"
#include"include/Menu.h"
#include<limits>
ElectricalProduct::ElectricalProduct() : Product(), techSpec() {}

ElectricalProduct::ElectricalProduct(int productID, int importID,  char* TenSanPham,
                 int Price, int SoLuongDaBan, int SoLuongTonKho,  char*NhaSanXuat, Date NgaySanXuat 
                                    ,const TechnicalSpecification &tech)
    : Product(productID,importID,TenSanPham,Price,SoLuongDaBan,SoLuongTonKho,NhaSanXuat,NgaySanXuat), techSpec(tech) {}

ElectricalProduct::~ElectricalProduct()
{
    // Destructor implementation here, if needed
}

ElectricalProduct::TechnicalSpecification ElectricalProduct::GetTechnicalSpecification() const
{
    return techSpec;
}

void ElectricalProduct::SetTechnicalSpecification(const TechnicalSpecification &tech)
{
    techSpec = tech;
}

void ElectricalProduct::Display()
{
    Product::Display();
    std::cout << "Resolution: " << techSpec.resolutionX << "x" << techSpec.resolutionY << std::endl;
    std::cout << "Capacity: " << techSpec.capacity << " GB" << std::endl;
    std::cout << "Screen Size: " << techSpec.screenSize << " inches" << std::endl;
    std::cout << "Wattage: " << techSpec.wattage << " watts" << std::endl;
    std::cout << "Operating System: " << techSpec.operatingSystem << std::endl;
}

void ElectricalProduct::Display_01(std::ostream& file)
{
    Product::Display_01(file);
    file << std::left << std::setw(3) << techSpec.resolutionX << " | ";
    file << std::left << std::setw(3) << techSpec.resolutionY << " | ";
    file << std::left << std::setw(3) << techSpec.capacity << " | ";
    file << std::left << std::setw(3) << techSpec.screenSize << " | ";
    file << std::left << std::setw(3) << techSpec.wattage << " | ";
    file << std::left << std::setw(3) << techSpec.operatingSystem << " | ";
    file << "\n";
}

void ElectricalProduct::WriteDataToFile(std::ostream &file) const
{
    Product::WriteDataToFile(file);
    file << techSpec.resolutionX << ",";
    file << techSpec.resolutionY << ",";
    file << techSpec.capacity << ",";
    file << techSpec.screenSize << ",";
    file << techSpec.wattage << ",";
    file << techSpec.operatingSystem << std::endl;
}

void ElectricalProduct::ReadDataFromFile(std::istream &file)
{
    char comma;
    Product::ReadDataFromFile(file);
    file >> techSpec.resolutionX >> comma;
    file >> techSpec.resolutionY >> comma;
    file >> techSpec.capacity >> comma;
    file >> techSpec.screenSize >> comma;
    file >> techSpec.wattage >> comma;
    Menu::readAttributeTillDelimiter(techSpec.operatingSystem,file) ; 
}
