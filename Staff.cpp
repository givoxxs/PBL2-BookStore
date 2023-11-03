#include <bits/stdc++.h>
#include "Person.h"
#include "Staff.h"
#include "Ourlib.h"
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string.h>

using namespace std;

string Staff::get_IDStaff()
{
    return this->IDStaff;
}
string Staff::get_CICard() {
    return this->CICard;
}
string Staff::get_Address() {
    return this->Address;
}
string Staff::get_Email() {
    return this->Email;
}
float Staff::get_Wage() {
    return this->Wage;
}
// trans to lower
string Staff::no_space(const string s) {
    string result = "";
        for (char c : s) {
            if (c != ' ') {
                result += tolower(c);
            }
        }   
    return result;
}
// Them 1 nhan vien vao danh sach
void Staff::Add(vector<Staff> &Staff_Data) {

    string IDStaff, name, sdt, CICard, Address, Email;
    float Wage;
    int ngaysinh;

    do{
        cout << "Nhap ma nhan vien:";
        getchar();
        getline(cin, IDStaff);
    } while (CheckID(IDStaff, Staff_Data)==true);
    cout << "Nhap ho va ten:  ";
    getchar();
    getline(cin, name);
    cout << "Nhap so dien thoai:  ";
    getline(cin, sdt);
    cout << "Nhap nam sinh:  ";
    cin >> ngaysinh;
    cout << "Nhap so Can cuoc cong dan:  ";
    getchar();
    getline(cin, CICard);
    cout << "Nhap Dia Chi (Huyen va Tinh):  ";
    getline(cin, Address);
    cout << "Nhap Email:  ";
    getline(cin, Email);
    cout << "Nhap he so luong:  ";
    cin >> Wage;

    Staff staff(IDStaff, name, sdt, ngaysinh, CICard, Address, Email, Wage);

    Staff_Data.push_back(staff);

    ofstream file("Staff.txt", ios::app);

    if (!file) {
        cerr << "Không thể mở tệp Staff.txt để ghi dữ liệu." << endl;
        return ;
    }

    file << staff.get_IDStaff() << "|" 
         << staff.getName() << "|" 
         << staff.getPhoneNumber() << "|"
         << staff.getYear_of_birthday() << "|"
         << staff.get_CICard() << "|"
         << staff.get_Address() << "|"
         << staff.get_Email() << "|"
         << staff.get_Wage() << endl;
    file.close();
    cout << "Nhan vien moi da duoc them vao tep." << endl;
}
// Hien thi 1 nhan vien 
void Staff::display() const
{
    cout << setiosflags(ios::left) << setw(10) << IDStaff;
    cout << setw(25) << Name;
    cout << setw(18) << PhoneNumber;
    cout << setw(14) << Year_of_birthday;
    cout << setw(15) << CICard;
    cout << setw(30) << Address;
    cout << setw(35) << Email;
    cout << setw(10) << Wage;
    cout << endl;
}
void Staff::displayAll(vector<Staff> Staff_Data) {
    cout << setiosflags(ios::left) << setw(10) << "ID_Staff";
    cout << setw(25) << "Ten nhan vien";
    cout << setw(18) << "So dien thoai";
    cout << setw(14) << "Nam sinh";
    cout << setw(15) << "Can cuoc cd";
    cout << setw(30) << "Dia chi";
    cout << setw(35) << "Email";
    cout << setw(10) << "He so luong";
    cout << endl << endl;

    for(int i=0;i<Staff_Data.size();i++) {
        Staff_Data[i].display();
        cout<<endl;
    }
}
// Search Tổng
void Staff::search(vector<Staff> Staff_Data) {
    int choice;
        while (1) { 
            cout<<"\n\t====== Các lựa chọn tìm kiếm: ======="<<endl;
            cout<<"\t=  <1>: Tim kiem theo TEN nhan vien ="<<endl;
            cout<<"\t=  <2>: Tim theo tien luong         ="<<endl;
            cout<<"\t=  <0>: Thoat.                      ="<<endl;
            cout<<"\t====================================="<<endl;

            cout<<" Nhap lua chon cua ban: ";

            cin>>choice;
            string searching;
            float searching2;

            switch (choice) {
            case 1:
                cout << "\n\tNhap ten nhan vien can tim:";
                getchar();
                getline(cin, searching);
                search_name(searching, Staff_Data);
                break;
            case 2:
                cout << "\n\tNhap muc tien luong:";
                cin >> searching2;
                search_wage(searching2, Staff_Data);
                break;
            case 0:
                return ;
            default:
                cout << "\n\tNhap sai vui long lua chon lai.\n";
            }
        };
}
// Search theo TÊN
void Staff::search_name(string abc, vector<Staff> Staff_Data) {
    int count = 0;
    for(int i=0;i<Staff_Data.size();i++) {
        if(no_space(abc)==no_space(Staff_Data[i].Name)) {
            Staff_Data[i].display();
            count ++;
        }
    }
    if (count == 0) cout << "NOT FOUND THIS BOOK !!!" << endl;
}
// Search theo Tiền Lương
void Staff::search_wage(float abc, vector<Staff> Staff_Data) {
    int count = 0;
    for(int i=0;i<Staff_Data.size();i++) {
        if(abc == Staff_Data[i].Wage) {
            Staff_Data[i].display();
            count ++;
        }
    }
    if (count == 0) cout << "NOT FOUND THIS BOOK !!!" << endl;
}
