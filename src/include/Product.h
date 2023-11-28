#ifndef PRODUCT_H
#define PRODUCT_H
#include"C:\Users\nguye\Downloads\Ky3\PBL2\src\Date.h"
#include <iomanip>
#include <iostream>
class Product {
private:
    int productID;
    int importID;
    char* TenSanPham;
    int Price;
    int SoLuongDaBan;
    int SoLuongTonKho;
    char* NhaSanXuat;
    Date NgaySanXuat;
    int SoLuongTrongGio; 
    enum class ProductType {
    Houseware,
    Food,
    Electrical,
};

public:
    Product();
    ~Product();
    Product(int , int , char* , int , int , int , char* , Date ) ; 
    char* getTenSanPham() const;
    void setTenSanPham( char* &TenSanPham);

    int getMaSanPham() const;
    void setMaSanPham(int MaSanPham);

    int getPrice() const;
    void setPrice(int Gia);

    int getSoLuongDaBan() ; 
    void setSoLuongDaBan(int) ; 

    int getSoLuongTonKho() const;
    void setSoLuongTonKho(int SoLuongTonKho);

    char* getNhaSanXuat() const;
    void setNhaSanXuat( char* &NhaSanXuat);

    Date getNgaySanXuat() const;
    void setNgaySanXuat( Date&);

    friend std::ostream &operator<<(std::ostream &out, const Product &product);
    virtual void Display() const;

    void WriteDataToFile(std::ostream &file) const;
    void Display_01(std::ostream&) ;
    void Display_Order(std::ostream&) ;
    void setSoLuongTrongGio(int) ; 
    int getSoLuongTrongGio() ; 
    // Trong lớp Product hoặc lớp cơ sở chung
// virtual void DisplayType() const = 0;

    void ReadDataFromFile(std::istream&) ; 
};
#endif 