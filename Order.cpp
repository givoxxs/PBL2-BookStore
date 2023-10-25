#include "Order.h"
#include"Book.h"
#include<iostream>
#include<vector>
using namespace std;

order::order(){}
order::order(int so_loai, vector<int> a, vector<int> b, vector<Book> books, int pay_money) {
    this->so_loai = so_loai;
    this->book_id=a;
    this->book_quantity=b;
    this->books=books;
    this->pay_money=pay_money;
}
order::~order(){}

int order::get_price(int a) {
    for(int i=0;i<books.size();i++) {
        if(a==books[i].get_id()) {
            return books[i].get_price();
        }
    }
    return -1;
}

int order::sum_total() {
    int sum=0;
    for(int i=0;i<so_loai;i++) {
        sum+=get_price(book_id[i])*book_quantity[i];
    }
    return sum;
}

void order::pay() {
    cin>>this->pay_money;
    change();
}

void order::change() {
    this->change_money =  this->pay_money - sum_total();
}


order order::create(vector<Book> books) {
    this->books=books;
    cout<<"Nhap vao tong loai sach: ";
    cin>>this->so_loai;
    cout<<"Nhap vao id cua sach va so luong tuong ung: "<<endl;
    for(int i=0;i<so_loai;i++) {
        int a,b;
        cout<<"ID quyen sach thu "<<i+1<<": ";
        cin>>a;
        cout<<"So luong: ";
        cin>>b;
        book_id.push_back(a);
        book_quantity.push_back(b);
    }

    return *this;
}


void order::choose() {
    int chosen;
    cout<<"Tong tien la: "<<sum_total()<<endl;
    do {
        cout << "Ban muon: " << endl;
        cout << "1. Tinh tien" << endl << "2. Thay doi don hang" << endl;
        cin >> chosen;

        switch (chosen) {
            case 1:
                cout<<"Tien nhan cua khach: ";
                pay();
                break;
            case 2:
                remove();
                cout<<"Tong tien con lai: "<<sum_total()<<endl;
                break;
            default:
                cout << "Lua chon sai. Vui long nhap lai." << endl;
        }
    } while (chosen != 1);
}

order order::remove() {
    int dlt_id;
    cout << "Nhap vao ID sach ban muon xoa khoi don hang: ";
    cin >> dlt_id;

    bool found = false;
    for (int i = 0; i < so_loai; i++) {
        if (book_id[i] == dlt_id) {
            book_id.erase(book_id.begin() + i);
            book_quantity.erase(book_quantity.begin() + i);
            so_loai--;
            found = true;
            cout<<"Xoa thanh cong!!"<<endl;
            break; 
        }
    }

    if (!found) {
        cout << "Khong tim thay sach co ID " << dlt_id << " trong don hang." << endl;
    }

    return *this;
}

void order::display() {
    cout<<"HOA DON CUA BAN: "<<endl;
    cout<<"So loai sach: "<<so_loai<<endl;
    for(int i=0;i<so_loai;i++) {
        cout<<book_id[i]<<"     "<<book_quantity[i]<<endl;
    }
    int sum=sum_total();
    cout<<"Tong tien: "<<sum<<endl;
    cout<<"Tien nhan: "<<pay_money<<endl;
    cout<<"Tien thua: "<<change_money<<endl;
    cout<<"XIN CAM ON <3"<<endl;
}

