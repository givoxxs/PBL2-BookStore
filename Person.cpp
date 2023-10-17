#include "Person.h"
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

person::person() {}
person::person(int id, string name, string phone_number):id(id),name(name),phone_number(phone_number) {}
person::~person() {}

int person::get_id() {
    return this->id;
}

person person::add() {
    cout<<"Them cac thong tin: "<<endl;
    cout<<"ID: ";
    cin>>this->id;
    cout<<"Ho ten: ";
    getchar();
    getline(cin,this->name);
    cout<<"So dien thoai: ";
    getline(cin,this->phone_number);

    return *this;
}

void person::display() const {
    cout<<setw(5)<<id;
    cout<<setw(20)<<name;
    cout<<setw(20)<<phone_number<<endl;
}

void person::search() {

}

person person::re_phone_number() {
    string new_phone_number;
    cout<<"Nhap so dien thoai moi: ";
    getline(cin,new_phone_number);
    this->phone_number = new_phone_number;
    return *this;
}
