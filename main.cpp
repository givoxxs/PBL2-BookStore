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

    vector<Book> BookInventory;

void lay_du_lieu () {
    ifstream inventoryFile("books.txt");
    if (!inventoryFile) {
        cerr << "Không thể mở tệp InventoryBook.txt để đọc dữ liệu." << endl;
        return ;
    }

    string line;
    while (getline(inventoryFile, line)) {
        stringstream ss(line);
        string item;
        int id;
        string title, author, genre, publisher, bookShelves, language;
        int price, quantity, publishingYear;

        getline(ss, item, ',');
        stringstream(item) >> id;

        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, genre, ',');
        
        getline(ss, item, ',');
        stringstream(item) >> price;

        getline(ss, item, ',');
        stringstream(item) >> quantity;

        getline(ss, publisher, ',');
        getline(ss, item, ',');
        stringstream(item) >> publishingYear;

        getline(ss, bookShelves, ',');
        getline(ss, language, ',');

        Book book(id, title, author, genre, price, quantity, publisher, publishingYear, bookShelves, language);
        BookInventory.push_back(book);
    }

    inventoryFile.close();

        
}
int main() {

    lay_du_lieu();





    return 0;
}



