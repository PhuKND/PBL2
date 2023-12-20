#include "DataManager.h"
#include <iomanip>
template <class T>
DataManager<T>::DataManager()
{
}
template <class T>
void DataManager<T>::ShowLists_file(const Vector_Class<T>& data, const char* filename)
{
	std::ofstream file(filename);
	if (file.is_open())
	{
		if (typeid(T) == typeid(Customer) || typeid(T) == typeid(Employee))
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
		}
		else if (typeid(T) == typeid(Food) || typeid(T) == typeid(ElectricalProduct) || typeid(T) == typeid(Houseware))
		{
			cout << "STT" << std::right << std::setw(3) << "|";
			cout << "Product ID" << std::right << std::setw(16) << "|";
			cout << "Import ID" << std::right << std::setw(14) << "|";
			cout << "Product Name" << std::right << std::setw(4) << "|";
			cout << "Price" << std::right << std::setw(11) << "|";
			cout << "Quantity Sold" << std::right << std::setw(21) << "|";
			cout << "Quanity in Stock" << std::right << std::setw(6) << "|";
			cout << "Manufacturer" << std::right << std::setw(28) << "|";
			cout << "Production Date" << std::right << std::setw(28) << "|";
			if (typeid(T) == typeid(Food))
			{
				cout << "Food Type" << std::right << std::setw(4) << "|";
				cout << "Calories" << std::right << std::setw(11) << "|";
				cout << "Carbohydrates" << std::right << std::setw(21) << "|";
				cout << "Fat" << std::right << std::setw(6) << "|";
				cout << "Vitamins" << std::right << std::setw(28) << "|";
				cout << "Net Weight" << std::right << std::setw(28) << "|";
				cout << "Is Expired" << std::right << std::setw(28) << "|";
			}
			else if (typeid(T) == typeid(ElectricalProduct))
			{
				cout << "Resolution" << std::right << std::setw(28) << "|";
				cout << "Capacity" << std::right << std::setw(18) << "|";
				cout << "Screen Size" << std::right << std::setw(18) << "|";
				cout << "Wattage" << std::right << std::setw(18) << "|";
				cout << "Operating System" << std::right << std::setw(18) << "|";
			}
			else if (typeid(T) == typeid(Houseware))
			{
				cout << "Matterial" << std::right << std::setw(19) << "|";
			}
		}
		file << std::endl;
		for (int i = 0; i < 200; ++i)
		{
			file << '-';
		}
		file << endl;
		for (size_t i = 0; i < data.getSize(); i++)
		{
			file << std::left << std::setw(4) << i + 1 << " | ";
			data.at(i).Display_01(file);
		}
		file.close();
	}
}

template <class T>
void DataManager<T>::Display(const Vector_Class<T>& data)
{

	if (typeid(T) == typeid(Customer) || typeid(T) == typeid(Employee))
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
	}
	else if (typeid(T) == typeid(Food) || typeid(T) == typeid(ElectricalProduct) || typeid(T) == typeid(Houseware))
	{
		cout << "STT" << std::right << std::setw(3) << "|";
		cout << "Product ID" << std::right << std::setw(0) << "|";
		cout << "Import ID" << std::right << std::setw(0) << "|";
		cout << "Product Name" << std::right << std::setw(6) << "|";
		cout << "Price" << std::right << std::setw(0) << "|";
		cout << "Quantity Sold" << std::right << std::setw(0) << "|";
		cout << "Quanity in Stock" << std::right << std::setw(0) << "|";
		cout << "Manufacturer" << std::right << std::setw(5) << "|";
		cout << "Production Date" << std::right << std::setw(0) << "|";
		if (typeid(T) == typeid(Food))
		{
			cout << "Food Type" << std::right << std::setw(1) << "|";
			cout << "Calories" << std::right << std::setw(1) << "|";
			cout << "Carbohydrates" << std::right << std::setw(1) << "|";
			cout << "Fat" << std::right << std::setw(1) << "|";
			cout << "Vitamins" << std::right << std::setw(1) << "|";
			cout << "Net Weight" << std::right << std::setw(1) << "|";
			cout << "Is Expired" << std::right << std::setw(1) << "|";
		}
		else if (typeid(T) == typeid(ElectricalProduct))
		{
			cout << "Resolution" << std::right << std::setw(1) << "|";
			cout << "Capacity" << std::right << std::setw(1) << "|";
			cout << "Screen Size" << std::right << std::setw(1) << "|";
			cout << "Wattage" << std::right << std::setw(1) << "|";
			cout << "Operating System" << std::right << std::setw(1) << "|";
		}
		else if (typeid(T) == typeid(Houseware))
		{
			cout << "Material" << std::right << std::setw(1) << "|";
		}
	}
	if (typeid(T) == typeid(Discount))
    {
        cout << "STT" << std::right << std::setw(3) << "|";
        cout << "Discount ID" << std::right << std::setw(0) << "|";
        cout << "Discount Type" << std::right << std::setw(20) << "|";
        cout << "Coupon Code" << std::right << std::setw(4) << "|";
        cout << "Percentage" << std::right << std::setw(20) << "|";
        cout << "Quantity" << std::right << std::setw(25) << "|";
        cout << "Available" << std::right << std::setw(15) << "|";
        cout << "Holder ID" << std::right << std::setw(30) << "|";
        cout << "\n";
	}
	cout << std::endl;
	for (int i = 0; i < 200; ++i)
	{
		std::cout << '-';
	}
	cout << endl;
	for (size_t i = 0; i < data.getSize(); i++)
	{
		cout << std::left << std::setw(4) << i + 1 << " | ";
		data.at(i).Display_01(std::cout);
	}
}

template <class T>
void DataManager<T>::AddToLists(const T& obj)
{
	lists.pushBack(obj);
}

template <class T>
void DataManager<T>::SaveData(const Vector_Class<T> data, const char* filename)
{
	std::ofstream file(filename);
	if (file.is_open())
	{
		for (size_t i = 0; i < data.getSize(); i++)
		{
			data[i].WriteDataToFile(file);
		}
		file.close();
	}
	else
	{
		std::cerr << "Can't open" << filename << "for writing" << std::endl;
	    }
}


template <class T>
void DataManager<T>::GetData(Vector_Class<T>& data, const char* filename)
{
	std::ifstream file(filename);
	if (file.is_open())
	{
		T temp;
		while (!file.eof())
		{
			temp.ReadDataFromFile(file);
			if (file.eof())
			{
				break;
			}
			data.pushBack(temp);
		}
		file.close();
	}
	else
	{
		std::cerr << "Can't open " << filename << "for reading" << std::endl;
	}
}
