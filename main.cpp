#include "Book.h"
#include "Employee.h"
#include"Customer.h"
#include"Order.h"
// #include "MyLib.h"
#include<iostream>
#include<vector>
#include<string.h>
#include<iomanip>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

    vector<Book> BookInventory;

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
int main() {
    Intro_start();
    lay_du_lieu();
    int choice;
    while (1)
	{
		cout << "\t\t===========================================\n";
		cout << "\t\t  1. Hien thi tat ca sach.                 \n";
		cout << "\t\t  2. Them sach.                            \n";
		cout << "\t\t  3. Tim kiem sach.                        \n";
		cout << "\t\t  4. Quan ly.                              \n";
		cout << "\t\t  0. Thoat!                                \n";
		cout << "\t\t===========================================\n";
		cout << "\t\t   Nhap Lua Chon: ";
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
                cout << "Quan ly"; // Thêm mã lệnh quản lý ở đây
                break;
            case 0:
                return 0; // Thoát khỏi chương trình
            default:
                cout << "Nhap sai vui long lua chon lai.\n";
        }
        
        cout << "Press Enter to continue...";
        cin.ignore(); // Đọc ký tự xuống dòng sau lựa chọn
        cin.get();    // Đợi người dùng nhấn Enter để tiếp tục         
    }

    return 0;
}



