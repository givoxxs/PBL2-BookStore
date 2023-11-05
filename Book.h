#ifndef BOOK_H
#define BOOK_H
#include <bits/stdc++.h>
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


    public:
        Book();
        Book(int id, string title, string author, string genre, int price, int quantity, string publisher, int publishingYear, string bookShelves, string language);
        ~Book();
        Book &add();
        Book &increase(int a);
        Book &decrease(int a);
        int get_id();
        string get_title();
        string get_author();
        string get_genre();
        int get_price();
        int get_quantity();
        string get_publisher();
        int get_publishingYear();
        string get_bookShelves();
        string get_language();

        // show search 
        void display() const;
        static string no_space(const string s);
        static void search_title(string abc,vector<Book> BookInventory);
        static void search_author(string abc,vector<Book> BookInventory);
        static void search_genre(string abc,vector<Book> BookInventory);
        static void search_language(string abc,vector<Book> BookInventory);
        static void display_All(vector<Book> BookInventory) ;
        static void search(vector<Book> BookInventory);

};
#endif
