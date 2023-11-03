#include "Book.h"
#include "Staff.h"
#include"Order.h"
#include "Ourlib.h"
// #include "MyLib.h"
#include<iostream>
#include<vector>
#include<string.h>
#include<iomanip>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
// int pickMenu() {
//     char ch = _getch();
//     int output = ch - '0';
//     return output;
// }
vector<Staff> Staff_Data;
vector<Book> BookInventory;
void Title_display() {
    cout<<setiosflags(ios::left)<<setw(5)<<"ID";
    cout<<setw(40)<<"Title";
    cout<<setw(20)<<"Author";
    cout<<setw(25)<<"Genre";
    cout<<setw(10)<<"Price";
    cout<<setw(10)<<"Quantity";
    cout<<setw(20)<<"Publisher";
    cout<<setw(15)<<"PublishingYear";
    cout<<setw(15)<<"BookShelves";
    cout<<setw(15)<<"Language"<<endl<<endl;
}
void setspace(int n)
{
    while (n--)
        cout << " ";
}
void Intro_start()
{
    // SetColor(2);
    int n = 20;
    setspace(n - 5);
    for (int i = 0; i < 60; i++)
        cout << "=";
    cout << endl;
    setspace(5 + n);
    cout << "Truong Dai hoc Bach Khoa - Dai hoc Da Nang" << endl;
    setspace(14 + n);
    cout << "Khoa Cong nghe thong tin" << endl;
    setspace(24 + n);
    cout << "*---*" << endl;
    setspace(11 + n);
    cout << "PBL2: Du an co so lap trinh" << endl;
    setspace(9 + n);
    cout << "De tai:Quan ly sach trong cua hang chuyen ve sach\n\n\n";
    setspace(n);
    cout << "Sinh vien thuc hien:";
    setspace(10);
    cout << "Giang vien huong dan:\n";
    setspace(n);
    cout << "-Phan Van Toan";
    setspace(12);
    cout << "-Nguyen Van Hieu\n";
    setspace(n);
    cout << "-Nguyen Le Nhat Tuan\n";
    setspace(n - 5);
    for (int i = 0; i < 60; i++)
        cout << "=";
    // SetColor(7);
    getchar();
    cout << "\n\n";
}
void lay_du_lieu () {
    ifstream inventoryFile("books.txt");
    if (!inventoryFile) {
        cerr << "Không thể mở tệp InventoryBook.txt để đọc dữ liệu." << endl;
        return ;
    }

    string line;
    while (getline(inventoryFile, line)) {
        stringstream ss(line);
        string item;
        int id;
        string title, author, genre, publisher, bookShelves, language;
        int price, quantity, publishingYear;

        getline(ss, item, ',');
        stringstream(item) >> id;

        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, genre, ',');
        
        getline(ss, item, ',');
        stringstream(item) >> price;

        getline(ss, item, ',');
        stringstream(item) >> quantity;

        getline(ss, publisher, ',');
        getline(ss, item, ',');
        stringstream(item) >> publishingYear;

        getline(ss, bookShelves, ',');
        getline(ss, language, ',');

        Book book(id, title, author, genre, price, quantity, publisher, publishingYear, bookShelves, language);
        BookInventory.push_back(book);
    }

    inventoryFile.close();
}
void Readfile()
{

    ifstream file("Staff.txt");
    if (!file) {
        cerr << "Không thể mở tệp Staff.txt để đọc dữ liệu." << endl;
        return ;
    }

    string line,item;

    while (getline(file, line)) {
        stringstream ss(line);

        string IDStaff, name, sdt, CICard, Address, Email;
        float Wage;
        int ngaysinh;

        getline(ss,IDStaff,'|');

        getline(ss,name,'|');

        getline(ss,sdt,'|');

        getline(ss,item,'|');
        stringstream(item) >> ngaysinh;

        getline(ss,CICard,'|');

        getline(ss,Address,'|');

        getline(ss,Email,'|');

        getline(ss,item,'|');
        stringstream(item) >> Wage;

        Staff staff(IDStaff, name, sdt, ngaysinh, CICard, Address, Email, Wage);
        Staff_Data.push_back(staff);
        }  

        file.close();
}
void Add_Book() {
    Book newBook;
    newBook.add();
    BookInventory.push_back(newBook);

    ofstream inventoryFile("books.txt", ios::app);

    if (!inventoryFile) {
        cerr << "Không thể mở tệp InventoryBook.txt để ghi dữ liệu." << endl;
        return ;
    }
    inventoryFile << newBook.get_id() << ","
                 << newBook.get_title() << ","
                 << newBook.get_author() << ","
                 << newBook.get_genre() << ","
                 << newBook.get_price() << ","
                 << newBook.get_quantity() << ","
                 << newBook.get_publisher() << ","
                 << newBook.get_publishingYear() << ","
                 << newBook.get_bookShelves() << ","
                 << newBook.get_language() << endl;
    inventoryFile.close();
    cout << "Sách mới đã được thêm vào tệp." << endl;
}
void QuanlyNhanvien();
void QuanlySach();
int main() {
    Intro_start();
    lay_du_lieu();
    Readfile();
    
    int choice;
    // while (1)
	do {
		cout << "\t\t+------------ QUAN LY CUA HANG ------------+\n";
		cout << "\t\t+  1. Kho SACH                             +\n";
		cout << "\t\t+------------------------------------------+\n";
		cout << "\t\t+  2. Danh sach Nhan vien                  +\n";
        cout << "\t\t+------------------------------------------+\n";
		cout << "\t\t+  3. Danh sach Khach hang                 +\n";
        cout << "\t\t+------------------------------------------+\n";
        cout << "\t\t+  4. Lich su giao dich                    +\n";
        cout << "\t\t+------------------------------------------+\n";
		cout << "\t\t+  0. Thoat!                               +\n";
		cout << "\t\t+------------------------------------------+\n";
		cout << "\t\t   Nhap Lua Chon: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "\n\t\t*QUAN LY SACH TROG CUA HANG*\n"; 
                QuanlySach();
                break;
            case 2:
                cout << "\n\t\t*QUAN LY NHAN VIEN TROG CUA HANG*\n"; 
                QuanlyNhanvien();
                break;
            case 3:
                cout << "\n\t\t*QUAN LY KHACH HANG TROG CUA HANG*\n"; 
                //QuanlyKhachhang();
                break;
            case 4:
                cout << "\n\t\t*Giao dich cua CUA HANG SACH*\n"; 
                
                break;
            case 0:
                return 0; // Thoát khỏi chương trình
            default:
                cout << "Nhap sai vui long lua chon lai.\n";
        }
        
        cout << "Press Enter to continue...";
        cin.ignore(); // Đọc ký tự xuống dòng sau lựa chọn
        cin.get();    // Đợi người dùng nhấn Enter để tiếp tục         
    } while (1);

    return 0;
}
void QuanlySach() {
    int choice;
    while (1)
	{
        // system("cls");

		cout << "\t\t\t================= SACH ====================\n";
		cout << "\t\t\t  1. Hien thi tat ca sach.                 \n";
		cout << "\t\t\t  2. Them sach.                            \n";
		cout << "\t\t\t  3. Tim kiem sach.                        \n";
		cout << "\t\t\t  4. Xoa 1 quyen sach.                     \n";
		cout << "\t\t\t  0. Thoat!                                \n";
		cout << "\t\t\t===========================================\n";
		cout << "\t\t\t   Nhap Lua Chon: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "\n\t\t*THONG TIN SACH TRONG CUA HANG*\n";
                Book::display_All(BookInventory);
                break;
            case 2:
                cout << "\n\t\t*THEM 1 SACH VAO KHO SACH*\n";
                Add_Book();
                break;
            case 3:
                cout << "\n\t\t*TIM KIEM SACH TRONG KHO SACH*\n";
                Book::search(BookInventory);
                break;
            case 4:
                cout << "\n\t\t*XOA 1 quyen sach*\n"; 
                
                break;
            case 0:
                return ; // Thoát khỏi chương trình
            default:
                cout << "Nhap sai vui long lua chon lai.\n";
        }
        
        cout << "Press Enter to continue...";
        cin.ignore(); // Đọc ký tự xuống dòng sau lựa chọn
        cin.get();    // Đợi người dùng nhấn Enter để tiếp tục         
    }

}
// QUAN LY NHAN VIEN
void QuanlyNhanvien() {
    int choice;
    while (1) {
        // system("cls");

        cout << "\t\t\t===============  NHAN VIEN ================\n";
		cout << "\t\t\t  1. Hien thi tat ca nhan vien.            \n";
		cout << "\t\t\t  2. Them moi 1 nhan vien.                 \n";
		cout << "\t\t\t  3. Tim kiem.                             \n";
		cout << "\t\t\t  4. hello world.                          \n";
		cout << "\t\t\t  0. Thoat!                                \n";
		cout << "\t\t\t===========================================\n";
		cout << "\t\t\t   Nhap Lua Chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\n\t\t*DANH SACH NHAN VIEN TRONG CUA HANG*\n";
                Staff::displayAll(Staff_Data);
                break;
            case 2:
                cout << "\n\t\t*THEM 1 NHAN VIEN*\n";
                Staff::Add(Staff_Data);
                break;
            case 3:
                cout << "\n\t\t*TIM KIEM*\n";
                Staff::search(Staff_Data);
                break;
            case 4:
                cout << "\n\t\t*HELLO WORLD*\n"; 
                break;
            case 0:
                return ; // Thoát khỏi chương trình
            default:
                cout << "\n\t\tNhap sai vui long lua chon lai.\n";
        }
            
            cout << "Press Enter to continue...";
            cin.ignore(); // Đọc ký tự xuống dòng sau lựa chọn
            cin.get();    // Đợi người dùng nhấn Enter để tiếp tục         
    }
}



