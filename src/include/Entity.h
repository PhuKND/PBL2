#include <string>

class Entity
{
protected:
   char* name;
    char* address;
    char* phoneNumber;
    char* email;

public:
    Entity( char* &name,  char* &address, char* &phoneNumber,  char* &email)
        : name(name), address(address), phoneNumber(phoneNumber), email(email)
    {
    }
    virtual void Display() ; 
};
