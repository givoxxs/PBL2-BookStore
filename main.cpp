#include "Book.h"
#include "Staff.h"
#include "MyLib.h"
#include "MyMenu.h"
#include <iostream>
#include <vector>
#include <fstream>

std::vector<Staff> Staff_Data;
std::vector<Book> BookInventory;

void setspace(int n);
void Intro_start();
void lay_du_lieu();
void Readfile();
void Add_Book();
void QuanlyNhanvien();
void QuanlySach();
void Main_Menu();

int main() {
    Intro_start();
    lay_du_lieu();
    Readfile();

    Main_Menu();

    return 0;
}

void Main_Menu() {
    int choose, n = 4;
    string nd[n];
    nd[0] = "Kho sach";
    nd[1] = "Danh sach Nhan Vien";
    nd[2] = "Danh sach Khach Hang";
    nd[3] = "Thoat";

    do
    {
        system("cls");
        choose = Menu(80, 5, 35, 2, 11, 75, nd, n);
        system("cls");
        switch (choose)
        {
        case 0:
            std::cout << "\n\t\t*QUAN LY SACH TROG CUA HANG*\n";
            QuanlySach();
            break;
        case 1:
            std::cout << "\n\t\t*QUAN LY NHAN VIEN TROG CUA HANG*\n";
            QuanlyNhanvien();
            break;
        case 2:
            std::cout << "\n\t\t*QUAN LY KHACH HANG TROG CUA HANG*\n";
            // QuanlyKhachhang();
            break;
        case 3:
            //system("pause");
            break;
        }
    } while (n - choose - 1);
}


void QuanlySach() {

    int choose, n = 4;
    string nd[n];
    nd[0] = "Hien thi tat ca sach";
    nd[1] = "Them sach";
    nd[2] = "Tim kiem sach";
    nd[3] = "Quay lai";

    do {
            system("cls");
            choose = Menu(80, 5, 35, 2, 11, 75, nd, n);
            system("cls");
            switch (choose)
            {
            case 0:
                std::cout << "\n\t\t*THONG TIN SACH TRONG CUA HANG*\n";
                Book::display_All(BookInventory);
                system("pause");
                break;
            case 1:
                std::cout << "\n\t\t*THEM 1 SACH VAO KHO SACH*\n";
                Add_Book();
                system("pause");
                break;
            case 2:
                std::cout << "\n\t\t*TIM KIEM SACH TRONG KHO SACH*\n";
                Book::search(BookInventory);
                system("pause");
                break;
            case 3:
                //system("pause");
                break;
            }
        } while (n - choose - 1);
}

void QuanlyNhanvien() {
    int choose, n = 4;
    string nd[n];
    nd[0] = "Hien thi tat ca nhan vien";
    nd[1] = "Them moi 1 nhan vien";
    nd[2] = "Tim kiem";
    nd[3] = "Quay lai";

    do {
            system("cls");
            choose = Menu(80, 5, 35, 2, 11, 75, nd, n);
            system("cls");
            switch (choose)
            {
            case 0:
                std::cout << "\n\t\t*DANH SACH NHAN VIEN TRONG CUA HANG*\n";
                Staff::displayAll(Staff_Data);
                system("pause");
                break;
            case 1:
                std::cout << "\n\t\t*THEM 1 NHAN VIEN*\n";
                Staff::Add(Staff_Data);
                system("pause");
                break;
            case 2:
                std::cout << "\n\t\t*TIM KIEM*\n";
                Staff::search(Staff_Data);
                system("pause");
                break;
            case 3:
                //system("pause");
                break;
            }
        } while (n - choose - 1);
}

void setspace(int n) {
    while (n--)
        std::cout << " ";
}

void Intro_start() {
    int n = 20;
    setspace(n - 5);
    for (int i = 0; i < 60; i++)
        std::cout << char(196);;
    std::cout << std::endl;
    setspace(5 + n);
    std::cout << "Truong Dai hoc Bach Khoa - Dai hoc Da Nang" << std::endl;
    setspace(14 + n);
    std::cout << "Khoa Cong nghe thong tin" << std::endl;
    setspace(24 + n);
    std::cout << "*---*" << std::endl;
    setspace(11 + n);
    std::cout << "PBL2: Du an co so lap trinh" << std::endl;
    setspace(9 + n);
    std::cout << "De tai: Quan ly sach trong cua hang chuyen ve sach\n\n\n";
    setspace(n);
    std::cout << "Sinh vien thuc hien:";
    setspace(10);
    std::cout << "Giang vien huong dan:\n";
    setspace(n);
    std::cout << "-Phan Van Toan";
    setspace(12);
    std::cout << "-Nguyen Van Hieu\n";
    setspace(n);
    std::cout << "-Nguyen Le Nhat Tuan\n";
    setspace(n - 5);
    for (int i = 0; i < 60; i++)
        std::cout << char(196);;
    getchar();
    system("cls");
}

void lay_du_lieu() {
    std::ifstream inventoryFile("books.txt");
    if (!inventoryFile) {
        std::cerr << "Khong the mo tep InventoryBook.txt de doc du lieu." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inventoryFile, line)) {
        std::stringstream ss(line);
        std::string item;
        int id;
        std::string title, author, genre, publisher, bookShelves, language;
        int price, quantity, publishingYear;

        std::getline(ss, item, ',');
        std::stringstream(item) >> id;

        std::getline(ss, title, ',');
        std::getline(ss, author, ',');
        std::getline(ss, genre, ',');

        std::getline(ss, item, ',');
        std::stringstream(item) >> price;

        std::getline(ss, item, ',');
        std::stringstream(item) >> quantity;

        std::getline(ss, publisher, ',');
        std::getline(ss, item, ',');
        std::stringstream(item) >> publishingYear;

        std::getline(ss, bookShelves, ',');
        std::getline(ss, language, ',');

        Book book(id, title, author, genre, price, quantity, publisher, publishingYear, bookShelves, language);
        BookInventory.push_back(book);
    }

    inventoryFile.close();
}

void Readfile() {
    std::ifstream file("Staff.txt");
    if (!file) {
        std::cerr << "Khong the mo tep Staff.txt de doc du lieu." << std::endl;
        return;
    }

    std::string line, item;

    while (std::getline(file, line)) {
        std::stringstream ss(line);

        std::string IDStaff, name, sdt, CICard, Address, Email;
        float Wage;
        int ngaysinh;

        std::getline(ss, IDStaff, '|');
        std::getline(ss, name, '|');
        std::getline(ss, sdt, '|');

        std::getline(ss, item, '|');
        std::stringstream(item) >> ngaysinh;

        std::getline(ss, CICard, '|');
        std::getline(ss, Address, '|');
        std::getline(ss, Email, '|');

        std::getline(ss, item, '|');
        std::stringstream(item) >> Wage;

        Staff staff(IDStaff, name, sdt, ngaysinh, CICard, Address, Email, Wage);
        Staff_Data.push_back(staff);
    }

    file.close();
}

void Add_Book() {
    Book newBook;
    newBook.add();
    BookInventory.push_back(newBook);

    std::ofstream inventoryFile("books.txt", std::ios::app);

    if (!inventoryFile) {
        std::cerr << "Khong the mo tep InventoryBook.txt de ghi du lieu." << std::endl;
        return;
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
                 << newBook.get_language() << std::endl;

    inventoryFile.close();
    std::cout << "Sach moi da duoc them vao tep." << std::endl;
}
