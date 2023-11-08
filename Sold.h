#ifndef SOLD_H
#define SOLD_H
#include<iostream>
#include "Date.h"

class sold {
    private:
        int book_id;
        int book_qtt;
    public:
        sold();
        sold(int , int );
        ~sold();
        int get_book_id();
        int get_book_qtt();
        void set_book_id(int book_id);
        void set_book_qtt(int book_qtt);
};
#endif