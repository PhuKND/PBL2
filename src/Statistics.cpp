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
Statistics::Statistics(char* rType,  char* tPeriod,  char* rData,
               double tRevenue, double tExpenses, double tProfit,
               double tAmountIn, double tAmountOut,
               const Vector_Class<Employee>& empSalaries)
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
    : customerID(cID), paidAmount(pAmount), paidQuantity(pQuantity),
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
char* Statistics::GetStatisticsType() const {
    return StatisticsType;
}

void Statistics::SetStatisticsType( char* newStatisticsType) {
    this -> StatisticsType = newStatisticsType ;
}

char* Statistics::GetTimePeriod() const {
    return timePeriod;
}

void Statistics::SetTimePeriod( char* newTimePeriod) {
    this -> timePeriod = newTimePeriod ;
}
char* Statistics::GetStatisticsData() const {
    return StatisticsData;
}
void Statistics::SetStatisticsData( char* newStatisticsData) {
    this -> StatisticsData = newStatisticsData; 
}
double Statistics::GetTotalRevenue() const {
    return totalRevenue;
}
void Statistics::SetTotalRevenue(double newTotalRevenue) {
    this -> totalRevenue = newTotalRevenue ;
}
double Statistics::GetTotalExpenses() const {
    return totalExpenses;
}
void Statistics::SetTotalExpenses(double newTotalExpenses) {
    this -> totalExpenses = newTotalExpenses ; 
}
double Statistics::GetTotalProfit() const {
    return totalProfit;
}
void Statistics::SetTotalProfit(double newTotalProfit) {
    this -> totalProfit = newTotalProfit ; 
}
double Statistics::GetTotalAmountIn() const {
    return totalAmountIn;
}
void Statistics::SetTotalAmountIn(double newTotalAmountIn) {
    this -> totalAmountIn = newTotalAmountIn ; 
}
double Statistics::GetTotalAmountOut() const {
    return totalAmountOut;
}
void Statistics::SetTotalAmountOut(double newTotalAmountOut) {
    this -> totalAmountOut = newTotalAmountOut ;
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

// Add implementations for new setters

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
    newAvgDiscountRate = newAvgDiscountRate;
}
// Xử lý nhân viên trước
void Statistics::DisplayStatistics() const
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

// Profit supermarket 
void Statistics::CalculateProfit(int param1, int param2, double param3){

}
