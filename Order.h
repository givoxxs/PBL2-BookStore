#ifndef ORDER_H
#define ORDER_H
#include"Book.h"
#include "Date.h"
#include "Prepare.h"
#include "Sold.h"
#include<iostream>
#include<vector>

class order {
    private: 
        std::string order_id;
        std::string id_emp;
        std::string name_cus;
        std::string sdt_cus;

        int so_loai;
        int pay_money;
        int change_money;
        std::vector<sold> book_sold; 
        Date d;
        
    public:
        order();
        order(int id_emp, std::string sdt_cus, int so_loai, int pay_money, std::vector<sold> book_sold ,Date d);
        ~order();

        int get_price(int a);// lay ra gia tien moi loai sach
        int sum_total();// tong tien don hang
        void pay();// tien nhan 
        void change(int );//tien thua

        
        order create();// tao don hang
        int set_info();//lay thong tin nhan vien va khach hang
        void choose();//lua chon 

        order remove_type();// xoa sach khoi don hang
        order remove_qtt();
        void remove();

        //giam so luong sach trong kho
        static void decrease_store() ;
        void display();// xuat hoa don


        static void allthing();
        

};

#endif