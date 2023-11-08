#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<time.h>

class Date {
    private:
        int second;
        int minute;
        int hour;
        int day;
        int month;
        int year;
    public:
    Date();
    Date(int year, int month, int day, int hour, int minute, int second);
    ~Date();
    tm time_now();
    void set_time();
    void display();

    int getSecond();
    int getMinute();
    int getHour();
    int getDay();
    int getMonth();
    int getYear();
};
#endif