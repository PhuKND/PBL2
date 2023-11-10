#include "include/DataManager.h"
#include <iomanip>
template <class T>
DataManager<T>::DataManager()
{
}
template <class T>
void DataManager<T>::ShowLists_file(const Vector_Class<T> &data, const char *filename)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        if (typeid(T) == typeid(Employee))
        {
            file << "Employee Information" << endl;
        }
        else if (typeid(T) == typeid(Customer))
        {
            file << "Customer information" << endl;
        }
        file << "STT" << std::right << std::setw(3) << "|";
        file << "ID" << std::right << std::setw(16) << "|";
        file << "Full Name" << std::right << std::setw(14) << "|";
        file << "Age" << std::right << std::setw(4) << "|";
        file << "Day of birth" << std::right << std::setw(11) << "|";
        file << "Address" << std::right << std::setw(21) << "|";
        file << "Phone number" << std::right << std::setw(6) << "|";
        file << "Email" << std::right << std::setw(28) << "|";
        if (typeid(T) == typeid(Employee))
        {
            file << "Position" << std::right << std::setw(15) << "|";
            file << "Salary" << std::right << std::setw(7) << "|";
            file << "Start day" << std::right << std::setw(9) << "|";
            file << "End day" << std::right << std::setw(11) << "|";
            file << "Is working" << std::right << std::setw(3) << "|";
        }
        else if (typeid(T) == typeid(Customer))
        {
            file << "Point" << std::right << std::setw(15) << "|";
            file << "Customer Type" << std::right << std::setw(7) << "|";
        }
        file << std::endl;
        for (int i = 0; i < 256; ++i) {
            file << '-';
    }
        cout << endl ;
        for (size_t i = 0; i < data.getSize(); i++)
        {
            file << std::left << std::setw(4) << i + 1 << " | ";
            data.at(i).Display_01(file);
        }
        file.close();
    }
}

template <class T>
void DataManager<T>::Display(const Vector_Class<T> &data)
{
    if (typeid(T) == typeid(Employee))
    {
        cout << "Employee Information" << endl;
    }
    else if (typeid(T) == typeid(Customer))
    {
        cout << "Customer information" << endl;
    }
    cout << "STT" << std::right << std::setw(3) << "|";
    cout << "ID" << std::right << std::setw(16) << "|";
    cout << "Full Name" << std::right << std::setw(14) << "|";
    cout << "Age" << std::right << std::setw(4) << "|";
    cout << "Day of birth" << std::right << std::setw(11) << "|";
    cout << "Address" << std::right << std::setw(21) << "|";
    cout << "Phone number" << std::right << std::setw(6) << "|";
    cout << "Email" << std::right << std::setw(28) << "|";
    if (typeid(T) == typeid(Employee))
    {
        cout << "Position" << std::right << std::setw(15) << "|";
        cout << "Salary" << std::right << std::setw(7) << "|";
        cout << "Start day" << std::right << std::setw(9) << "|";
        cout << "End day" << std::right << std::setw(11) << "|";
        cout << "Is working" << std::right << std::setw(3) << "|";
    }
    else if (typeid(T) == typeid(Customer))
    {
        cout << "Point" << std::right << std::setw(15) << "|";
        cout << "Customer Type" << std::right << std::setw(7) << "|";
    }
    cout << std::endl;
    for (int i = 0; i < 256; ++i) {
        std::cout << '-';
    }
         cout << endl ;
    for (size_t i = 0; i < data.getSize(); i++)
    {
        cout << std::left << std::setw(4) << i + 1 << " | ";
        data.at(i).Display_01(std::cout); 
    }
}

template <class T>
void DataManager<T>::AddToLists(const T &obj)
{
    lists.pushBack(obj);
}

template <class T>
void DataManager<T>::SaveData(const Vector_Class<T> data, const char *filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (size_t i = 0; i < data.getSize(); i++) {
            data[i].WriteDataToFile(file); // Assuming WriteDataToFile exists in the T class
        }
        file.close();
    } else {
        std::cerr << "Can't open file for writing" << std::endl;
    }
}

template <class T>
void DataManager<T>::GetData(Vector_Class<T> &data, const char *filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        T temp;

        while (!file.eof()) {
            temp.ReadDataFromFile(file); 
            if (file.eof()) {
                break;
            }
            data.pushBack(temp);
        }
        file.close();
    } else {
        std::cerr << "Can't open file for reading" << std::endl;
    }
}
