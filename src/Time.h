#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <chrono>

class Time {
private:
    int day;
    int month;
    int year;
    int hour;
    int minute;
    std::chrono::system_clock::time_point realTime;

public:
    Time();
    Time(int day, int month, int year, int hour, int minute);
    Time(int day, int month, int year);
    Time(int hour, int minute);

    int getDay() const;
    void setDay(int day);
    int getMonth() const;
    void setMonth(int month);
    int getYear() const;
    void setYear(int year);
    int getHour() const;
    void setHour(int hour);
    int getMinute() const;
    void setMinute(int minute);
   int operator-(const Time& other) const ; 
    char* getFormattedTime() const;
    void updateRealTime();
    char* getRealTime() const;

    friend std::ostream& operator<<(std::ostream& os, const Time& timeObj);
    friend std::istream& operator>>(std::istream& is, Time& timeObj);
    
    bool operator<=(const Time& other) const;
    bool operator>=(const Time& other) const;
      bool operator<(const Time& other) const;
    bool operator>(const Time& other) const;
    bool operator==(const Time&) const;
};

#endif // TIME_H
