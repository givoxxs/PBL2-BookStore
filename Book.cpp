#include "Book.h"
#include "Prepare.h"
#include "MyLib.h"
#include "BookLib_Menu.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

Book::Book() {}
Book::Book(int id, std::string title, std::string author, std::string genre, int price, int quantity,
           std::string publisher, int publishingYear, std::string bookShelves, std::string language)
    : id(id), title(title), author(author), genre(genre), price(price),
      quantity(quantity), publisher(publisher), publishingYear(publishingYear), bookShelves(bookShelves), language(language) {}

Book::~Book() {}

// cac phuong thuc Private
std::string Book::no_space(const std::string s)
{
    std::string result = "";
    for (char c : s)
    {
        if (c != ' ')
        {
            result += tolower(c);
        }
        else
        {
            result += c;
        }
    }
    return result;
}

void Book::search_title(std::string abc)
{
    int count = 0;
    cout << left << setw(5) << "ID" << setw(40) << "Tieu de" << setw(25) << "Tac gia" << setw(20) << "The loai" << setw(15) << "Gia (VND)";
    cout << setw(10) << "So luong" << setw(30) << "Nha xuat ban" << setw(20) << "Nam xuat ban" << setw(15) << "Ke sach" << setw(15) << "Ngon ngu" << endl<<endl;
    for (int i = 0; i < books.size(); i++)
    {
        if (no_space(books[i].title).find(no_space(abc)) != string::npos)
        {
            books[i].display();
            cout << endl;
            count++;
        }
    }
    if (count == 0)
        std::cout << "NOT FOUND THIS BOOK !!!" << std::endl;
}

void Book::search_author(std::string abc)
{
    int count = 0;
    cout << left << setw(5) << "ID" << setw(40) << "Tieu de" << setw(25) << "Tac gia" << setw(20) << "The loai" << setw(15) << "Gia (VND)";
    cout << setw(10) << "So luong" << setw(30) << "Nha xuat ban" << setw(20) << "Nam xuat ban" << setw(15) << "Ke sach" << setw(15) << "Ngon ngu" << endl<<endl;
    for (int i = 0; i < books.size(); i++)
    {
        if (no_space(books[i].author).find(no_space(abc)) != string::npos)
        {
            books[i].display();
            cout << endl;
            count++;
        }
    }
    if (count == 0)
        std::cout << "NOT FOUND THIS BOOK !!!" << std::endl;
}

void Book::search_genre(std::string abc)
{
    int count = 0;
    cout << left << setw(5) << "ID" << setw(40) << "Tieu de" << setw(25) << "Tac gia" << setw(20) << "The loai" << setw(15) << "Gia (VND)";
    cout << setw(10) << "So luong" << setw(30) << "Nha xuat ban" << setw(20) << "Nam xuat ban" << setw(15) << "Ke sach" << setw(15) << "Ngon ngu" << endl<<endl;
    for (int i = 0; i < books.size(); i++)
    {
        if (no_space(books[i].genre).find(no_space(abc)) != string::npos)
        {
            books[i].display();
            cout << endl;
            count++;
        }
    }
    if (count == 0)
        std::cout << "NOT FOUND THIS BOOK !!!" << std::endl;
}

void Book::search_language(std::string abc)
{
    int count = 0;
    cout << left << setw(5) << "ID" << setw(40) << "Tieu de" << setw(25) << "Tac gia" << setw(20) << "The loai" << setw(15) << "Gia (VND)";
    cout << setw(10) << "So luong" << setw(30) << "Nha xuat ban" << setw(20) << "Nam xuat ban" << setw(15) << "Ke sach" << setw(15) << "Ngon ngu" << endl<<endl;
    for (int i = 0; i < books.size(); i++)
    {
        if (no_space(books[i].language).find(no_space(abc)) != string::npos)
        {
            books[i].display();
            cout << endl;
            count++;
        }
    }
    if (count == 0)
        std::cout << "NOT FOUND THIS BOOK !!!" << std::endl;
}

Book &Book::add()
{
    getchar();
    int max = books.size();
    int new_id = books[max - 1].get_id() + 1;
    this->id = new_id;
    int x = 80, y = 5, h = 2;
    box_Add_Book();
    gotoXY(x + 15, y + 1);
    cout << new_id;
    gotoXY(x + 15, y + 3);
    getline(cin, title);
    gotoXY(x + 15, y + 5);
    getline(cin, author);
    gotoXY(x + 15, y + 7);
    getline(cin, genre);
    gotoXY(x + 15, y + 9);
    cin >> price;
    gotoXY(x + 15, y + 11);
    cin >> quantity;
    getchar();
    gotoXY(x + 15, y + 13);
    getline(cin, publisher);
    gotoXY(x + 15, y + 15);
    cin >> publishingYear;
    getchar();
    gotoXY(x + 15, y + 17);
    getline(cin, bookShelves);
    gotoXY(x + 15, y + 19);
    getline(cin, language);
    return *this;
}

void Book::add_new_book()
{
    Book newBook;
    newBook.add();
    books.push_back(newBook);
    gotoXY(80, 5 + 23);
    ofstream inventoryFile("books.txt", ios::app);

    if (!inventoryFile)
    {
        cerr << "Khong the mo InventoryBook.txt de ghi du lieu." << endl;
        return;
    }
    inventoryFile << newBook.get_id() << ","
                  << newBook.get_title() << ","
                  << newBook.get_author() << ","
                  << newBook.get_genre() << ","
                  << newBook.get_price() << ","
                  << newBook.get_quantity() << ","
                  << newBook.get_publisher() << ","
                  << newBook.get_publishingYear() << ","
                  << newBook.get_bookShelves() << ","
                  << newBook.get_language() << endl;
    inventoryFile.close();
    cout << "Sach moi da duoc them vao kho" << endl;
    gotoXY(80, 5 + 24);
    system("pause");
}

void Book::display()
{

    std::cout << std::setiosflags(std::ios::left) << std::setw(5) << id;
    std::cout << std::setw(40) << title;
    std::cout << std::setw(25) << author;
    std::cout << std::setw(20) << genre;
    std::cout << std::setw(10) << price;
    std::cout << std::setw(1) << " ";
    std::cout << std::setw(9) << quantity;
    std::cout << std::setw(20) << publisher;
    std::cout << std::setw(3) << "   ";
    std::cout << std::setw(17) << publishingYear;
    std::cout << std::setw(15) << bookShelves;
    std::cout << std::setw(15) << language << std::endl;
}

void Book::increase()
{
    int ids, a;
    cout << "Nhap vao id cuon sach va so luong can them: ";
    cin >> ids >> a;
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].id == ids)
        {
            books[i].quantity += a;
            cout << "Thay doi thanh cong!!!" << endl;
            // return;
        }
    }
}

void Book::decrease(int a)
{
    this->set_quantity(a);
}

void Book::set_quantity(int a)
{
    this->quantity = a;
}

void Book::search()
{

    int choose, n = 5;
    string nd[n], nd1;
    nd[0] = "Theo TIEU DE / Search by Book Title";
    nd[1] = "Theo TAC GIA / Search by Author";
    nd[2] = "Theo THE LOAI / Search by Category";
    nd[3] = "Theo NGON NGU / Search by Language";
    nd[4] = "THOAT / EXIT";

    nd1 = "         TUY CHON TIM KIEM / CHANGE OPTIONS";
    do
    {
        system("cls");
        system("cls");
        box(70 - 2, 5 - 2, 50 + 4, 2 + 17, 11, 75, nd1);
        choose = Menu(70, 5, 50, 2, 11, 75, nd, n);
        std::string searching = "";
        switch (choose)
        {
        case 0:
            searching = box_Search_BOOK("TEN SACH");
            search_title(searching);
            system("pause");
            break;
        case 1:
            searching = box_Search_BOOK("TAC GIA");
            search_author(searching);
            system("pause");
            break;
        case 2:
            searching = box_Search_BOOK("THE LOAI");
            search_genre(searching);
            system("pause");
            break;
        case 3:
            searching = box_Search_BOOK("NGON NGU");
            search_language(searching);
            system("pause");
            break;
        case 4:
            break;
        }
    } while (n - choose - 1);
}

int Book::get_id()
{
    return this->id;
}

std::string Book::get_title()
{
    return this->title;
}

std::string Book::get_author()
{
    return this->author;
}

std::string Book::get_genre()
{
    return this->genre;
}

int Book::get_price()
{
    return this->price;
}

int Book::get_quantity()
{
    return this->quantity;
}

std::string Book::get_publisher()
{
    return this->publisher;
}

int Book::get_publishingYear()
{
    return this->publishingYear;
}

std::string Book::get_bookShelves()
{
    return this->bookShelves;
}

std::string Book::get_language()
{
    return this->language;
}

void Book::display_All()
{
    std::cout << std::setiosflags(std::ios::left) << std::setw(5) << "ID";
    std::cout << std::setw(40) << "Tieu de";
    std::cout << std::setw(25) << "Tac gia";
    std::cout << std::setw(20) << "The loai";
    std::cout << std::setw(15) << "Gia (VND)";
    std::cout << std::setw(10) << "So luong";
    std::cout << std::setw(30) << "Nha Xuat Ban";
    std::cout << std::setw(20) << "Nam Xuat Ban";
    std::cout << std::setw(15) << "Ke Sach";
    std::cout << std::setw(15) << "Ngon ngu" << std::endl
              << std::endl;

    for (int i = 0; i < books.size(); i++)
    {
        books[i].display();
        cout << endl;
    }
}

void Book::re_price()
{
    int thay_doi;
    int new_price;
    cout << "Nhap vao id can thay doi gia: ";
    cin >> thay_doi;

    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].get_id() == thay_doi)
        {
            cout << "Nhap vao gia ban moi: ";
            cin >> new_price;
            books[i].set_price(new_price);
            break;
        }
    }
}

void Book::set_price(int price)
{
    this->price = price;
}

void Book::change()
{
    int chon;
    cout << "1. Them sach " << endl;
    cout << "2. Thay doi gia ban " << endl;
    cin >> chon;
    switch (chon)
    {
    case 1:
        increase();
        thay_doi_tep_books();
        break;
    case 2:
        re_price();
        thay_doi_tep_books();
        break;
    default:
        break;
    }
}

void Book::delete_book()
{
    int id_dlt;
    cout << "Nhap ID quyen sach can loai bo: ";
    cin >> id_dlt;
    int max = books.size();
    for (int i = 0; i < max; i++)
    {
        if (books[i].get_id() == id_dlt)
        {
            books[i].set_quantity(0);
            cout<<"Xoa thanh cong"<<endl;
            break;
        }
    }
    thay_doi_tep_books();
}
