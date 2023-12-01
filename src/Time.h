#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <chrono>

class Time {
private:
    int hour;
    int minute;
    std::chrono::system_clock::time_point realTime;

public:
    Time();
    Time(int hour, int minute);

    int getHour() const;
    void setHour(int hour);
    int getMinute() const;
    void setMinute(int minute);

    char* getFormattedTime() const;
    void updateRealTime();
    char* getRealTime() const;

    friend std::ostream& operator<<(std::ostream& os, const Time& timeObj);
    friend std::istream& operator>>(std::istream& is, Time& timeObj);
    bool operator==(const Time&)const; 
};

#endif // TIME_H
