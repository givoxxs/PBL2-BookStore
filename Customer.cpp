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

customer &customer::add() {
    cout<<"Nhap vao ID: ";
    cin>>this->id;
    getchar();
    cout<<"Nhap vao ten: ";
    getline(cin,name);
    cout<<"Nhap vao so dien thoai: ";
    getline(cin,phone_number);
    cout<<"Nhap vao dia chi: ";
    getline(cin,address);
    
    return *this;
}

void customer::display()  {
    cout<<setw(5)<<id;
    cout<<setw(20)<<name;
    cout<<setw(20)<<phone_number;
    cout<<setw(50)<<address<<endl;
}

void customer::display_All(vector<customer> customers) {
    for(int i=0;i<customers.size();i++) {
        customers[i].display();
    }
}

void customer::re_address(vector<customer> &customers) {
    int thay_doi;
    cout<<"Nhap vao id can thay doi dia chi: ";
    cin>>thay_doi;
    getchar();
    cout<<"Nhap vao dia chi moi: ";
    for(int i=0;i<customers.size();i++) {
        if(customers[i].id == thay_doi) {
            getline(cin,customers[i].address);
            break;
        }
    }
    cout<<"Thay doi thanh cong!!!"<<endl;
}

void customer::re_phone(vector<customer> &customers) {
    int thay_doi;
    cout<<"Nhap vao id can thay doi so dien thoai: ";
    cin>>thay_doi;
    getchar();
    cout<<"Nhap vao so dien thoai moi: ";
    for(int i=0;i<customers.size();i++) {
        if(customers[i].id == thay_doi) {
            customers[i].re_phone_num();
            break;
        }
    }
    cout<<"Thay doi thanh cong!!!"<<endl;
}

