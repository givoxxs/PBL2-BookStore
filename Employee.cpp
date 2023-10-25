#include "Employee.h"
#include<iostream>
#include<iomanip>
using namespace std;

employee::employee () {}
employee::employee(int id, string name, string phone_number, int salary):person(id, name, phone_number) {
    this->salary=salary;
}
employee::~employee() {}

int employee::get_salary() {
    return salary;
}

employee employee::add() {
    cout<<"Them cac thong tin: "<<endl;
    cout<<"ID: ";
    cin>>this->id;
    cout<<"Ho ten: ";
    getchar();
    getline(cin,this->name);
    cout<<"So dien thoai: ";
    getline(cin,this->phone_number);
    cout<<"Luong: ";
    cin>>salary;

    return *this;
}

void employee::display() const {
    cout<<setw(5)<<id;
    cout<<setw(20)<<name;
    cout<<setw(20)<<phone_number;
    cout<<setw(15)<<salary<<endl;
}

employee employee::re_salary() {
    cout<<"Nhap tien luong moi: ";
    cin>>this->salary;
    return *this;
}
