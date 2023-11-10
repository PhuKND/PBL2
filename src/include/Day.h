// Day.h
#ifndef DAY_H
#define DAY_H

#include <iostream>
#include <ctime>

class Day {
private:
    int day;
    int month;
    int year;

public:
    Day();
    Day(int day, int month, int year);

    int getDay() const;
    void setDay(int day);

    int getMonth() const;
    void setMonth(int month);

    int getYear() const;
    void setYear(int year);

    void display() const;
};

#endif
