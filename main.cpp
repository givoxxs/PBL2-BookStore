#include "Book.h"
#include "Employee.h"
#include"Customer.h"
#include"Order.h"
#include<iostream>
#include<vector>
#include<string.h>
#include<iomanip>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    /*
    vector<Book> books;
    ifstream myfile("books.txt");
    if (myfile.is_open()) {
        string line;
        while (getline(myfile, line)) {
            stringstream ss(line);
            string ids;
            string title;
            string author;
            string genre;
            string prices;
            string quantitys;
            string publisher;
            string publishingYear;
            string bookShelves;
            string language;
            if (getline(ss, ids, ',')) {
                int id;
                stringstream(ids) >> id;
                if (getline(ss, title, ',')) {
                    if (getline(ss, author, ',')) {
                        if (getline(ss, genre, ',')) {
                            if (getline(ss, prices, ',')) {
                                int price;
                                stringstream(prices) >> price;
                                if (getline(ss, quantitys, ',')) {
                                    int quantity;
                                    stringstream(quantitys) >> quantity;
                                    if (getline(ss, publisher, ',')) {
                                        if (getline(ss, publishingYear, ',')) {
                                            if (getline(ss, bookShelves, ',')) {
                                                if (getline(ss, language)) {
                                                    Book book(id, title, author, genre, price, quantity,
                                                              publisher, publishingYear, bookShelves, language);
                                                    books.push_back(book);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        myfile.close();
    } else {
        cout << "Unable to open file" << endl;
    }

    for (int i = 0; i < books.size(); i++) {
        books[i].display();
        cout << "\n";
    }
    


    // order o;
    // o.create(books);
    // o.choose();
    // o.display();
    */

   vector<Book> books; // Vector để chứa thông tin sách

    ifstream inputFile("books.txt");
    if (!inputFile) {
        cerr << "Không thể mở tệp tin." << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        Book book;
        // Đọc dữ liệu từ tệp tin và gán cho cấu trúc sách
        if (sscanf(line.c_str(), "%d,%s[^,],%s[^,],%s[^,],%d,%d,%s[^,],%s[^,],%s[^,],%s", 
            &book.id, &book.title[0], &book.author[0], &book.genre[0], &book.price, 
            &book.quantity, &book.publisher[0], &book.publishingYear[0], 
            &book.bookShelves[0], &book.language[0]) == 10) {
            books.push_back(book);
        } else {
            cout << "Dòng không hợp lệ: " << line << endl;
        }
    }
    inputFile.close();

    for (const Book& book : books) {
        cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << endl;
    }

    return 0;
}


