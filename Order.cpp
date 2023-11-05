#include "Order.h"
#include "Book.h"
#include <iostream>
#include <vector>

order::order() {}
order::order(int so_loai, std::vector<int> a, std::vector<int> b, std::vector<Book> books, int pay_money) {
    this->so_loai = so_loai;
    this->book_id = a;
    this->book_quantity = b;
    this->books = books;
    this->pay_money = pay_money;
}
order::~order() {}

int order::get_price(int a) {
    for (int i = 0; i < books.size(); i++) {
        if (a == books[i].get_id()) {
            return books[i].get_price();
        }
    }
    return -1;
}

int order::sum_total() {
    int sum = 0;
    for (int i = 0; i < so_loai; i++) {
        sum += get_price(book_id[i]) * book_quantity[i];
    }
    return sum;
}

void order::pay() {
    std::cin >> this->pay_money;
    change();
}

void order::change() {
    this->change_money = this->pay_money - sum_total();
}

order order::create(std::vector<Book> books) {
    this->books = books;
    std::cout << "Nhap vao tong loai sach: ";
    std::cin >> this->so_loai;
    std::cout << "Nhap vao id cua sach va so luong tuong ung: " << std::endl;
    for (int i = 0; i < so_loai; i++) {
        int a, b;
        std::cout << "ID quyen sach thu " << i + 1 << ": ";
        std::cin >> a;
        std::cout << "So luong: ";
        std::cin >> b;
        book_id.push_back(a);
        book_quantity.push_back(b);
    }

    return *this;
}

void order::choose() {
    int chosen;
    std::cout << "Tong tien la: " << sum_total() << std::endl;
    do {
        std::cout << "Ban muon: " << std::endl;
        std::cout << "1. Tinh tien" << std::endl << "2. Thay doi don hang" << std::endl;
        std::cin >> chosen;

        switch (chosen) {
            case 1:
                std::cout << "Tien nhan cua khach: ";
                pay();
                break;
            case 2:
                remove();
                std::cout << "Tong tien con lai: " << sum_total() << std::endl;
                break;
            default:
                std::cout << "Lua chon sai. Vui long nhap lai." << std::endl;
        }
    } while (chosen != 1);
}

order order::remove() {
    int dlt_id;
    std::cout << "Nhap vao ID sach ban muon xoa khoi don hang: ";
    std::cin >> dlt_id;

    bool found = false;
    for (int i = 0; i < so_loai; i++) {
        if (book_id[i] == dlt_id) {
            book_id.erase(book_id.begin() + i);
            book_quantity.erase(book_quantity.begin() + i);
            so_loai--;
            found = true;
            std::cout << "Xoa thanh cong!!" << std::endl;
            break;
        }
    }

    if (!found) {
        std::cout << "Khong tim thay sach co ID " << dlt_id << " trong don hang." << std::endl;
    }

    return *this;
}

void order::display() {
    std::cout << "HOA DON CUA BAN: " << std::endl;
    std::cout << "So loai sach: " << so_loai << std::endl;
    for (int i = 0; i < so_loai; i++) {
        std::cout << book_id[i] << "     " << book_quantity[i] << std::endl;
    }
    int sum = sum_total();
    std::cout << "Tong tien: " << sum << std::endl;
    std::cout << "Tien nhan: " << pay_money << std::endl;
    std::cout << "Tien thua: " << change_money << std::endl;
    std::cout << "XIN CAM ON <3" << std::endl;
}
