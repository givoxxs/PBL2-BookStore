#include "Customer.h"
#include "Prepare.h"
#include "MyLib.h"
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

void customer::set_point(int x)
{
    this->point = x;
}

customer customer::add()
{
    getchar();
    int max = customers.size() + 1;
    string temp = "KH" + to_string(max);
    this->id = temp;
    cout << "Nhap vao ten: ";
    getline(cin, name);
    cout << "Nhap vao so dien thoai: ";
    getline(cin, phone_number);
    cout << "Nhap nam sinh: ";
    cin >> year_of_birthday;
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
                  << newcus.get_point() << endl;
    inventoryFile.close();
    cout << "Khach hang da duoc them vao." << endl;
}

void customer::display()
{
    cout << setiosflags(ios::left) << setw(20) << id;
    cout << setw(30) << name;
    cout << setw(20) << phone_number;
    cout << setw(20) << year_of_birthday;
    cout << setw(20) << point << endl;
}

void customer::display_All()
{
    cout << setiosflags(ios::left) << setw(20) << "ID_CUS";
    cout << setw(30) << "Ho Ten";
    cout << setw(20) << "So Dien Thoai";
    cout << setw(20) << "Nam Sinh";
    cout << setw(20) << "Diem tich luy" << endl;
    for (int i = 0; i < customers.size(); i++)
    {
        customers[i].display();
    }
}

void customer::search_phone(string abc)
{
    if (abc == get_phone_num())
    {
        this->display();
    }
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
    case 2:
        cout << "Nhap vao SDT can tim: ";
        getline(cin, abc);
        for (int i = 0; i < customers.size(); i++)
        {
            customers[i].search_phone(abc);
        }
        break;
    default:
        cout << "Lua chon sai!!!";
        break;
    }
}

void customer::re_phone()
{
    bool success = false;
    getchar();
    string thay_doi;
    cout << "Nhap vao id can thay doi so dien thoai: ";
    getline(cin, thay_doi);

    
    for (int i = 0; i < customers.size(); i++)
    {
        if (no_space(customers[i].id) == no_space(thay_doi))
        {
            cout << "Nhap vao so dien thoai moi: ";
            customers[i].re_phone_num();
            success = true;
            break;
        }
    }
    if (success)
    {
        cout << "Thay doi thanh cong!!!" << endl;
    }
    else
    {
        cout << "Khong tim thay khach hang co ID tren" << endl;
    }
}

void customer::re_point()
{
    bool success = false;
    getchar();
    string thay_doi;
    int new_point;
    cout << "Nhap vao id can thay doi diem tich luy: ";
    getline(cin, thay_doi);

    for (int i = 0; i < customers.size(); i++)
    {
        if (no_space(customers[i].id) == no_space(thay_doi))
        {
            cout << "Nhap vao diem tich luy moi: ";
            cin >> new_point;
            customers[i].set_point(new_point);
            success = true;
            break;
        }
    }
    if (success)
    {
        cout << "Thay doi thanh cong!!!" << endl;
    }
    else
    {
        cout << "Khong tim thay khach hang co ID tren" << endl;
    }
}

void customer::change()
{
    int chon;
    string abc;
    cout << "1. Thay doi diem tich luy" << endl;
    cout << "2. Thay doi so dien thoai" << endl;
    cout << "Nhap lua chon cua ban: ";
    cin >> chon;
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