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
void FirstMenu();
int DangNhap(int x);
bool CheckLog(const string& filename, const string& username, const string& password);

int main() {
    Intro_start();
    lay_du_lieu();
    Readfile();

    FirstMenu();

    //Main_Menu();

    return 0;
}
// Giao diện lúc mới vào ứng dụng quản lý
void FirstMenu() {
    int choose, n=3;
    string nd[n], nd1;
    nd1 = "         Dang nhap";
    nd[0] = "  Quan ly";
    nd[1] = "  Nhan vien";
    nd[2] = "  Thoat";
    box(80, 3, 35, 2, 11, 75, nd1);
    //cout << endl;
    
    do {
        system("cls");
        box(80, 3, 35, 2, 11, 75, nd1);
        choose = Menu(80, 5, 35, 2, 11, 75, nd, n);
        gotoXY(80,5); std::cout << char(195);
        gotoXY(115,5); std::cout << char(180);
        system("cls");
        switch(choose) {
            case 0:
                if (DangNhap(1) == 99) {
                    // std::cout << "Nguoi quan ly dang su dung";               
                    Main_Menu();
                }
                break;
            case 1:
                if (DangNhap(2) == 99) {
                    Main_Menu();
                }
                gotoXY(80, 19);
                system("pause");
                break;
            case 2:
                break;
        }                
    } while (n -  choose - 1);
}
// kiểm tra đăng nhập
bool CheckLogin(const string& filename, const string& username, const string& password) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t pos = line.find(',');
            if (pos != string::npos) {
                string fileUsername = line.substr(0, pos);
                string filePassword = line.substr(pos + 1);
                if (fileUsername == username && filePassword == password) {
                    return true;
                }
            }
        }
        file.close();
    }
    return false;
}
// Giao diện đăng nhập
int DangNhap(int choice) {

    system("cls");

    string username, password;
    gotoXY(80, 5);
    std::cout << "+---------------------------------+\n";
    gotoXY(80, 6);
    std::cout << "|              LOG IN             |\n";  
    gotoXY(80, 7);
    std::cout << "+---------------------------------+\n"; 
    gotoXY(80, 8);
    std::cout << "| Username:                       |\n";
    gotoXY(80, 9);
    std::cout << "+---------------------------------+\n"; 
    gotoXY(80, 10);  
    std::cout << "| Password:                       |\n";
    gotoXY(80, 11);
    std::cout << "+---------------------------------+\n"; 

    gotoXY(80 + 13, 8);
    cin >> username;
    gotoXY(80 + 13, 10);
    cin >> password;

    bool loginSuccess = false;
    
    if (choice == 1) {
        loginSuccess = CheckLogin("Login_manager.txt", username, password);
    } else if (choice == 2) {
        loginSuccess = CheckLogin("Login_staff.txt", username, password);
    }
    
    if (loginSuccess) {
        gotoXY(80, 13);
        cout << "Logged in successfully" << endl;
        gotoXY(80, 15);
        system("pause");
        return 99;
    } else {
        gotoXY(80, 13);
        cout << "Login failed. Please try again." << endl;
        gotoXY(80, 15);
        system("pause");
        return -99;
    }
}
// Menu quản lý của Người quản lý
void Main_Menu() {
    int choose, n = 5;
    string nd[n];
    nd[0] = "Kho sach";
    nd[1] = "Danh sach Nhan Vien";
    nd[2] = "Danh sach Khach Hang";
    nd[3] = "Doanh thu va thong ke";
    nd[4] = "Thoat";

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
            std::cout << "\n\t\t*DOANH THU VA THONGH KE*\n";
            // Doanhthu();
            break;
        case 4:
            //system("pause");
            break;
        }
    } while (n - choose - 1);
}
// Giao diện quản lý sách  - MANAGER
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
// Giao diện quản lý nhân viên - Manager
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
// Loại bỏ so sánh khi dấu hoa vs k hoa
void setspace(int n) {
    while (n--)
        std::cout << " ";
}
// Intro start
void Intro_start() {
    cout << "\n\n\n\n";
    int n = 80;
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
// Lay dữ liệu cho Book Inventory
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
// Lay dữ liệu cho Mục nhân viên
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
// Thêm 1 quyển sách vào Kho - Book Inventory
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
