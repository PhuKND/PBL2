
#include "Statistics.h"

Statistics::Statistics()
    : StatisticsType(nullptr), timePeriod(nullptr), StatisticsData(nullptr),
      totalRevenue(0.0), totalExpenses(0.0), totalProfit(0.0),
      totalAmountIn(0.0), totalAmountOut(0.0), employeeSalaries(),
      customerID(0), paidAmount(0.0), paidQuantity(0),
      avgQuantityPerOrder(0.0), avgAmountPerOrder(0.0),
      favouriteProductID(0), savedMoneyDiscount(0.0),
      employeeID(0), numExecutedOrders(0)
{
}

// Constructor cho Siêu thị
Statistics::Statistics(int day , int month , int year ,char *rType, char *tPeriod, char *rData,
                       double tRevenue, double tExpenses, double tProfit,
                       double tAmountIn, double tAmountOut,
                       const Vector_Class<Employee> &empSalaries)
    :day(day),month(month),year(year), StatisticsType(nullptr), timePeriod(nullptr), StatisticsData(nullptr),
      totalRevenue(tRevenue), totalExpenses(tExpenses), totalProfit(tProfit),
      totalAmountIn(tAmountIn), totalAmountOut(tAmountOut),
      employeeSalaries(empSalaries),
      customerID(0), paidAmount(0.0), paidQuantity(0),
      avgQuantityPerOrder(0.0), avgAmountPerOrder(0.0),
      favouriteProductID(0), savedMoneyDiscount(0.0),
      employeeID(0), numExecutedOrders(0)
{
    SetStatisticsType(rType);
    SetTimePeriod(tPeriod);
    SetStatisticsData(rData);
}

// Constructor cho Khách hàng
Statistics::Statistics(int day, int month , int year, int cID, double pAmount, int pQuantity,
                       double avgQPerOrder, double avgAPerOrder,
                       int favProductID, double savedMoneyDis)
    : day(day),month(month), year(year), customerID(cID), paidAmount(pAmount), paidQuantity(pQuantity),
      avgQuantityPerOrder(avgQPerOrder), avgAmountPerOrder(avgAPerOrder),
      favouriteProductID(favProductID), savedMoneyDiscount(savedMoneyDis)
{
    // Initialize other member variables
    totalOrders = 0;
    totalAmountSpent = 0.0;
    savedMoneyDiscount = 0.0;
    repeatPurchaseRate = 0.0;
    customerLifetimeValue = 0.0;
    avgDiscountRate = 0.0;
}

// Constructor cho Nhân viên
Statistics::Statistics(int eID, int numOrders)
    : StatisticsType(nullptr), timePeriod(nullptr), StatisticsData(nullptr),
      totalRevenue(0.0), totalExpenses(0.0), totalProfit(0.0),
      totalAmountIn(0.0), totalAmountOut(0.0), employeeSalaries(),
      customerID(0), paidAmount(0.0), paidQuantity(0),
      avgQuantityPerOrder(0.0), avgAmountPerOrder(0.0),
      favouriteProductID(0), savedMoneyDiscount(0.0),
      employeeID(eID), numExecutedOrders(numOrders)
{
}

// Destructor
Statistics::~Statistics()
{
    // Giải phóng bộ nhớ
    delete[] StatisticsType;
    delete[] timePeriod;
    delete[] StatisticsData;
}

// Các getter và setter cũng cần được triển khai tương ứng
char *Statistics::GetStatisticsType() const
{
    return StatisticsType;
}

void Statistics::SetStatisticsType(char *newStatisticsType)
{
    this->StatisticsType = newStatisticsType;
}

char *Statistics::GetTimePeriod() const
{
    return timePeriod;
}

void Statistics::SetTimePeriod(char *newTimePeriod)
{
    this->timePeriod = newTimePeriod;
}
char *Statistics::GetStatisticsData() const
{
    return StatisticsData;
}
void Statistics::SetStatisticsData(char *newStatisticsData)
{
    this->StatisticsData = newStatisticsData;
}
double Statistics::GetTotalRevenue() const
{
    return totalRevenue;
}
void Statistics::SetTotalRevenue(double newTotalRevenue)
{
    this->totalRevenue = newTotalRevenue;
}
double Statistics::GetTotalExpenses() const
{
    return totalExpenses;
}
void Statistics::SetTotalExpenses(double newTotalExpenses)
{
    this->totalExpenses = newTotalExpenses;
}
double Statistics::GetTotalProfit() const
{
    return totalProfit;
}
void Statistics::SetTotalProfit(double newTotalProfit)
{
    this->totalProfit = newTotalProfit;
}
double Statistics::GetTotalAmountIn() const
{
    return totalAmountIn;
}
void Statistics::SetTotalAmountIn(double newTotalAmountIn)
{
    this->totalAmountIn = newTotalAmountIn;
}
double Statistics::GetTotalAmountOut() const
{
    return totalAmountOut;
}
void Statistics::SetTotalAmountOut(double newTotalAmountOut)
{
    this->totalAmountOut = newTotalAmountOut;
}
// Getter and setter methods for Khách hàng
int Statistics::GetCustomerID() const
{
    return customerID;
}

void Statistics::SetCustomerID(int newCustomerID)
{
    customerID = newCustomerID;
}

double Statistics::GetPaidAmount() const
{
    return paidAmount;
}

void Statistics::SetPaidAmount(double newPaidAmount)
{
    paidAmount = newPaidAmount;
}

int Statistics::GetPaidQuantity() const
{
    return paidQuantity;
}

void Statistics::SetPaidQuantity(int newPaidQuantity)
{
    paidQuantity = newPaidQuantity;
}

double Statistics::GetAvgQuantityPerOrder() const
{
    return avgQuantityPerOrder;
}

void Statistics::SetAvgQuantityPerOrder(double newAvgQuantityPerOrder)
{
    avgQuantityPerOrder = newAvgQuantityPerOrder;
}

double Statistics::GetAvgAmountPerOrder() const
{
    return avgAmountPerOrder;
}

void Statistics::SetAvgAmountPerOrder(double newAvgAmountPerOrder)
{
    avgAmountPerOrder = newAvgAmountPerOrder;
}

int Statistics::GetFavouriteProductID() const
{
    return favouriteProductID;
}

void Statistics::SetFavouriteProductID(int newFavouriteProductID)
{
    favouriteProductID = newFavouriteProductID;
}

double Statistics::GetSavedMoneyDiscount() const
{
    return savedMoneyDiscount;
}

void Statistics::SetSavedMoneyDiscount(double newSavedMoneyDiscount)
{
    savedMoneyDiscount = newSavedMoneyDiscount;
}

// Getter and setter methods for Nhân viên
int Statistics::GetEmployeeID() const
{
    return employeeID;
}

void Statistics::SetEmployeeID(int newEmployeeID)
{
    employeeID = newEmployeeID;
}

int Statistics::GetNumExecutedOrders() const
{
    return numExecutedOrders;
}

void Statistics::SetNumExecutedOrders(int newNumExecutedOrders)
{
    numExecutedOrders = newNumExecutedOrders;
}
int Statistics::GetTotalOrders() const
{
    return totalOrders;
}

double Statistics::GetTotalAmountSpent() const
{
    return totalAmountSpent;
}

double Statistics::GetRepeatPurchaseRate() const
{
    return repeatPurchaseRate;
}

double Statistics::GetCustomerLifetimeValue() const
{
    return customerLifetimeValue;
}

double Statistics::GetAvgDiscountRate() const
{
    return avgDiscountRate;
}
int Statistics::getImportCost() const {
    return importCost ; 
}
void Statistics::setImportCost(int cost) { 
    this -> importCost = cost ;
}

void Statistics::SetTotalOrders(int newTotalOrders)
{
    totalOrders = newTotalOrders;
}

void Statistics::SetTotalAmountSpent(double newTotalAmountSpent)
{
    totalAmountSpent = newTotalAmountSpent;
}

void Statistics::SetRepeatPurchaseRate(double newRepeatPurchaseRate)
{
    repeatPurchaseRate = newRepeatPurchaseRate;
}

void Statistics::SetCustomerLifetimeValue(double newCustomerLifetimeValue)
{
    customerLifetimeValue = newCustomerLifetimeValue;
}

void Statistics::SetAvgDiscountRate(double newAvgDiscountRate)
{
    avgDiscountRate= newAvgDiscountRate;
}
int Statistics::GetNumberOfCustomers() const
{
    return numberCustomer;
}
void Statistics::SetNumberOfCustomers(int newNumberOfCustomers)
{
    numberCustomer = newNumberOfCustomers;
}

int Statistics::GetTotalUnitsSold() const
{
    return totalUnitsSold;
}

void Statistics::SetTotalUnitsSold(int newTotalUnitsSold)
{
    totalUnitsSold = newTotalUnitsSold;
}
int Statistics::GetNumberOfSalesInvoices() const
{
    return numberInvoice;
}

void Statistics::SetNumberOfSalesInvoices(int newNumberOfSalesInvoices)
{
    numberInvoice = newNumberOfSalesInvoices;
}

int Statistics::GetBestSellingProduct() const
{
    return 0; // Thay bằng triển khai thực tế
}

void Statistics::SetBestSellingProduct(int newBestSellingProduct)
{
    bestSellingProductID = newBestSellingProduct  ;
}

int Statistics::GetNumberOfEmployees() const
{
    return numberEmployee;
}

void Statistics::SetNumberOfEmployees(int newNumberOfEmployees)
{
    numberEmployee = newNumberOfEmployees;
}

int Statistics::GetTotalPaymentsToEmployees() const
{
    return paymentsToEmployee;
}

void Statistics::SetTotalPaymentsToEmployees(int newTotalPaymentsToEmployees)
{
    paymentsToEmployee = newTotalPaymentsToEmployees;
}

// Xử lý nhân viên trước
void Statistics::DisplayCustomerStatistics() const
{

    std::cout << "Total Orders: " << totalOrders << std::endl;
    std::cout << "Total Amount Spent: $" << totalAmountSpent << std::endl;
    std::cout << "Average Quantity Per Order: " << avgQuantityPerOrder << std::endl;
    std::cout << "Average Amount Per Order: $" << avgAmountPerOrder << std::endl;
    std::cout << "Favourite Product ID: " << favouriteProductID << std::endl;
    std::cout << "Total Savings From Discounts: $" << savedMoneyDiscount << std::endl;

    std::cout << "Repeat Purchase Rate: " << repeatPurchaseRate << "%" << std::endl;
    std::cout << "Customer Lifetime Value: $" << customerLifetimeValue << std::endl;
    std::cout << "Average Discount Rate: " << avgDiscountRate << "%" << std::endl;
}
void Statistics::DisplaySuperMarketStatistics() const
{
    std::cout << "Supermarket Statistics " << std::endl ;
    // std::cout << "Statistics type : " << GetStatisticsType() << std::endl ;
    // std::cout << "Statistics date : " << GetStatisticsData() << std::endl; 
    std::cout << "Total revenue : $" << GetTotalRevenue() << std::endl ;
    std::cout << "Total profit :  $" << GetTotalProfit() << std::endl ;
    std::cout << "Total amount in :  $" << GetTotalAmountIn() << std::endl; 
    std::cout << "Total amount out :  $" << GetTotalAmountOut() << std::endl ;
    std::cout << "Import cost  : $" << getImportCost() << std::endl ;
    std::cout << "Number of customers: " << GetNumberOfCustomers() << std::endl;
    std::cout << "Total units sold: " << GetTotalUnitsSold() << std::endl;
    std::cout << "Number of sales invoices: " << GetNumberOfSalesInvoices() << std::endl;
    std::cout << "Best-selling product: " << GetBestSellingProduct() << std::endl;
    std::cout << "Number of employees: " << GetNumberOfEmployees() << std::endl;
    std::cout << "Total payments to employees:  $" << GetTotalPaymentsToEmployees() << std::endl;
}

