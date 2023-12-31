#include "Date.h"
#include<iostream>
#include<iomanip>
#include<time.h>
using namespace std;


Date:: Date() {}
Date::Date(int year, int month, int day, int hour, int minute, int second)
        : year(year), month(month), day(day), hour(hour), minute(minute), second(second) {
    }
Date::~Date() {}
tm Date::time_now() {
    time_t baygio = time(0);
    return *localtime(&baygio);
}



void Date::set_time() {
    tm today = time_now();
    this->second = today.tm_sec;
    this->minute = today.tm_min;
    this->hour = today.tm_hour;
    this->year = today.tm_year + 1900;
    this->month = today.tm_mon + 1;
    this->day = today.tm_mday;
}

void Date::display() {
    cout<<setw(89)<<left<<(to_string(this->hour) + ":" +to_string(this->minute) + ":" + to_string(this->second)
    + " -- " + to_string(this->day) + "/" + to_string(this->month) + "/" + to_string(this->year));
}

int Date::getSecond() {
    return this->second;
}

int Date::getMinute() {
    return this->minute;
}

int Date::getHour() {
    return this->hour;
}

int Date::getDay() {
        return this->day;
}

int Date::getMonth() {
    return this->month;
}

int Date::getYear() {
    return this->year;
}


