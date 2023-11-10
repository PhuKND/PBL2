// Day.cpp
#include "Day.h"

Day::Day() : day(1), month(1), year(2000) {}

Day::Day(int day, int month, int year) : day(day), month(month), year(year) {}

int Day::getDay() const {
    return day;
}

void Day::setDay(int day) {
    this->day = day;
}

int Day::getMonth() const {
    return month;
}

void Day::setMonth(int month) {
    this->month = month;
}

int Day::getYear() const {
    return year;
}

void Day::setYear(int year) {
    this->year = year;
}

void Day::display() const {
    std::cout << day << "/" << month << "/" << year;
}
