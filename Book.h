#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include<string>
#include<vector>
#include<time.h>


class Book {
    private:
        int id;
        std::string title;
        std::string author;
        std::string genre;
        int price;
        int quantity;
        std::string publisher;
        int publishingYear;
        std::string bookShelves;
        std::string language;

        static std::string no_space(const std::string s);
        static void search_title(std::string abc);
        static void search_author(std::string abc);
        static void search_genre(std::string abc);
        static void search_language(std::string abc);

    public:
        Book();
        Book(int id, std::string title, std::string author, std::string genre, int price, int quantity, std::string publisher, int publishingYear, std::string bookShelves, std::string language);
        ~Book();
        Book &add();
        
        int get_id();
        std::string get_title();
        std::string get_author();
        std::string get_genre();
        int get_price();
        int get_quantity();
        std::string get_publisher();
        int get_publishingYear();
        std::string get_bookShelves();
        std::string get_language();
       
        void display() ;
        
        static void display_All() ;
        static void search();

        static void increase();
        void decrease(int);
        void set_quantity(int );
        static void add_new_book();

};
#endif
