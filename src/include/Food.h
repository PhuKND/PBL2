#ifndef FOOD_H
#define FOOD_H

#include "Product.h"

enum class FoodType
{
    Fresh,
    Canned,
    Packaged,
};

class Food : public Product
{
private:
    FoodType foodType;
    double calories;
    double protein;
    double carbohydrates;
    double fat;
    double vitamins;
    double netWeight;
    bool isExpired;

public:
    Food();
    Food(FoodType type, double cal, double prot, double carbs, double f, double vit, double weight, bool expired, int productID, int importPrice, char *LoaiSanPham, char *TenSanPham, int Price, int SoLuongDaBan, int SoLuongTonKho, char *NhaSanXuat, Date NgaySanXuat);
    ~Food();

    FoodType GetFoodType() const;
    void SetFoodType(FoodType type);

    double GetCalories() const;
    void SetCalories(double cal);

    double GetProtein() const;
    void SetProtein(double prot);

    double GetCarbohydrates() const;
    void SetCarbohydrates(double carbs);

    double GetFat() const;
    void SetFat(double f);

    double GetVitamins() const;
    void SetVitamins(double vit);

    double GetNetWeight() const;
    void SetNetWeight(double weight);

    bool IsExpired() const;
    void SetIsExpired(bool expired);

    void Display();
    void Display_01(std::ostream &);

    friend std::ostream &operator<<(std::ostream &, const Food &);
    friend std::istream &operator>>(std::istream &, Food &);

    void WriteDataToFile(std::ostream &file) const;
    void ReadDataFromFile(std::istream &file);
};

#endif
