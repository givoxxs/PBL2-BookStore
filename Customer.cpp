#include "Customer.h"
#include "Prepare.h"
#include <vector>
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

customer::customer() {}

customer::customer(string id, string name, string phone_number, int year_of_birthday, int point) : person(id, name, phone_number, year_of_birthday)
{
    this->point = point;
}

customer::~customer() {}

int customer::get_point()
{
    return point;
}

void customer::set_point(int x) {
    this->point = x;
}

customer customer::add()
{
    getchar();
    int max =  customers.size()+1;
    string temp = "KH" + to_string(max);
    this->id = temp;
    cout << "Nhap vao ten: ";
    getline(cin, name);
    cout << "Nhap vao so dien thoai: ";
    getline(cin, phone_number);
    cout<<"Nhap nam sinh: ";
    cin>>year_of_birthday;
    this->point = 0;
    return *this;
}

void customer::add_new_cus()
{
    customer newcus;
    newcus.add();
    customers.push_back(newcus);

    ofstream inventoryFile("customers.txt", ios::app);

    if (!inventoryFile)
    {
        cerr << "Không thể mở tệp customers.txt để ghi dữ liệu." << endl;
        return;
    }
    inventoryFile << newcus.get_id() << ","
                  << newcus.get_name() << ","
                  << newcus.get_phone_num() << ","
                  << newcus.get_year_of_birthday() << ","
                  << newcus.get_point()<<endl;
    inventoryFile.close();
    cout << "Khach hang da duoc them vao." << endl;
}

void customer::display()
{
    cout << setw(5) << id;
    cout << setw(20) << name;
    cout << setw(20) << phone_number;
    cout << setw(10) << year_of_birthday;
    cout << setw(10) << point<<endl;
}

void customer::display_All()
{
    for (int i = 0; i < customers.size(); i++)
    {
        customers[i].display();
    }
}

void customer::re_phone()
{
    getchar();
    string thay_doi;
    cout << "Nhap vao id can thay doi so dien thoai: ";
    getline(cin,thay_doi);
    getchar();
    cout << "Nhap vao so dien thoai moi: ";
    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].id == thay_doi)
        {
            customers[i].re_phone_num();
            break;
        }
    }
    cout << "Thay doi thanh cong!!!" << endl;
}

void customer::search()
{
    int chon;
    string abc;
    cout << "1. Tim theo ten" << endl;
    cout << "2. Tim theo so dien thoai" << endl;
    cout << "Nhap lua chon cua ban: ";
    cin >> chon;
    getchar();
    switch (chon)
    {
    case 1:

        cout << "Nhap vao ten can tim: ";
        getline(cin, abc);
        for (int i = 0; i < customers.size(); i++)
        {
            customers[i].search_name(abc);
        }
        break;
    default:
        cout << "Lua chon sai!!!";
        break;
    }
}

void customer::change() {
    int chon = 0;
    string abc;
    cout << "1. Thay doi diem tich luy" << endl;
    cout << "2. Thay doi so dien thoai" << endl;
    cout << "Nhap lua chon cua ban: ";
    cin >> chon;
    getchar();
    
    switch (chon)
    {
    case 1:
        customer::re_point();
        break;
    case 2:
        customer::re_phone();
        break;
    default:
        cout << "Lua chon sai!!!";
        break;
    }

}

void customer::re_point() {
    getchar();
    string thay_doi;
    int new_point;
    cout << "Nhap vao id can thay doi diem tich luy: ";
    getline(cin,thay_doi);
    getchar();
    cout << "Nhap vao diem tich luy moi: ";
    cin>>new_point;
    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].id == thay_doi)
        {
            customers[i].set_point(new_point);
            break;
        }
    }
    cout << "Thay doi thanh cong!!!" << endl;
}