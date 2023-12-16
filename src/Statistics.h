#ifndef STATISTICS_CLASS_H
#define STATISTICS_CLASS_H
#include"Employee.h"
#include"Vector_Class.h"
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
    int numberCustomer; 
    int totalUnitsSold ;
    int bestSellingProductID ;
    int numberInvoice ;
    int numberEmployee ;
    int paymentsToEmployee ;
    Vector_Class<Employee> employeeSalaries;

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

    // Customer-related metrics
    int totalOrders;
    double totalAmountSpent;
    double repeatPurchaseRate;
    double customerLifetimeValue;
    double avgDiscountRate;

public:
    // Constructors
    Statistics(); // Constructor mặc định

    // Constructor cho Siêu thị
    Statistics(char* rType, char* tPeriod, char* rData,
               double tRevenue, double tExpenses, double tProfit,
               double tAmountIn, double tAmountOut,
               const Vector_Class<Employee>& empSalaries);

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
    void SetStatisticsType(char* newStatisticsType);

    char* GetTimePeriod() const;
    void SetTimePeriod(char* newTimePeriod);
    void SetNumberOfCustomers(int) ;
    int GetNumberOfCustomers() const;
    void SetTotalUnitsSold(int);
    int GetTotalUnitsSold()const ; 
    int GetNumberOfSalesInvoices()const; 
    void SetNumberOfSalesInvoices(int); 
    int GetBestSellingProduct() const;
    void SetBestSellingProduct(int);
    int GetNumberOfEmployees() const;
    void SetNumberOfEmployees(int);
    int GetTotalPaymentsToEmployees()const; 
    void SetTotalPaymentsToEmployees(int); 
    char* GetStatisticsData() const;
    void SetStatisticsData(char* newStatisticsData);

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

    // Getter và setter cho các metrics của Khách hàng
    int GetTotalOrders() const;
    double GetTotalAmountSpent() const;
    double GetRepeatPurchaseRate() const;
    double GetCustomerLifetimeValue() const;
    double GetAvgDiscountRate() const;

    void SetTotalOrders(int) ; 
    void SetTotalAmountSpent(double) ; 
    void SetRepeatPurchaseRate(double) ; 
    void SetCustomerLifetimeValue(double) ;
    void SetAvgDiscountRate(double) ;  

    // Phương thức hiển thị và tính toán lợi nhuận
    void DisplayCustomerStatistics() const;
    void DisplaySuperMarketStatistics() const;
};

#endif 
