#include "include/Product.h"
#include"include/Menu.h"
#include<iomanip>
using namespace std;
Product::Product() {
    productID = 0;
    importID = 0;
    TenSanPham = "";
    Price = 0;
    SoLuongDaBan = 0;
    SoLuongTonKho = 0;
    NhaSanXuat = "";
    NgaySanXuat = "";
}
Product::Product(int productID, int importID,  char* TenSanPham,
                 int Price, int SoLuongDaBan, int SoLuongTonKho,  char*NhaSanXuat,  char*NgaySanXuat)
    : productID(productID), importID(importID),  TenSanPham(TenSanPham),
      Price(Price), SoLuongDaBan(SoLuongDaBan), SoLuongTonKho(SoLuongTonKho), NhaSanXuat(NhaSanXuat), NgaySanXuat(NgaySanXuat) {
}

Product::~Product() {
}

char* Product::getTenSanPham() const {
    return TenSanPham;
}

void Product::setTenSanPham(char* &TenSanPham) {
    this->TenSanPham = TenSanPham;
}

int Product::getMaSanPham() const {
    return productID;
}

void Product::setMaSanPham(int MaSanPham) {
    productID = MaSanPham;
}

int Product::getPrice() const {
    return Price;
}

void Product::setPrice(int Gia) {
    Price = Gia;
}
void Product::setSoLuongDaBan(int sl) { 
    this -> SoLuongDaBan = sl ; 
}
int Product ::getSoLuongDaBan() {
    return SoLuongDaBan ; 
}
int Product::getSoLuongTonKho() const {
    return SoLuongTonKho;
}

void Product::setSoLuongTonKho(int SoLuongTonKho) {
    this->SoLuongTonKho = SoLuongTonKho;
}

char* Product::getNhaSanXuat() const {
    return NhaSanXuat;
}

void Product::setNhaSanXuat( char* &NhaSanXuat) {
    this->NhaSanXuat = NhaSanXuat;
}

char* Product::getNgaySanXuat() const {
    return NgaySanXuat;
}

void Product::setNgaySanXuat(char* &NgaySanXuat) {
    this->NgaySanXuat = NgaySanXuat;
}
void Product::setSoLuongTrongGio(int quantity) {
    SoLuongTrongGio = quantity;
}

// Implement getSoLuongTrongGio
int Product::getSoLuongTrongGio() {
    return SoLuongTrongGio;
}
std::ostream &operator<<(std::ostream &out, const Product &product) {
    out << "Product ID: " << product.productID << "\n";
    out << "Import ID: " << product.importID << "\n";
    out << "Product Name: " << product.TenSanPham << "\n";
    out << "Price: " << product.Price << "\n";
    out << "Quantity Sold: " << product.SoLuongDaBan << "\n";
    out << "Quantity in Stock: " << product.SoLuongTonKho << "\n";
    out << "Manufacturer: " << product.NhaSanXuat << "\n";
    out << "Production Date: " << product.NgaySanXuat << "\n";
    return out;
}

void Product::Display() const {
    std::cout << *this;
}
void Product::Display_01(std::ostream& f ){
    f << std::left << std::setw(15) << getMaSanPham() << " | ";
    f << std::left << std::setw(20) << getTenSanPham() << " | ";
    f << std::left << std::setw(4) <<  getPrice()<< " | ";
    f << std::left << std::setw(20) << getSoLuongTonKho() << " | ";
    f << std::left << std::setw(25) << getNhaSanXuat() << " | ";
    f << std::left << std::setw(15) << getNgaySanXuat() << " | ";
}
void Product::WriteDataToFile(std::ostream &file) const {
    file << productID << ","
         << importID << ","
         << TenSanPham << ","
         << Price << ","
         << SoLuongDaBan << ","
         << SoLuongTonKho << ","
         << NhaSanXuat << ","
         << NgaySanXuat << "," ; 
}

void Product::ReadDataFromFile(std::istream& file) {
    char comma ; 
    file >> productID >> comma ; 
    file >> importID >> comma ;
    Menu::readAttributeTillDelimiter(TenSanPham,file) ; 
    file >> Price >> comma ;
    file >> SoLuongDaBan >> comma ;
    file >> SoLuongTonKho >> comma ;
    Menu::readAttributeTillDelimiter(NhaSanXuat,file) ; 
    Menu::readAttributeTillDelimiter(NgaySanXuat,file) ; 
}
void Product::Display_Order(std::ostream& o) {
    o << std::left << std::setw(15) << getMaSanPham() << " | ";
    o << std::left << std::setw(20) << getTenSanPham() << " | ";
    o << std::left << std::setw(6) <<  getPrice()<< " | ";
    o << std::left << std::setw(6) << getSoLuongTrongGio() << " | ";
    o << std::left << std::setw(6) << getPrice()*getSoLuongTrongGio() << " | ";
    o << endl ;
}