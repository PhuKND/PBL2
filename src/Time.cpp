#include"Time.h"
#include <iomanip>
#include <sstream>
#include <cstring>

Time::Time() : hour(0), minute(0) {
    updateRealTime();
}

Time::Time(int hour, int minute) : hour(hour), minute(minute) {
    // updateRealTime();
}

int Time::getHour() const {
    return hour;
}

void Time::setHour(int hour) {
    this->hour = hour;
}

int Time::getMinute() const {
    return minute;
}

void Time::setMinute(int minute) {
    this->minute = minute;
}

char* Time::getFormattedTime() const {
    char* formattedTime = new char[6];
    std::snprintf(formattedTime, 6, "%02d:%02d", hour, minute);
    return formattedTime;
}

void Time::updateRealTime() {
    realTime = std::chrono::system_clock::now();
    auto timeT = std::chrono::system_clock::to_time_t(realTime);
    auto timeStruct = std::localtime(&timeT);
    hour = timeStruct->tm_hour;
    minute = timeStruct->tm_min;
}


char* Time::getRealTime() const {
    auto currentTime = std::chrono::system_clock::to_time_t(realTime);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&currentTime), "%Y-%m-%d %H:%M:%S");
    std::string timeStr = ss.str();
    char* realTimeStr = new char[timeStr.length() + 1];
    std::strcpy(realTimeStr, timeStr.c_str());
    return realTimeStr;
}

std::ostream& operator<<(std::ostream& os, const Time& timeObj) {
    os << std::setw(2) << std::setfill('0') << timeObj.hour << ":"
       << std::setw(2) << std::setfill('0') << timeObj.minute
       << std::setfill(' ') ; 
    return os;
}

std::istream& operator>>(std::istream& is, Time& timeObj) {
    char colon;  
    is >> timeObj.hour >> colon >> timeObj.minute;
    timeObj.updateRealTime();
    return is;
}
bool Time::operator==(const Time& other) const {
    return (hour == other.hour) && (minute == other.minute);
}
// Inside Time class

bool Time::operator>=(const Time& other) const {
    if (hour > other.hour) {
        return true;
    } else if (hour == other.hour) {
        return minute >= other.minute;
    } else {
        return false;
    }
}

bool Time::operator<=(const Time& other) const {
    if (hour < other.hour) {
        return true;
    } else if (hour == other.hour) {
        return minute <= other.minute;
    } else {
        return false;
    }
}
