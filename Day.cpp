#include <bits/stdc++.h>
#include "Day.h"

using namespace std;
// Ham dựng
Day::Day(const Day &other) {
    day=other.day;
    month=other.month;
    year=other.year;
}

istream &operator>>(istream &in,Day &other)
{
    do {
        cout << "Nhap ngay:";
        in >> other.day;
        cout << "Nhap thang:";
        in >> other.month;
        cout << "Nhap nam:";
        in >> other.year;
    } while (!other.checkDay());
    return in;
}

ostream &operator<<(ostream &out,const Day &other)
{
    other.printfDay();
    return out;
}

Day Day::operator=(const Day &other)
{
    if(this!=&other) {
        this->day=other.day;
        this->month=other.month;
        this->year=other.year;
    }
    return *this;
}

int Day::getDay() const {
    return day;
}

int Day::getMonth() const {
    return month;
}

int Day::getYear() const {
    return year;
}

int Day::lastDay(int m,int y) {
    int a[]={31,29,31,30,31,30,31,31,30,31,30,31};
    if (y%4==0 && y%400!=0) a[2]=28;
    return a[m];
}

bool Day::checkDay()
{
    if (year>2023) return false;
    if (month<1 || month>12) return false;
    if (day<1 || day>lastDay(month,year)) return false;
    return true;
}

void Day::printfDay() const
{
    cout << right << setw(2) << day << "/" << right << setw(2) << month << "/" << left << setw(8) << year;
}

Day::~Day() {}

bool Day::operator<=(const Day &other)
{
    if (this->year>other.year) return false;
    if (this->year==other.year && this->month>other.month) return false;
    if (this->year==other.year && this->month==other.month && this->day>other.day) return false;
    return true;
}