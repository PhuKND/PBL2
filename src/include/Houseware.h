#pragma once
#include "Product.h"

class Houseware : public Product {
private:
    std::string material;

public:
    Houseware();
    Houseware(const std::string& name, int id, double price, int stock, const std::string& manufacturer, const std::string& description, const std::string& material);
    ~Houseware();

    std::string GetMaterial() const;
    void SetMaterial(const std::string& material);
    void Display();
};
