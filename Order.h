#ifndef ORDER_H
#define ORDER_H
#include"Book.h"
#include<iostream>
#include<vector>
using namespace std;
class order {
    private: 
        int so_loai;
        int pay_money;
        int change_money;
        vector<int> book_id;
        vector<int> book_quantity;
        vector<Book> books;
        
    public:
        order();
        order(int so_loai, vector<int> a, vector<int> b,vector<Book> books, int pay_money);
        ~order();
        int get_price(int a);// lay ra gia tien moi loai sach
        int sum_total();// tong tien don hang
        void pay();// tien nhan 
        void change();//tien thua
        order create(vector<Book> books);// tao don hang
        void choose();//lua chon tiep theo
        order remove();// xoa sach khoi don hang
        void display();// xuat hoa don

};

#endif