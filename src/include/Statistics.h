#pragma once
#include "Vector_Class.h"

class Statistics
{
private:
    // Siêu thị
    char* StatisticsType;
    char* timePeriod;
    char* StatisticsData;
    double totalRevenue;
    double totalExpenses;
    double totalProfit;
    double totalAmountIn;
    double totalAmountOut;
    Vector_Class<double> employeeSalaries;

    // Khách hàng
    int customerID;
    double paidAmount;
    int paidQuantity;
    double avgQuantityPerOrder;
    double avgAmountPerOrder;
    int favouriteProductID;
    double savedMoneyDiscount;

    // Nhân viên
    int employeeID;
    int numExecutedOrders;

public:
    // Constructors
    Statistics(); // Constructor mặc định

    // Constructor cho Siêu thị
    Statistics(const char* rType, const char* tPeriod, const char* rData,
           double tRevenue, double tExpenses, double tProfit,
           double tAmountIn, double tAmountOut,
           const Vector_Class<double>& empSalaries);

    // Constructor cho Khách hàng
    Statistics(int cID, double pAmount, int pQuantity,
           double avgQPerOrder, double avgAPerOrder,
           int favProductID, double savedMoneyDis);

    // Constructor cho Nhân viên
    Statistics(int eID, int numOrders);

    // Destructor
    ~Statistics();

    // Getter và setter cho Siêu thị
    char* GetStatisticsType() const;
    void SetStatisticsType(const char* newStatisticsType);

    char* GetTimePeriod() const;
    void SetTimePeriod(const char* newTimePeriod);

    char* GetStatisticsData() const;
    void SetStatisticsData(const char* newStatisticsData);

    double GetTotalRevenue() const;
    void SetTotalRevenue(double newTotalRevenue);

    double GetTotalExpenses() const;
    void SetTotalExpenses(double newTotalExpenses);

    double GetTotalProfit() const;
    void SetTotalProfit(double newTotalProfit);

    double GetTotalAmountIn() const;
    void SetTotalAmountIn(double newTotalAmountIn);

    double GetTotalAmountOut() const;
    void SetTotalAmountOut(double newTotalAmountOut);

    // Getter và setter cho Khách hàng
    int GetCustomerID() const;
    void SetCustomerID(int newCustomerID);

    double GetPaidAmount() const;
    void SetPaidAmount(double newPaidAmount);

    int GetPaidQuantity() const;
    void SetPaidQuantity(int newPaidQuantity);

    double GetAvgQuantityPerOrder() const;
    void SetAvgQuantityPerOrder(double newAvgQuantityPerOrder);

    double GetAvgAmountPerOrder() const;
    void SetAvgAmountPerOrder(double newAvgAmountPerOrder);

    int GetFavouriteProductID() const;
    void SetFavouriteProductID(int newFavouriteProductID);

    double GetSavedMoneyDiscount() const;
    void SetSavedMoneyDiscount(double newSavedMoneyDiscount);

    // Getter và setter cho Nhân viên
    int GetEmployeeID() const;
    void SetEmployeeID(int newEmployeeID);

    int GetNumExecutedOrders() const;
    void SetNumExecutedOrders(int newNumExecutedOrders);

    // Phương thức hiển thị và tính toán lợi nhuận
    void DisplayStatistics() const;
    void CalculateProfit(int param1, int param2, double param3);
};
