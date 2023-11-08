#include <windows.h>
#include "Employee.h"
#include "Prepare.h"
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

employee::employee() {}

employee::employee(string id, string name, string phone_number, int wage, string cic, string address, int yob) : person(id, name, phone_number, yob )
{
    this->CICard = cic;
    this->address=address;
    this->wage = wage;
}

employee::~employee() {}

string employee::get_CI() {
    return this->CICard;
}

string employee::getAddress() {
    return this->address;
}

float employee::get_wage()
{
    return wage;
}

void employee::set_wage(float wage) {
    this->wage = wage;
}

employee employee::add()
{
    
    int max =  employees.size()+1;
    string temp = "NV" + to_string(max);
    this->id = temp;
    cout << "Nhap vao ten: ";
    getline(cin, name);
    cout << "Nhap vao so dien thoai: ";
    getline(cin, phone_number);
    cout<<"Nhap nam sinh: ";
    cin>>year_of_birthday;
    cout << "Nhap so Can cuoc cong dan:  ";
    getchar();
    getline(cin,CICard);
    cout << "Nhap Dia Chi (Huyen va Tinh):  ";
    getline(cin, address);
    cout << "Nhap vao luong: ";
    cin>>wage;
    getchar();
    return *this;
}

void employee::add_new_emp()
{
    employee newemp;
    newemp.add();
    employees.push_back(newemp);

    ofstream inventoryFile("employees.txt", ios::app);

    if (!inventoryFile)
    {
        cerr << "Không thể mở tệp employees.txt để ghi dữ liệu." << endl;
        return;
    }
    inventoryFile << newemp.get_id() << ","
                  << newemp.get_name() << ","
                  << newemp.get_phone_num() << ","
                  << newemp.get_year_of_birthday() << ","
                  << newemp.get_CI() << ","
                  << newemp.getAddress() << ","
                  << newemp.get_wage() << ","<<endl;
    inventoryFile.close();
    cout << "Nhân viên đã được thêm vào tệp." << endl;
}

void employee::display()
{
    cout << setiosflags(ios::left) << setw(10) << id;
    cout << setw(30) << name;
    cout << setw(18) << phone_number;
    cout << setw(14) << year_of_birthday;
    cout << setw(20) << CICard;
    cout << setw(20) << address;
    cout << setw(20) << wage;
    cout << endl;
}

void employee::display_All()
{
    cout << setiosflags(ios::left) << setw(10) << "ID_Staff";
    cout << setw(30) << "Ten nhan vien";
    cout << setw(18) << "So dien thoai";
    cout << setw(14) << "Nam sinh";
    cout << setw(20) << "Can cuoc cong dan";
    cout << setw(20) << "Dia chi";
    cout << setw(20) << "Luong";
    cout << endl << endl;
    for (int i = 0; i < employees.size(); i++)
    {
        employees[i].display();
        cout<<endl;
    }
}

void employee::re_wage()
{
    string thay_doi;
    cout << "Nhap vao id can thay doi luong: ";
    getline(cin,thay_doi);
    cout << "Nhap vao luong moi: ";
    for (int i = 0; i < employees.size(); i++)
    {
        if (employees[i].get_id() == thay_doi)
        {
            float new_wage;
            cin>>new_wage;
            employees[i].set_wage(new_wage);
            break;
        }
    }
    cout << "Thay doi thanh cong!!!" << endl;
}

void employee::re_phone()
{
    string thay_doi;
    cout << "Nhap vao id can thay doi luong: ";
    getline(cin,thay_doi);
    cout << "Nhap vao so dien thoai moi: ";
    for (int i = 0; i < employees.size(); i++)
    {
        if (employees[i].get_id() == thay_doi)
        {
            employees[i].re_phone_num();
            break;
        }
    }
    cout << "Thay doi thanh cong!!!" << endl;
}

void employee::search()
{
    int chon;
    string abc1;
    float abc2;
    cout << "1. Tim theo ten" << endl;
    cout << "2. Tim theo luong" << endl;
    cout << "Nhap lua chon cua ban: ";
    cin >> chon;
    getchar();
    switch (chon)
    {
    case 1:

        cout << "Nhap vao ten can tim: ";
        getline(cin, abc1);
        for (int i = 0; i < employees.size(); i++)
        {
            employees[i].search_name(abc1);
        }
        break;
    case 2:
        cout << "Nhap vao luong can tim: ";
        cin>>abc2;
        for (int i = 0; i < employees.size(); i++)
        {
            employees[i].search_wage(abc2);
        }
        break;
    default:
        cout << "Lua chon sai!!!";
        break;
    }
}

void employee::change() {
    int chon;
    string abc;
    cout << "1. Thay doi luong" << endl;
    cout << "2. Thay doi so dien thoai" << endl;
    cout << "3. Thay doi so dien thoai" << endl;
    cout << "Nhap lua chon cua ban: ";
    cin >> chon;
    getchar();
    
    switch (chon)
    {
    case 1:

        employee::re_wage();
        break;
    case 2:
        employee::re_phone();
        break;
    case 3:
        employee::re_address();
        break;
    default:
        cout << "Lua chon sai!!!";
        break;
    }

}

void employee::search_wage(float abc)
{
    if (abc == get_wage())
    {
        this->display();
    }
}

void employee::re_address() {
    string thay_doi;
    cout << "Nhap vao id can thay doi dia chi: ";
    getline(cin,thay_doi);
    cout << "Nhap vao dia chi moi: ";
    for (int i = 0; i < employees.size(); i++)
    {
        if (employees[i].get_id() == thay_doi)
        {
            float new_address;
            cin>>new_address;
            employees[i].set_address(new_address);
            break;
        }
    }
    cout << "Thay doi thanh cong!!!" << endl;
}

void employee::set_address(float address) {
    this->address = address;
}
