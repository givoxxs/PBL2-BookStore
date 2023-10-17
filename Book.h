#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include<string>
using namespace std;
class Book {
    private:
        int id;
        string title;
        string author;
        string genre;
        int price;
        int quantity;
        string publisher;
        int publishingYear;
        string bookShelves;
        string language;

        string no_space(const string s);

        void search_title(string abc);
        void search_author(string abc);
        void search_genre(string abc);
        void search_language(string abc);

    public:
        Book();
        Book(int id, string title, string author, string genre, int price, int quantity, string publisher, int publishingYear, string bookShelves, string language);
        ~Book();
        Book &add();
        Book &increase(int a);
        Book &decrease(int a);
        void display();
        void search();
        int get_id();
        int get_price();

};
#endif
