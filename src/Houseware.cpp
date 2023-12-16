#include "Houseware.h"
#include<limits>
#include"Menu.h"
Houseware::Houseware() : Product(), material("") {}
Houseware::Houseware(int productID, int importPrice, char *TenSanPham,
                     int Price, int SoLuongDaBan, int SoLuongTonKho, char *NhaSanXuat, Date NgaySanXuat, char *mat)
{
}
Houseware::~Houseware() {}

char *Houseware::GetMaterial() const
{
    return material;
}
void Houseware::SetMaterial(char *&mat)
{
    material = mat;
}
void Houseware::Display()
{
    Product::Display();
    std::cout << "Material: " << material << std::endl;
}
void Houseware::Display_01(std::ostream &f)
{
    Product::Display_01(f);
    f << std::left << std::setw(15) << material << " | " << endl ;
}
std::istream& operator>>(std::istream& is, Houseware& houseware) {
     is >> static_cast<Product&>(houseware);
    std::cout << "Material: ";
    Menu::getInput(houseware.material, is);

    return is;
}
void Houseware::WriteDataToFile(std::ostream &file) const
{
    Product::WriteDataToFile(file);
    file << material << std::endl;
}
void Houseware::ReadDataFromFile(std::istream &file)
{
    Product::ReadDataFromFile(file);
    Menu::readAttributeTillDelimiter(material, file);
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
