#ifndef BOOK_H
#define BOOK_H
// #include "MyMenu.h"
// #include "MyLib.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

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

public:
    Book();
    Book(int id, std::string title, std::string author, std::string genre, int price, int quantity, std::string publisher, int publishingYear, std::string bookShelves, std::string language);
    ~Book();
    Book &add();
    Book &increase(int a);
    Book &decrease(int a);
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

    // Show search
    void display() const;
    static std::string no_space(const std::string s);
    static void search_title(std::string abc, std::vector<Book> BookInventory);
    static void search_author(std::string abc, std::vector<Book> BookInventory);
    static void search_genre(std::string abc, std::vector<Book> BookInventory);
    static void search_language(std::string abc, std::vector<Book> BookInventory);
    static void display_All(std::vector<Book> BookInventory);
    static void search(std::vector<Book> BookInventory);
};

#endif
