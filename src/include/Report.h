class Report
{
private:
    char* reportType;  
    char* timePeriod; 
    char* reportData;

    double totalRevenue;   
    double totalExpenses;   
    double totalProfit;     
    double totalAmountIn;   
        double totalAmountOut; 

    Vector<double> employeeSalaries;

public:
    Report(/* args */);
    ~Report();

    char* GetReportType() const;
    void SetReportType(const char* &newReportType);

    char* GetTimePeriod() const;
    void SetTimePeriod(const char* &newTimePeriod);

    char* GetReportData() const;
    void SetReportData(const char* &newReportData);

    void DisplayReport() const;
    void CalculateProfit(int , int  , double) ;
};
