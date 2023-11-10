// Time.cpp
#include "Time.h"

Time::Time() : hour(0), minute(0), second(0) {}

Time::Time(int hour, int minute, int second) : hour(hour), minute(minute), second(second) {}

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

int Time::getSecond() const {
    return second;
}

void Time::setSecond(int second) {
    this->second = second;
}

void Time::display() const {
    std::cout << hour << ":" << minute << ":" << second;
}
