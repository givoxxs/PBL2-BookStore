#include "Customer.h"
#include<iostream>
#include<iomanip>
using namespace std;

customer::customer () {}
customer::customer(int id, string name, string phone_number, string address):person(id, name, phone_number) {
    this->address=address;
}
customer::~customer() {}

string customer::get_address() {
    return address;
}

customer customer::add() {
    cout<<"Them cac thong tin: "<<endl;
    cout<<"ID: ";
    cin>>this->id;
    cout<<"Ho ten: ";
    getchar();
    getline(cin,this->name);
    cout<<"So dien thoai: ";
    getline(cin,this->phone_number);
    cout<<"Dia chi: ";
    getline(cin,this->phone_number);

    return *this;
}

void customer::display() const {
    cout<<setw(5)<<id;
    cout<<setw(20)<<name;
    cout<<setw(20)<<phone_number;
    cout<<setw(50)<<address<<endl;
}

customer customer::re_address() {
    cout<<"Nhap dia chi moi: ";
    getline(cin,this->address);

    return *this;
}
