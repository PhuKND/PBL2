#ifndef PRODUCT_H
#define PRODUCT_H
#include"Date.h"
#include <iomanip>
#include"Time.h"
// #include"Discount.h"
#include <iostream>
class Product {
private:
    int productID;
    Time NgayNhapHang; 
    char* TenSanPham;
    int importPrice; 
    int Price;
    int SoLuongDaBan;
    int SoLuongTonKho;
    char* NhaSanXuat;
    int SoLuongNhapHang ;
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
    int getSoLuongNhapHang() const ; 
    void setSoLuongNhapHang(int) ;
    void EditProduct() ; 
    Time getNgayNhapHang() const ; 
    void setNgayNhapHang(Time&) ; 
    int GetImportPrice() const ;
    void SetImportPrice(int) ;

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
    friend std::istream &operator>>(std::istream &is ,Product&)  ;
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