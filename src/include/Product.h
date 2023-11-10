#pragma once
#include"Menu.h"
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
    char* NgaySanXuat;

public:
    Product();
    ~Product();
    Product(int , int , char* , int , int , int , char* , char* ) ; 
    char* getTenSanPham() const;
    void setTenSanPham( char* &TenSanPham);

    int getMaSanPham() const;
    void setMaSanPham(int MaSanPham);

    int getPrice() const;
    void setPrice(int Gia);

    int getSoLuongTonKho() const;
    void setSoLuongTonKho(int SoLuongTonKho);

    char* getNhaSanXuat() const;
    void setNhaSanXuat( char* &NhaSanXuat);

    char* getNgaySanXuat() const;
    void setNgaySanXuat( char* &NgaySanXuat);

    friend std::ostream &operator<<(std::ostream &out, const Product &product);
    void Display() const;

    void WriteDataToFile(std::ostream &file) const;
    void Display_01(std::ostream&) ; 

    void ReadDataFromFile(std::istream&) ; 
};
