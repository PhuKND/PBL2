#include<iostream>
#ifndef DATE_H
#define DATE_H

class Date {
private:
    int day;
    int month;
    int year;
    
public:
    Date();
    Date(int day, int month, int year);

    // Getters and setters
    int getDay() const;
    void setDay(int day);
    int getMonth() const;
    void setMonth(int month);
    int getYear() const;
    void setYear(int year);
    friend std::ostream& operator<<(std::ostream& os, const Date& dayObj);
    // Function to display the date in a formatted way
    char* getFormattedDate() const;
friend std::istream& operator>>(std::istream& is, Date& dayObj);
    // Functions for real-time
    void updateRealTime();
    char* getRealTime() const;
};

#endif // DATE_H
