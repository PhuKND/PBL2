#include "Product.h"
#include"Menu.h"
#include<iomanip>
using namespace std;
Product::Product() {
    productID = 0;
    importPrice = 0;
    TenSanPham = "";
    Price = 0;
    SoLuongDaBan = 0;
    SoLuongTonKho = 0;
    SoLuongTrongGio = 0  ;
    NhaSanXuat = "";
    NgaySanXuat = Date(0,0,0);
    NgayNhapHang = Time(1,1,1); 
}
Product::Product(int productID, int importPrice,  char* TenSanPham,
                 int Price, int SoLuongDaBan, int SoLuongTonKho,  char*NhaSanXuat,  Date NgaySanXuat)
    : productID(productID), importPrice(importPrice),  TenSanPham(TenSanPham),
      Price(Price), SoLuongDaBan(SoLuongDaBan), SoLuongTonKho(SoLuongTonKho), NhaSanXuat(NhaSanXuat), NgaySanXuat(NgaySanXuat) {
        this -> SoLuongTrongGio = 0 ;
}

Product::~Product() {
}

char* Product::getTenSanPham() const {
    return TenSanPham;
}

void Product::setTenSanPham(char* &TenSanPham) {
    this->TenSanPham = TenSanPham;
}
// Trong lớp Product
void Product::EditProduct() {
    int choice;
    do {
        // Hiển thị menu sửa thông tin
        cout << "1. Edit Product Name\n";
        cout << "2. Edit Price\n";
        cout << "3. Edit Quantity in Stock\n";
        cout << "4. Edit Manufacturer\n";
        cout << "5. Edit Production Date\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Sử dụng switch case để xử lý từng lựa chọn
        switch (choice) {
            case 1: {
                cout << "Enter new product name: ";
                Menu::getInput(TenSanPham, cin);
                break;
            }
            case 2: {
                cout << "Enter new price: ";
                cin >> Price;
                break;
            }
            case 3: {
                cout << "Enter new quantity in stock: ";
                cin >> SoLuongTonKho;
                break;
            }
            case 4: {
                cout << "Enter new manufacturer: ";
                Menu::getInput(NhaSanXuat, cin);
                break;
            }
            case 5: {
                cout << "Enter new production date: ";
                cin >> NgaySanXuat;
                break;
            }
            case 0: {
                cout << "Exiting product edit menu.\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please enter a valid option.\n";
            }
        }
    } while (choice != 0);
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
int Product::GetImportPrice() const {
    return importPrice ; 
}
void Product::SetImportPrice(int price) { 
    this -> importPrice = price; 
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
Time Product::getNgayNhapHang()const {
    return NgayNhapHang ;
}
void Product::setNgayNhapHang(Time& date){
    this -> NgayNhapHang = date ;
}
Date Product::getNgaySanXuat() const {
    return NgaySanXuat;
}

void Product::setNgaySanXuat(Date& date) {
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
    out << "Import Price : " << product.importPrice << "\n";
    out << "Product Name: " << product.TenSanPham << "\n";
    out << "Price: " << product.Price << "\n";
    out << "Quantity Sold: " << product.SoLuongDaBan << "\n";
    out << "Quantity in Stock: " << product.SoLuongTonKho << "\n";
    out << "Manufacturer: " << product.NhaSanXuat << "\n";
    out << "Production Date: " << product.NgaySanXuat << "\n";
    return out;
}
std::istream& operator>>(std::istream& is , Product & product){
    std::cout << "Enter Product ID : " ; 
    is >> product.productID ; 
    std::cout << "Import Price : " ; 
    is >> product.importPrice ; 
    std::cout <<" Product name : " ; 
    Menu::getInput(product.TenSanPham,is) ;
    std::cout << "Price : " ; 
    is >> product.Price ; 
    std::cout << "Quanity in Stock : "; 
    is >> product.SoLuongTonKho ;
    std::cout << "Manufacturer : " ;
    Menu::getInput(product.NhaSanXuat,is);
    std::cout << "Production Date : " ; 
    is >> product.NgaySanXuat ;  
return is ;
}
void Product::Display() const {
    std::cout << *this;
}
void Product::Display_01(std::ostream& f ){
    f << std::left << std::setw(8) << getMaSanPham() << " | ";
    f << std::left << std::setw(8) << GetImportPrice() << " | " ; 
    f << std::left << std::setw(25) << getTenSanPham() << " | ";
    f << std::left << std::setw(4) <<  getPrice()<< " | ";
    f << std::left << std::setw(5) << getSoLuongTonKho() << " | ";
    f << std::left << std::setw(10) << getNhaSanXuat() << " | ";
    f << std::left << std::setw(0) <<std::right << std::setw(0)  << getNgaySanXuat() << " | ";
}
void Product::WriteDataToFile(std::ostream &file) const {
    file << productID << ","
        << NgayNhapHang << ","
         << importPrice << ","
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
    file >> NgayNhapHang >> comma ;
    file >> importPrice>> comma ;
    Menu::readAttributeTillDelimiter(TenSanPham,file) ; 
    file >> Price >> comma ;
    file >> SoLuongDaBan >> comma ;
    file >> SoLuongTonKho >> comma ;
    Menu::readAttributeTillDelimiter(NhaSanXuat,file) ; 
    file >> NgaySanXuat >> comma ; 
    }
void Product::Display_Order(std::ostream& o) {
    o << std::left << std::setw(11) << getMaSanPham() << " | ";
    o << std::left << std::setw(25) << getTenSanPham() << " | ";
    o << std::left << "$" << std::setw(8) << getPrice()<< " | ";
    o << std::left << std::setw(6) << getSoLuongTrongGio() << " | ";
    o << std::left << "$"<<  std::setw(6) << getPrice()*getSoLuongTrongGio() << " | ";
    o << endl ;
}