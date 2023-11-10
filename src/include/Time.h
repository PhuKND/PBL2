// Time.h
#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <ctime>

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    Time();
    Time(int hour, int minute, int second);

    int getHour() const;
    void setHour(int hour);

    int getMinute() const;
    void setMinute(int minute);

    int getSecond() const;
    void setSecond(int second);

    void display() const;
};

#endif
