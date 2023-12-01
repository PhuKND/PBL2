#pragma once
#include <fstream>
#include "Employee.h"
#include "Customer.h"
#include"Food.h"
#include"ElectricalProduct.h"
#include"Houseware.h"
#include "Vector.h"
#include "Vector_Class.h"
class Customer;
class Employee;
class Food;
class ElectricalProduct;
class Houseware;
class Order;
class Discount;

template <class T>
class DataManager
{
public:
    DataManager();
    
    Vector_Class<T> lists;
    void AddToLists(const T &);
    void Display(const Vector_Class<T>&);
    void ShowLists_file(const Vector_Class<T> &data, const char *filename);
    void SaveData(const Vector_Class<T> data , const char* ) ;
    void GetData( Vector_Class<T> &data, const char* ) ;
};