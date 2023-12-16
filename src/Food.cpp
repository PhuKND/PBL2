#include <iostream>
#include<limits>
#include "Food.h"
Food::Food()
{
    foodType = FoodType::Fresh;
    calories = 0.0;
    protein = 0.0;
    carbohydrates = 0.0;
    fat = 0.0;
    vitamins = 0.0;
    netWeight = 0.0;
    isExpired = false;
}

Food::Food(FoodType type, double cal, double prot, double carbs, double f, double vit, double weight, bool expired, int productID, int importPrice, char *LoaiSanPham, char *TenSanPham, int Price, int SoLuongDaBan, int SoLuongTonKho, char *NhaSanXuat, Date NgaySanXuat)
    : Product(productID, importPrice, TenSanPham, Price, SoLuongDaBan, SoLuongTonKho, NhaSanXuat, NgaySanXuat),
      foodType(type),
      calories(cal),
      protein(prot),
      carbohydrates(carbs),
      fat(f),
      vitamins(vit),
      netWeight(weight),
      isExpired(expired) {}

Food::~Food()
{

}

FoodType Food::GetFoodType() const
{
    return foodType;
}

void Food::SetFoodType(FoodType type)
{
    foodType = type;
}

double Food::GetCalories() const
{
    return calories;
}

void Food::SetCalories(double cal)
{
    calories = cal;
}

double Food::GetProtein() const
{
    return protein;
}

void Food::SetProtein(double prot)
{
    protein = prot;
}

double Food::GetCarbohydrates() const
{
    return carbohydrates;
}

void Food::SetCarbohydrates(double carbs)
{
    carbohydrates = carbs;
}

double Food::GetFat() const
{
    return fat;
}

void Food::SetFat(double f)
{
    fat = f;
}

double Food::GetVitamins() const
{
    return vitamins;
}

void Food::SetVitamins(double vit)
{
    vitamins = vit;
}

double Food::GetNetWeight() const
{
    return netWeight;
}

void Food::SetNetWeight(double weight)
{
    netWeight = weight;
}

bool Food::IsExpired() const
{
    return isExpired;
}

void Food::SetIsExpired(bool expired)
{
    isExpired = expired;
}

void Food::Display()
{
    Product::Display();
    std::cout << "Food Type: ";
    switch (foodType)
    {
    case FoodType::Fresh:
        std::cout << "Fresh" << std::endl;
        break;
    case FoodType::Canned:
        std::cout << "Canned" << std::endl;
        break;
    case FoodType::Packaged:
        std::cout << "Packaged" << std::endl;
        break;
    }
    std::cout << "Calories: " << calories << std::endl;
    std::cout << "Protein: " << protein << std::endl;
    std::cout << "Carbohydrates: " << carbohydrates << std::endl;
    std::cout << "Fat: " << fat << std::endl;
    std::cout << "Vitamins: " << vitamins << std::endl;
    std::cout << "Net Weight: " << netWeight << std::endl;
    std::cout << (isExpired ? "Expired" : "Not Expired") << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Food &obj)
{
    os << dynamic_cast<const Product &>(obj);
    os << static_cast<int>(obj.GetFoodType()) << ",";
    os << obj.GetCalories() << ",";
    os << obj.GetProtein() << ",";
    os << obj.GetCarbohydrates() << ",";
    os << obj.GetFat() << ",";
    os << obj.GetVitamins() << ",";
    os << obj.GetNetWeight() << ",";
    os << obj.IsExpired() << std::endl;
    return os;
}

void Food::Display_01(std::ostream &cout)
{
    Product::Display_01(cout);
    cout << std::left << std::setw(15) << static_cast<int>(foodType) << " | ";
    cout << std::left << std::setw(15) << calories << " | ";
    cout << std::left << std::setw(15) << protein << " | ";
    cout << std::left << std::setw(15) << carbohydrates << " | ";
    cout << std::left << std::setw(15) << fat << " | ";
    cout << std::left << std::setw(15) << vitamins << " | ";
    cout << std::left << std::setw(15) << netWeight << " | ";
    cout << std::left << std::setw(15) << (isExpired ? "Expired" : "Not Expired") << " | ";
    cout << "\n";
}

void Food::WriteDataToFile(std::ostream &file) const
{
    Product::WriteDataToFile(file);
    file << static_cast<int>(foodType) << ",";
    file << calories << ",";
    file << protein << ",";
    file << carbohydrates << ",";
    file << fat << ",";
    file << vitamins << ",";
    file << netWeight << ",";
    file << isExpired << std::endl;
}

void Food::ReadDataFromFile(std::istream &file)
{
    char comma;
    Product::ReadDataFromFile(file);
    int type;
    file >> type >> comma;
    foodType = static_cast<FoodType>(type);
    file >> calories >> comma;
    file >> protein >> comma;
    file >> carbohydrates >> comma;
    file >> fat >> comma;
    file >> vitamins >> comma;
    file >> netWeight >> comma;
    file >> isExpired ; 
}
std::istream& operator>>(std::istream& is, Food& food) {
    // Input for the base Product class
    is >> static_cast<Product&>(food);

    // Input for the Food-specific properties
    int foodTypeInt;
    std::cout << "Food Type (0: Fresh, 1: Canned, 2: Packaged): ";
    is >> foodTypeInt;
    food.foodType = static_cast<FoodType>(foodTypeInt);

    std::cout << "Calories: ";
    is >> food.calories;

    std::cout << "Protein: ";
    is >> food.protein;

    std::cout << "Carbohydrates: ";
    is >> food.carbohydrates;

    std::cout << "Fat: ";
    is >> food.fat;

    std::cout << "Vitamins: ";
    is >> food.vitamins;

    std::cout << "Net Weight: ";
    is >> food.netWeight;

    int isExpiredInt;
    std::cout << "Is Expired (0: No, 1: Yes): ";
    is >> isExpiredInt;
    food.isExpired = (isExpiredInt == 1);

    return is;
}

