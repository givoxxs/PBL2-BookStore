#include "Book.h"
#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

Book::Book() {}
Book::Book(int id, string title, string author, string genre, int price, int quantity, string publisher, int publishingYear, string bookShelves, string language) 
:id(id),title(title),author(author),genre(genre),price(price),quantity(quantity),publisher(publisher),publishingYear(publishingYear),bookShelves(bookShelves),language(language) {}

Book::~Book() {}

// cac phuong thuc Private
string Book::no_space(const string s) {
    string result = "";
        for (char c : s) {
            if (c != ' ') {
                result += tolower(c);
            }
        }   
    return result;
}


void Book::search_title(string abc) {
    if(no_space(title) == no_space(abc)) {
        display();
    }
}

void Book::search_author(string abc) {
    if(no_space(author) == no_space(abc)) {
        display();
    }
}

void Book::search_genre(string abc) {
    if(no_space(genre) == no_space(abc)) {
        display();
    }
}

void Book::search_language(string abc)  {
    if(no_space(language) == no_space(abc)) {
        display();
    }
}


// cac phuong thuc Public

Book &Book::add() {
    cout<<"nhap id: ";
    cin>>id;
    cout<<"nhap tieu de: ";
    getchar();
    getline(cin, title);
    cout<<"nhap tac gia: ";
    getline(cin, author);
    cout<<"nhap the loai: ";
    getline(cin, genre);
    cout<<"nhap gia: ";
    cin>>price;
    cout<<"nhap so luong: ";
    cin>>quantity;
    cout<<"nhap nha xuat ban: ";
    getchar();
    getline(cin, publisher);
    cout<<"nhap nam xuat ban: ";
    cin>>publishingYear;
    getchar();
    cout<<"nhap ke sach: ";
    getline(cin, bookShelves);
    cout<<"nhap ngon ngu: ";
    getline(cin, language);

    return *this;
}

void Book::display() {
    cout<<setw(10)<<id;
    cout<<setw(20)<<title;
    cout<<setw(20)<<author;
    cout<<setw(20)<<genre;
    cout<<setw(10)<<price;
    cout<<setw(10)<<quantity;
    cout<<setw(15)<<publisher;
    cout<<setw(10)<<publishingYear;
    cout<<setw(10)<<bookShelves;
    cout<<setw(15)<<language<<endl;
}

Book &Book::increase(int a) {
    this->quantity += a;
    return *this;
}

Book &Book::decrease(int a) {
    this->quantity -= a;
    return *this;
}


void Book::search( ) {
    int choose;
    do { 
        cout<<"Cac lua chon tim kiem: "<<endl;
        cout<<"<1>: Tim theo TIEU DE"<<endl<<"<2>: Tim theo TAC GIA"<<endl;
        cout<<"<3>: Tim theo THE LOAI: "<<endl<<"<4>: Tim theo NGON NGU"<<endl;
        cout<<"Nhap lua chon cua ban: ";
        cin>>choose;
        getchar();
        if (choose < 1 || choose > 4) { 
            system("cls");
            cout<<"Lựa chọn không hợp lệ!!! Vui lòng nhập lại."<<endl; // In ra thông báo
        }
    } while (choose < 1 || choose > 4);

    string searching;
    switch (choose)
    {
    case 1:
        cout<<"Nhap tac pham can tim: ";
        getline(cin,searching);
        search_title(searching);
        break;
    case 2:
        cout<<"Nhap tac gia can tim: ";
        getline(cin,searching);
        search_author(searching);
        break;
    case 3:
        cout<<"Nhap the loai can tim: ";
        getline(cin,searching);
        search_genre(searching);
        break;
    case 4:
        cout<<"Nhap ngon ngu can tim: ";
        getline(cin,searching);
        search_language(searching);
        break;
    }
}


