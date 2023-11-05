#ifndef ORDER_H
#define ORDER_H

#include "Book.h"
#include <iostream>
#include <vector>

class order {
private:
    int so_loai;
    int pay_money;
    int change_money;
    std::vector<int> book_id;
    std::vector<int> book_quantity;
    std::vector<Book> books;

public:
    order();
    order(int so_loai, std::vector<int> a, std::vector<int> b, std::vector<Book> books, int pay_money);
    ~order();
    int get_price(int a);  // lay ra gia tien moi loai sach
    int sum_total();       // tong tien don hang
    void pay();            // tien nhan
    void change();         // tien thua
    order create(std::vector<Book> books);  // tao don hang
    void choose();                          // lua chon tiep theo
    order remove();                         // xoa sach khoi don hang
    void display();                         // xuat hoa don
};

#endif
