#include "Book.h"
// #include "MyMenu.h"
// #include "MyLib.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>

// Không cần sử dụng namespace std nữa

Book::Book() {}
Book::Book(int id, std::string title, std::string author, std::string genre, int price, int quantity,
           std::string publisher, int publishingYear, std::string bookShelves, std::string language)
    : id(id), title(title), author(author), genre(genre), price(price),
      quantity(quantity), publisher(publisher), publishingYear(publishingYear), bookShelves(bookShelves), language(language) {}

Book::~Book() {}

std::string Book::no_space(const std::string s) {
    std::string result = "";
    for (char c : s) {
        if (c != ' ') {
            result += tolower(c);
        }
    }
    return result;
}

void Book::search_title(std::string abc, std::vector<Book> BookInventory) {
    int count = 0;
    for (int i = 0; i < BookInventory.size(); i++) {
        if (no_space(abc) == no_space(BookInventory[i].title)) {
            BookInventory[i].display();
            count++;
        }
    }
    if (count == 0) std::cout << "NOT FOUND THIS BOOK !!!" << std::endl;
}

void Book::search_author(std::string abc, std::vector<Book> BookInventory) {
    int count = 0;
    for (int i = 0; i < BookInventory.size(); i++) {
        if (no_space(abc) == no_space(BookInventory[i].author)) {
            BookInventory[i].display();
            count++;
        }
    }
    if (count == 0) std::cout << "NOT FOUND THIS BOOK !!!" << std::endl;
}

void Book::search_genre(std::string abc, std::vector<Book> BookInventory) {
    int count = 0;
    for (int i = 0; i < BookInventory.size(); i++) {
        if (no_space(abc) == no_space(BookInventory[i].genre)) {
            BookInventory[i].display();
            count++;
        }
    }
    if (count == 0) std::cout << "NOT FOUND THIS BOOK !!!" << std::endl;
}

void Book::search_language(std::string abc, std::vector<Book> BookInventory) {
    int count = 0;
    for (int i = 0; i < BookInventory.size(); i++) {
        if (no_space(abc) == no_space(BookInventory[i].language)) {
            BookInventory[i].display();
            count++;
        }
    }
    if (count == 0) std::cout << "NOT FOUND THIS BOOK !!!" << std::endl;
}

Book &Book::add() {
    std::cout << "Nhap id: ";
    std::cin >> id;
    std::cout << "Nhap tieu de: ";
    std::cin.ignore();
    std::getline(std::cin, title);
    std::cout << "Nhap tac gia: ";
    std::getline(std::cin, author);
    std::cout << "Nhap the loai: ";
    std::getline(std::cin, genre);
    std::cout << "Nhap gia: ";
    std::cin >> price;
    std::cout << "Nhap so luong: ";
    std::cin >> quantity;
    std::cout << "Nhap nha xuat ban: ";
    std::cin.ignore();
    std::getline(std::cin, publisher);
    std::cout << "Nhap nam xuat ban: ";
    std::cin >> publishingYear;
    std::cin.ignore();
    std::cout << "Nhap ke sach: ";
    std::getline(std::cin, bookShelves);
    std::cout << "Nhap ngon ngu: ";
    std::getline(std::cin, language);

    return *this;
}

void Book::display() const {
    std::cout << std::setiosflags(std::ios::left) << std::setw(5) << id;
    std::cout << std::setw(40) << title;
    std::cout << std::setw(20) << author;
    std::cout << std::setw(25) << genre;
    std::cout << std::setw(10) << price;
    std::cout << std::setw(10) << quantity;
    std::cout << std::setw(20) << publisher;
    std::cout << std::setw(15) << publishingYear;
    std::cout << std::setw(15) << bookShelves;
    std::cout << std::setw(15) << language << std::endl;
}

Book &Book::increase(int a) {
    this->quantity += a;
    return *this;
}

Book &Book::decrease(int a) {
    this->quantity -= a;
    return *this;
}

void Book::search(std::vector<Book> BookInventory) {
    // int choose, n = 5;
    // std::string nd[n];
    // nd[0] = "Tim kiem theo TIEU DE";
    // nd[1] = "Tim kiem theo TAC GIA";
    // nd[2] = "Tim kiem theo THE LOAI";
    // nd[3] = "Tim kiem theo NGON NGU";
    // nd[4] = "Quay lai";
    
    // do {
    //     system("cls");
    //     choose = Menu(80, 5, 35, 2, 11, 75, nd, n);
    //     system("cls");
    //     std::string searching;
    //     switch (choose) {
    //         case 0:
    //             std::cout << "Nhap tac pham can tim: ";
    //             std::getline(std::cin, searching);
    //             search_title(searching, BookInventory);
    //         case 1:
    //             std::cout << "Nhap tac gia can tim: ";
    //             std::getline(std::cin, searching);
    //             search_author(searching, BookInventory);
    //             break;
    //         case 2:
    //             std::cout << "Nhap the loai can tim: ";
    //             std::getline(std::cin, searching);
    //             search_genre(searching, BookInventory);
    //             break;
    //         case 3:
    //             std::cout << "Nhap ngon ngu can tim: ";
    //             std::getline(std::cin, searching);
    //             search_language(searching, BookInventory);
    //             break; 
    //         case 4:
    //             break;
    //     }

    // } while (n - choose - 1);

    int choose;
    do {
        std::cout << "\n\t===== Cac lua chon tim kiem: =====" << std::endl;
        std::cout << "\t= <1>: Tim theo TIEU DE          ="<< std::endl;
        std::cout << "\t= <2>: Tim theo TAC GIA          =" << std::endl;
        std::cout << "\t= <3>: Tim theo THE LOAI         =" << std::endl;
        std::cout << "\t= <4>: Tim theo NGON NGU         =" << std::endl;
        std::cout << "\t= <0>: Quay lai!                 =" << std::endl;

        std::cout << "Nhap lua chon cua ban: ";
        std::cin >> choose;
        std::cin.ignore();

        std::string searching;

        switch (choose) {
        case 1:
            std::cout << "Nhap tac pham can tim: ";
            std::getline(std::cin, searching);
            search_title(searching, BookInventory);
            break;
        case 2:
            std::cout << "Nhap tac gia can tim: ";
            std::getline(std::cin, searching);
            search_author(searching, BookInventory);
            break;
        case 3:
            std::cout << "Nhap the loai can tim: ";
            std::getline(std::cin, searching);
            search_genre(searching, BookInventory);
            break;
        case 4:
            std::cout << "Nhap ngon ngu can tim: ";
            std::getline(std::cin, searching);
            search_language(searching, BookInventory);
            break;
        case 0:
            return ;
        default:
            std::cout << "\n\tNhap sai vui long lua chon lai.\n"; 
        }

    } while (true);

    
}

int Book::get_id() {
    return this->id;
}

std::string Book::get_title() {
    return this->title;
}

std::string Book::get_author() {
    return this->author;
}

std::string Book::get_genre() {
    return this->genre;
}

int Book::get_price() {
    return this->price;
}

int Book::get_quantity() {
    return this->quantity;
}

std::string Book::get_publisher() {
    return this->publisher;
}

int Book::get_publishingYear() {
    return this->publishingYear;
}

std::string Book::get_bookShelves() {
    return this->bookShelves;
}

std::string Book::get_language() {
    return this->language;
}

void Book::display_All(std::vector<Book> BookInventory) {
    std::cout << std::setiosflags(std::ios::left) << std::setw(5) << "ID";
    std::cout << std::setw(40) << "Title";
    std::cout << std::setw(20) << "Author";
    std::cout << std::setw(25) << "Genre";
    std::cout << std::setw(10) << "Price";
    std::cout << std::setw(10) << "Quantity";
    std::cout << std::setw(20) << "Publisher";
    std::cout << std::setw(15) << "PublishingYear";
    std::cout << std::setw(15) << "BookShelves";
    std::cout << std::setw(15) << "Language" << std::endl << std::endl;
    for (int i = 0; i < BookInventory.size(); i++) {
        BookInventory[i].display();
        std::cout << std::endl;
    }
}
