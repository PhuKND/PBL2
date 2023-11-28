#include "Date.h"
#include <ctime>
#include <cstring>
#include <iostream>
#include<chrono>
#include<iomanip>
Date::Date() : day(1), month(1), year(2000) {
    updateRealTime();
}

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {
    updateRealTime();
}

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    this->day = day;
}
std::ostream& operator<<(std::ostream& os, const Date& dayObj) {
    os << std::setw(2) << std::setfill('0') << dayObj.day << "/"
       << std::setw(2) << std::setfill('0') << dayObj.month << "/"
       << std::setw(4) << std::setfill('0') << dayObj.year;
    return os;
}
std::istream& operator>>(std::istream& is, Date& dayObj) {
    char slash;  // Để đọc dấu '/'
    is >> dayObj.day >> slash >> dayObj.month >> slash >> dayObj.year;
    return is;
}
int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    this->month = month;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    this->year = year;
}

char* Date::getFormattedDate() const {
    // Assuming enough space is allocated for the formatted date
    char* formattedDate = new char[11];
    std::snprintf(formattedDate, 11, "%02d/%02d/%04d", day, month, year);
    return formattedDate;
}

void Date::updateRealTime() {
    auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm* timeInfo = localtime(&currentTime);

    // Set day, month, and year based on the current time
    day = timeInfo->tm_mday;
    month = timeInfo->tm_mon + 1; // tm_mon is 0-based
    year = timeInfo->tm_year + 1900; // tm_year is years since 1900
}

char* Date::getRealTime() const {
    auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    // Format time using custom strftime function
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&currentTime));
    
    // Allocate memory for the C-string
    char* realTimeStr = new char[20];
    std::strcpy(realTimeStr, buffer);

    return realTimeStr;
}
