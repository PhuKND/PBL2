#include "include/Houseware.h"
#include <iostream>

Houseware::Houseware() : Product(), material("") {}

Houseware::Houseware(const std::string& name, int id, double price, int stock, const std::string& manufacturer, const std::string& description, const std::string& mat)
    : Product(name, id, price, stock, manufacturer, description), material(mat) {}

Houseware::~Houseware() {}

std::string Houseware::GetMaterial() const {
    return material;
}

void Houseware::SetMaterial(const std::string& mat) {
    material = mat;
}

void Houseware::Display() {
    Product::Display();
    std::cout << "Material: " << material << std::endl;
}
