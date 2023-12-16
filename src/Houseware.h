#ifndef HOUSEWARE_H
#define HOUSEWARE_H
#include "Product.h"
class Houseware : public Product
{
private:
    char *material;

public:
    Houseware();
    Houseware(int, int, char *, int, int, int, char *, Date, char *);
    ~Houseware();
    friend std::istream& operator>>(std::istream& , Houseware& ) ; 
    char *GetMaterial() const;
    void SetMaterial(char *&material);
    void Display();
    void Display_01(std::ostream &);
    void WriteDataToFile(std::ostream &) const;
    void ReadDataFromFile(std::istream &);
};
#endif