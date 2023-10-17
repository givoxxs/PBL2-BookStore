#include "Book.h"
#include<iostream>
using namespace std;

int main() {
    Book a(123, "Nha Gia Kim"           ,"Nhat Tuan"        ," tieu thuyet"     ,12000        ,12       ,"Nhatttua"      ,2004       ,"12A"     ,"Tieng Anh");
    a.display();
    a.search();
    return 0;
}