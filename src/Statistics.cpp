#include "include/Statistics.h"

// Constructor mặc định
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
Statistics::Statistics(const char* rType, const char* tPeriod, const char* rData,
               double tRevenue, double tExpenses, double tProfit,
               double tAmountIn, double tAmountOut,
               const Vector_Class<double>& empSalaries)
    : StatisticsType(nullptr), timePeriod(nullptr), StatisticsData(nullptr),
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
Statistics::Statistics(int cID, double pAmount, int pQuantity,
               double avgQPerOrder, double avgAPerOrder,
               int favProductID, double savedMoneyDis)
    : StatisticsType(nullptr), timePeriod(nullptr), StatisticsData(nullptr),
      totalRevenue(0.0), totalExpenses(0.0), totalProfit(0.0),
      totalAmountIn(0.0), totalAmountOut(0.0), employeeSalaries(),
      customerID(cID), paidAmount(pAmount), paidQuantity(pQuantity),
      avgQuantityPerOrder(avgQPerOrder), avgAmountPerOrder(avgAPerOrder),
      favouriteProductID(favProductID), savedMoneyDiscount(savedMoneyDis),
      employeeID(0), numExecutedOrders(0)
{
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
char* Statistics::GetStatisticsType() const {
    return StatisticsType;
}

void Statistics::SetStatisticsType(const char* newStatisticsType) {
    // Implement the logic to set the new value
}

char* Statistics::GetTimePeriod() const {
    return timePeriod;
}

void Statistics::SetTimePeriod(const char* newTimePeriod) {
    // Implement the logic to set the new value
}
char* Statistics::GetStatisticsData() const {
    return StatisticsData;
}
void Statistics::SetStatisticsData(const char* newStatisticsData) {
    // Implement the logic to set the new value
}
double Statistics::GetTotalRevenue() const {
    return totalRevenue;
}
void Statistics::SetTotalRevenue(double newTotalRevenue) {
    // Implement the logic to set the new value
}
double Statistics::GetTotalExpenses() const {
    return totalExpenses;
}
void Statistics::SetTotalExpenses(double newTotalExpenses) {
    // Implement the logic to set the new value
}
double Statistics::GetTotalProfit() const {
    return totalProfit;
}
void Statistics::SetTotalProfit(double newTotalProfit) {
    // Implement the logic to set the new value
}
double Statistics::GetTotalAmountIn() const {
    return totalAmountIn;
}
void Statistics::SetTotalAmountIn(double newTotalAmountIn) {
    // Implement the logic to set the new value
}
double Statistics::GetTotalAmountOut() const {
    return totalAmountOut;
}
void Statistics::SetTotalAmountOut(double newTotalAmountOut) {
    // Implement the logic to set the new value
}
// Getter and setter methods for Khách hàng
int Statistics::GetCustomerID() const {
    return customerID;
}

void Statistics::SetCustomerID(int newCustomerID) {
    customerID = newCustomerID;
}

double Statistics::GetPaidAmount() const {
    return paidAmount;
}

void Statistics::SetPaidAmount(double newPaidAmount) {
    paidAmount = newPaidAmount;
}

int Statistics::GetPaidQuantity() const {
    return paidQuantity;
}

void Statistics::SetPaidQuantity(int newPaidQuantity) {
    paidQuantity = newPaidQuantity;
}

double Statistics::GetAvgQuantityPerOrder() const {
    return avgQuantityPerOrder;
}

void Statistics::SetAvgQuantityPerOrder(double newAvgQuantityPerOrder) {
    avgQuantityPerOrder = newAvgQuantityPerOrder;
}

double Statistics::GetAvgAmountPerOrder() const {
    return avgAmountPerOrder;
}

void Statistics::SetAvgAmountPerOrder(double newAvgAmountPerOrder) {
    avgAmountPerOrder = newAvgAmountPerOrder;
}

int Statistics::GetFavouriteProductID() const {
    return favouriteProductID;
}

void Statistics::SetFavouriteProductID(int newFavouriteProductID) {
    favouriteProductID = newFavouriteProductID;
}

double Statistics::GetSavedMoneyDiscount() const {
    return savedMoneyDiscount;
}

void Statistics::SetSavedMoneyDiscount(double newSavedMoneyDiscount) {
    savedMoneyDiscount = newSavedMoneyDiscount;
}

// Getter and setter methods for Nhân viên
int Statistics::GetEmployeeID() const {
    return employeeID;
}

void Statistics::SetEmployeeID(int newEmployeeID) {
    employeeID = newEmployeeID;
}

int Statistics::GetNumExecutedOrders() const {
    return numExecutedOrders;
}

void Statistics::SetNumExecutedOrders(int newNumExecutedOrders) {
    numExecutedOrders = newNumExecutedOrders;
}
