#include <bits/stdc++.h>
#include "Staff.h"

std::string Staff::get_IDStaff()
{
    return this->IDStaff;
}
std::string Staff::get_CICard() {
    return this->CICard;
}
std::string Staff::get_Address() {
    return this->Address;
}
std::string Staff::get_Email() {
    return this->Email;
}
float Staff::get_Wage() {
    return this->Wage;
}

std::string Staff::no_space(const std::string s) {
    std::string result = "";
    for (char c : s) {
        if (c != ' ') {
            result += tolower(c);
        }
    }
    return result;
}

void Staff::Add(std::vector<Staff> &Staff_Data) {
    std::string IDStaff, name, sdt, CICard, Address, Email;
    float Wage;
    int ngaysinh;

    do {
        std::cout << "Nhap ma nhan vien:";
        getchar();
        getline(std::cin, IDStaff);
    } while (CheckID(IDStaff, Staff_Data) == true);
    std::cout << "Nhap ho va ten:  ";
    getchar();
    getline(std::cin, name);
    std::cout << "Nhap so dien thoai:  ";
    getline(std::cin, sdt);
    std::cout << "Nhap nam sinh:  ";
    std::cin >> ngaysinh;
    std::cout << "Nhap so Can cuoc cong dan:  ";
    getchar();
    getline(std::cin, CICard);
    std::cout << "Nhap Dia Chi (Huyen va Tinh):  ";
    getline(std::cin, Address);
    std::cout << "Nhap Email:  ";
    getline(std::cin, Email);
    std::cout << "Nhap he so luong:  ";
    std::cin >> Wage;

    Staff staff(IDStaff, name, sdt, ngaysinh, CICard, Address, Email, Wage);

    Staff_Data.push_back(staff);

    std::ofstream file("Staff.txt", std::ios::app);

    if (!file) {
        std::cerr << "Không thể mở tệp Staff.txt để ghi dữ liệu." << std::endl;
        return;
    }

    file << staff.get_IDStaff() << "|"
        << staff.getName() << "|"
        << staff.getPhoneNumber() << "|"
        << staff.getYear_of_birthday() << "|"
        << staff.get_CICard() << "|"
        << staff.get_Address() << "|"
        << staff.get_Email() << "|"
        << staff.get_Wage() << std::endl;
    file.close();
    std::cout << "Nhan vien moi da duoc them vao tep." << std::endl;
}

void Staff::display() const
{
    std::cout << std::setiosflags(std::ios::left) << std::setw(10) << IDStaff;
    std::cout << std::setw(25) << Name;
    std::cout << std::setw(18) << PhoneNumber;
    std::cout << std::setw(14) << Year_of_birthday;
    std::cout << std::setw(15) << CICard;
    std::cout << std::setw(30) << Address;
    std::cout << std::setw(35) << Email;
    std::cout << std::setw(10) << Wage;
    std::cout << std::endl;
}

void Staff::displayAll(std::vector<Staff> Staff_Data) {
    std::cout << std::setiosflags(std::ios::left) << std::setw(10) << "ID_Staff";
    std::cout << std::setw(25) << "Ten nhan vien";
    std::cout << std::setw(18) << "So dien thoai";
    std::cout << std::setw(14) << "Nam sinh";
    std::cout << std::setw(15) << "Can cuoc cd";
    std::cout << std::setw(30) << "Dia chi";
    std::cout << std::setw(35) << "Email";
    std::cout << std::setw(10) << "He so luong";
    std::cout << std::endl << std::endl;

    for (int i = 0; i < Staff_Data.size(); i++) {
        Staff_Data[i].display();
        std::cout << std::endl;
    }
}

void Staff::search(std::vector<Staff> Staff_Data) {
    int choice;
    while (true) {
        std::cout << "\n\t====== Cac lua chon tim kiem: =======" << std::endl;
        std::cout << "\t=  <1>: Tim kiem theo TEN nhan vien =" << std::endl;
        std::cout << "\t=  <2>: Tim theo tien luong         =" << std::endl;
        std::cout << "\t=  <0>: Thoat.                      =" << std::endl;
        std::cout << "\t=====================================" << std::endl;

        std::cout << " Nhap lua chon cua ban: ";

        std::cin >> choice;

        std::string searching;
        float searching2;

        switch (choice) {
        case 1:
            std::cout << "\n\tNhap ten nhan vien can tim:";
            getchar();
            getline(std::cin, searching);
            search_name(searching, Staff_Data);
            break;
        case 2:
            std::cout << "\n\tNhap muc tien luong:";
            std::cin >> searching2;
            search_wage(searching2, Staff_Data);
            break;
        case 0:
            return;
        default:
            std::cout << "\n\tNhap sai vui long lua chon lai.\n";
        }

    }
}

void Staff::search_name(std::string abc, std::vector<Staff> Staff_Data) {
    int count = 0;
    for (int i = 0; i < Staff_Data.size(); i++) {
        if (no_space(abc) == no_space(Staff_Data[i].Name)) {
            Staff_Data[i].display();
            count++;
        }
    }
    if (count == 0) std::cout << "NOT FOUND THIS BOOK !!!" << std::endl;
}

void Staff::search_wage(float abc, std::vector<Staff> Staff_Data) {
    int count = 0;
    for (int i = 0; i < Staff_Data.size(); i++) {
        if (abc == Staff_Data[i].Wage) {
            Staff_Data[i].display();
            count++;
        }
    }
    if (count == 0) std::cout << "NOT FOUND THIS BOOK !!!" << std::endl;
}
