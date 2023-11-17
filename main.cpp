#include "Book.h"
#include "Date.h"
#include "Order.h"
#include "Prepare.h"
#include "Customer.h"
#include "Employee.h"
#include "Save.h"
#include "MyLib.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void Intro_start(), First_Menu(), Menu_Manager(), Menu_Staff(), setspace(), QuanlySach(), QuanlyNhanvien(), QuanlyKhachhang(), QuanlySach_Staff();
bool CheckLog(const string &filename, const string &username, const string &password);
int DangNhap(int choice);

int main()

{
    Intro_start();
    First_Menu();
    return 0;
}
// Setspace
void setspace(int n)
{
    while (n--)
        std::cout << " ";
}
// Intro
void Intro_start()
{
    cout << "\n\n\n\n";
    int n = 80;
    setspace(n - 5);
    for (int i = 0; i < 60; i++)
        std::cout << char(196);
    ;
    std::cout << std::endl;
    setspace(5 + n);
    std::cout << "Truong Dai hoc Bach Khoa - Dai hoc Da Nang" << std::endl;
    setspace(14 + n);
    std::cout << "Khoa Cong nghe thong tin" << std::endl;
    setspace(24 + n);
    std::cout << "*---*" << std::endl;
    setspace(11 + n);
    std::cout << "PBL2: Du an co so lap trinh" << std::endl;
    setspace(5 + n);
    std::cout << "De tai: Quan ly sach trong cua hang chuyen ve sach\n\n\n";
    setspace(n);
    std::cout << "Sinh vien thuc hien:";
    setspace(10);
    std::cout << "Giang vien huong dan:\n";
    setspace(n);
    std::cout << "-Phan Van Toan";
    setspace(16);
    std::cout << "-Nguyen Van Hieu\n";
    setspace(n);
    std::cout << "-Nguyen Le Nhat Tuan\n";
    setspace(n - 5);
    for (int i = 0; i < 60; i++)
        std::cout << char(196);
    ;
    getchar();
    system("cls");

    create_book_list();
    create_cus_list();
    create_emp_list();
    create_save_list();
}
// CheckLogin - kiem tra username & password
bool CheckLogin(const string &filename, const string &username, const string &password)
{
    ifstream file(filename);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            size_t pos = line.find(',');
            if (pos != string::npos)
            {
                string fileUsername = line.substr(0, pos);
                string filePassword = line.substr(pos + 1);
                if (fileUsername == username && filePassword == password)
                {
                    return true;
                }
            }
        }
        file.close();
    }
    return false;
}
// Giao dien luc LOGIN
int DangNhap(int choice)
{

    system("cls");

    string username, password;

    int x = 80, y = 5, w = 35, h = 2;
    SetColor(11);
    for (int i = x; i <= x + w; i++)
    {
        gotoXY(i, y);
        cout << char(196);
        gotoXY(i, y + h);
        cout << char(196);
        gotoXY(i, y + h + 2);
        cout << char(196);
        gotoXY(i, y + h + 4);
        cout << char(196);
    }
    for (int i = y; i <= y + h + 4; i++)
    {
        gotoXY(x, i);
        cout << char(179);
        gotoXY(x + w, i);
        cout << char(179);
    }
    gotoXY(x, y);
    cout << char(218);
    gotoXY(x + w, y);
    cout << char(191);
    gotoXY(x, y + h + 4);
    cout << char(192);
    gotoXY(x + w, y + h + 4);
    cout << char(217);
    gotoXY(x, y + h);
    cout << char(195);
    gotoXY(x + w, y + h);
    cout << char(180);
    gotoXY(x, y + h + 2);
    cout << char(195);
    gotoXY(x + w, y + h + 2);
    cout << char(180);

    gotoXY(x + 1, y + 1);
    cout << ("\t\t LOG IN");
    gotoXY(x + 1, y + 3);
    cout << (" Username: ");
    gotoXY(x + 1, y + 5);
    cout << (" Password: ");
    SetColor(15);
    gotoXY(80 + 13, 8);
    cin >> username;
    gotoXY(80 + 13, 10);
    cin >> password;

    bool loginSuccess = false;

    if (choice == 1)
    {
        loginSuccess = CheckLogin("Login_manager.txt", username, password);
    }
    else if (choice == 2)
    {
        loginSuccess = CheckLogin("Login_staff.txt", username, password);
    }

    if (loginSuccess)
    {
        gotoXY(80, 13);
        cout << "Logged in successfully" << endl;
        gotoXY(80, 15);
        system("pause");
        return 99;
    }
    else
    {
        gotoXY(80, 13);
        cout << "Login failed. Please try again." << endl;
        gotoXY(80, 15);
        system("pause");
        return -99;
    }
}
// First Menu - Dang nhap time;
void First_Menu()
{
    int choose, n = 3;
    string nd[n], nd1;
    nd1 = "\t\t       LOG IN";
    nd[0] = "  Quan ly";
    nd[1] = "  Nhan vien cua hang";
    nd[2] = "  Thoat";

    do
    {
        system("cls");
        box(80 - 2, 5 - 2, 35 + 4, 2 + 7, 11, 75, nd1);
        choose = Menu(80, 5, 35, 2, 11, 75, nd, n);
        gotoXY(80, 5);
        std::cout << char(195);
        gotoXY(115, 5);
        std::cout << char(180);
        system("cls");
        switch (choose)
        {
        case 0:
            if (DangNhap(1) == 99)
            {
                Menu_Manager();
            }
            break;
        case 1:
            if (DangNhap(2) == 99)
            {
                Menu_Staff();
            }
            break;
        case 2:
            break;
        }
    } while (n - choose - 1);
    thay_doi_tep_books();
    thay_doi_tep_customers();
    thay_doi_tep_employees();
    thay_doi_tep_save();
}
// Menu cua Manager
void Menu_Manager()
{
    int choose, n = 5;
    string nd[n];
    nd[0] = "Kho sach";
    nd[1] = "Danh sach Nhan Vien";
    nd[2] = "Danh sach Khach Hang";
    nd[3] = "Doanh thu va Lich su giao dich";
    nd[4] = "Thoat";

    do
    {
        system("cls");
        choose = Menu(80, 5, 35, 2, 11, 75, nd, n);
        system("cls");
        switch (choose)
        {
        case 0:
            QuanlySach();
            break;
        case 1:
            QuanlyNhanvien();
            break;
        case 2:
            QuanlyKhachhang();
            break;
        case 3:
            box(20, 0, 50, 2, 11, 75, "    DOANH THU VA LICH SU GIAO DICH");
            cout << "\n\n";
            SetColor(15);
            Save::display_All();
            system("pause");
            break;
        case 4:
            break;
        }
    } while (n - choose - 1);
}
// Quan ly sach
void QuanlySach()
{
    int choose, n = 6;
    string nd[n];
    nd[0] = "Hien thi tat ca sach";
    nd[1] = "Them sach";
    nd[2] = "Tim kiem sach";
    nd[3] = "Thay doi";
    nd[4] = "Xoa";
    nd[5] = "Quay lai";

    do
    {
        system("cls");
        choose = Menu(80, 5, 35, 2, 11, 75, nd, n);
        system("cls");
        switch (choose)
        {
        case 0:
            box(20, 0, 40, 2, 11, 75, "        THONG TIN SACH TRONG CUA HANG");
            cout << "\n\n";
            SetColor(15);
            Book::display_All();
            system("pause");
            break;
        case 1:
            Book::add_new_book();
            break;
        case 2:
            Book::search();
            break;
        case 3:
            Book::change();
            break;
        case 4:
            Book::delete_book();
            break;
        case 5:
            break;
        }
    } while (n - choose - 1);
}
// Quan ly Nhan vien
void QuanlyNhanvien()
{
    int choose, n = 6;
    string nd[n];
    nd[0] = "Hien thi tat ca nhan vien";
    nd[1] = "Them moi 1 nhan vien";
    nd[2] = "Tim kiem";
    nd[3] = "Thay doi thong tin nhan vien";
    nd[4] = "Xoa nhan vien";
    nd[5] = "Quay lai";

    do
    {
        system("cls");
        choose = Menu(80, 5, 35, 2, 11, 75, nd, n);
        system("cls");
        switch (choose)
        {
        case 0:
            box(20, 0, 50, 2, 11, 75, "     THONG TIN NHAN VIEN TRONG CUA HANG");
            cout << "\n\n";
            SetColor(15);
            employee::display_All();
            system("pause");
            break;
        case 1:
            employee::add_new_emp();
            break;
        case 2:
            employee::search();
            break;
        case 3:
            box(20, 0, 50, 2, 11, 75, "     Thay doi thong tin nhan vien");
            cout << "\n\n";
            SetColor(15);
            employee::change();
            break;
        case 4:
            box(20, 0, 50, 2, 11, 75, "     Xoa nhan vien");
            cout << "\n\n";
            SetColor(15);
            employee::delete_emp();
            break;
        case 5:
            break;
        }
    } while (n - choose - 1);
}
// Quan ly khach hang
void QuanlyKhachhang()
{
    int choose, n = 6;
    string nd[n];
    nd[0] = "Hien thi tat ca khach hang";
    nd[1] = "Dang ky khach hang";
    nd[2] = "Tim kiem khach hang";
    nd[3] = "Thay doi SDT khach hang";
    nd[4] = "Lich su giao dich";
    nd[5] = "Quay lai";

    do
    {
        system("cls");
        choose = Menu(80, 5, 35, 2, 11, 75, nd, n);
        system("cls");
        switch (choose)
        {
        case 0:
            box(20, 0, 50, 2, 11, 75, "     THONG TIN KHACH HANG TRONG CUA HANG");
            cout << "\n\n";
            SetColor(15);
            customer::display_All();
            system("pause");
            break;
        case 1:
            customer::add_new_cus();
            break;
        case 2:
            customer::search();
            break;
        case 3:
            box(70, 11, 50, 2, 11, 75, "     Thay doi thong tin Khach hang");
            cout << "\n\n";
            SetColor(15);
            customer::re_phone();
            system("pause");
            break;
        case 4:
            box(20, 0, 50, 2, 11, 75, "             Lich su giao dich");
            cout << "\n\n";
            SetColor(15);
            customer::order_history();
            system("pause");
            break;
        case 5:
            break;
        }
    } while (n - choose - 1);
}
// Menu_Staff
void Menu_Staff()
{
    int choose, n = 4;
    string nd[n];
    nd[0] = "Kho sach";
    nd[1] = "Danh sach Khach Hang";
    nd[2] = "Tao hoa don";
    nd[3] = "Thoat";

    do
    {
        system("cls");
        choose = Menu(80, 5, 35, 2, 11, 75, nd, n);
        system("cls");
        switch (choose)
        {
        case 0:
            QuanlySach_Staff();
            break;
        case 1:
            QuanlyKhachhang();
            break;
        case 2:
            box(20, 0, 50, 2, 11, 75, "     TAO HOA DON MOI");
            cout << "\n\n";
            SetColor(15);
            order::allthing();
            break;
        case 3:
            break;
        }
    } while (n - choose - 1);
}
// Quan ly sach - Danh rieng nhan vien
void QuanlySach_Staff()
{
    int choose, n = 3;
    string nd[n];
    nd[0] = "Hien thi tat ca sach";
    nd[1] = "Tim kiem sach";
    nd[2] = "Quay lai";

    do
    {
        system("cls");
        choose = Menu(80, 5, 35, 2, 11, 75, nd, n);
        system("cls");
        switch (choose)
        {
        case 0:
            box(20, 0, 40, 2, 11, 75, "    THONG TIN SACH TRONG CUA HANG");
            cout << "\n\n";
            SetColor(15);
            Book::display_All();
            system("pause");
            break;
        case 1:
            Book::search();
            break;
        case 2:
            break;
        }
    } while (n - choose - 1);
}
//