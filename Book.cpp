#include "Book.h"
#include<iostream>
#include<string.h>
#include<iomanip>
#include<vector>
using namespace std;



Book::Book() {}
Book::Book(int id, string title, string author, string genre, int price, int quantity,
string publisher, int publishingYear, string bookShelves, string language) 
:id(id),title(title),author(author),genre(genre),price(price),
quantity(quantity),publisher(publisher),publishingYear(publishingYear),bookShelves(bookShelves),language(language) {}

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


void Book::search_title(string abc,vector<Book> BookInventory) {
    for(int i=0;i<BookInventory.size();i++) {
        if(no_space(abc)==no_space(BookInventory[i].title)) {
            BookInventory[i].display();
        }
    }
}

void Book::search_author(string abc,vector<Book> BookInventory) {
    for(int i=0;i<BookInventory.size();i++) {
        if(no_space(abc)==no_space(BookInventory[i].author)) {
            BookInventory[i].display();
        }
    }
}

void Book::search_genre(string abc,vector<Book> BookInventory) {
    for(int i=0;i<BookInventory.size();i++) {
        if(no_space(abc)==no_space(BookInventory[i].genre)) {
            BookInventory[i].display();
        }
    }
}

void Book::search_language(string abc,vector<Book> BookInventory)  {
    for(int i=0;i<BookInventory.size();i++) {
        if(no_space(abc)==no_space(BookInventory[i].language)) {
            BookInventory[i].display();
        }
    }
}


// cac phuong thuc Public

Book &Book::add() {
    cout<<"Nhap id: ";
    cin>>id;
    cout<<"Nhap tieu de: ";
    getchar();
    getline(cin, title);
    cout<<"Nhap tac gia: ";
    getline(cin, author);
    cout<<"Nhap the loai: ";
    getline(cin, genre);
    cout<<"Nhap gia: ";
    cin>>price;
    cout<<"Nhap so luong: ";
    cin>>quantity;
    cout<<"Nhap nha xuat ban: ";
    getchar();
    getline(cin, publisher);
    cout<<"Nhap nam xuat ban: ";
    cin>>publishingYear;
    getchar();
    cout<<"Nhap ke sach: ";
    getline(cin, bookShelves);
    cout<<"Nhap ngon ngu: ";
    getline(cin, language);

    return *this;
}

void Book::display() const {
    cout<<setiosflags(ios::left)<<setw(5)<<id;
    cout<<setw(40)<<title;
    cout<<setw(20)<<author;
    cout<<setw(25)<<genre;
    cout<<setw(10)<<price;
    cout<<setw(10)<<quantity;
    cout<<setw(20)<<publisher;
    cout<<setw(15)<<publishingYear;
    cout<<setw(15)<<bookShelves;
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


void Book::search(vector<Book> BookInventory) {
    int choose;
    do { 
        cout<<"Các lựa chọn tìm kiếm: "<<endl;
        cout<<"<1>: Tìm theo tiêu đề"<<endl<<"<2>: Tìm theo tác giả"<<endl;
        cout<<"<3>: Tìm theo thể loại: "<<endl<<"<4>: Tìm theo ngôn ngữ"<<endl;
        cout<<"Nhập lựa chọn của bạn: ";
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
        search_title(searching,BookInventory);
        break;
    case 2:
        cout<<"Nhap tac gia can tim: ";
        getline(cin,searching);
        search_author(searching,BookInventory);
        break;
    case 3:
        cout<<"Nhap the loai can tim: ";
        getline(cin,searching);
        search_genre(searching,BookInventory);
        break;
    case 4:
        cout<<"Nhap ngon ngu can tim: ";
        getline(cin,searching);
        search_language(searching,BookInventory);
        break;
    }
}

int Book::get_id()  {
    return this->id;
}

string Book::get_title() {
    return this->title;
}

string Book::get_author() {
    return this->author;
}

string Book::get_genre() {
    return this->genre;
}

int Book::get_price() {
    return this->price;
}

int Book::get_quantity() {
    return this->quantity;
}

string Book::get_publisher() {
    return this->publisher;
}

int Book::get_publishingYear() {
    return this->publishingYear;
}

string Book::get_bookShelves() {
    return this->bookShelves;
}

string Book::get_language() {
    return this->language;
}


void Book::display_All(vector<Book> BookInventory)  {
    cout<<setiosflags(ios::left)<<setw(5)<<"ID";
    cout<<setw(40)<<"Title";
    cout<<setw(20)<<"Author";
    cout<<setw(25)<<"Genre";
    cout<<setw(10)<<"Price";
    cout<<setw(10)<<"Quantity";
    cout<<setw(20)<<"Publisher";
    cout<<setw(15)<<"PublishingYear";
    cout<<setw(15)<<"BookShelves";
    cout<<setw(15)<<"Language"<<endl<<endl;
    for(int i=0;i<BookInventory.size();i++) {
        BookInventory[i].display();
        cout<<endl;
    }
}



