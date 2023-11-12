#include "Prepare.h"
#include <iostream>
using namespace std;

vector<Book> books;
vector<customer> customers;
vector<employee> employees;
vector<Save> saveOrder;
int solds[100] = {0};

void create_book_list()
{
    ifstream inventoryFile("books.txt");
    if (!inventoryFile)
    {
        cerr << "Không thể mở tệp books.txt để đọc dữ liệu." << endl;
        return;
    }

    string line;
    while (getline(inventoryFile, line))
    {
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
        books.push_back(book);
    }

    inventoryFile.close();
}

void create_cus_list()
{
    ifstream inventoryFile("customers.txt");
    if (!inventoryFile)
    {
        cerr << "Không thể mở tệp customers.txt để đọc dữ liệu." << endl;
        return;
    }

    string line;
    while (getline(inventoryFile, line))
    {
        stringstream ss(line);
        string item1, item2;
        int year, point;
        string id, name, phone_number;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, phone_number, ',');

        getline(ss, item1, ',');
        stringstream(item1) >> year;
        getline(ss, item2, ',');
        stringstream(item2) >> point;
        customer a(id, name, phone_number, year, point);
        customers.push_back(a);
    }

    inventoryFile.close();
}

void create_emp_list()
{
    ifstream inventoryFile("employees.txt");
    if (!inventoryFile)
    {
        cerr << "Không thể mở tệp employees.txt để đọc dữ liệu." << endl;
        return;
    }

    string line;
    while (getline(inventoryFile, line))
    {
        stringstream ss(line);
        string item;
        int year_of_birthday;
        float wage;
        string id, name, phone_number, CICard, address;

        getline(ss, id, ',');

        getline(ss, name, ',');
        getline(ss, phone_number, ',');

        getline(ss, item, ',');
        stringstream(item) >> year_of_birthday;

        getline(ss, CICard, ',');
        getline(ss, address, ',');

        getline(ss, item, ',');
        stringstream(item) >> wage;
        employee a(id, name, phone_number, wage, CICard, address, year_of_birthday);
        employees.push_back(a);
    }

    inventoryFile.close();
}

void create_save_list()
{
    std::ifstream inputFile("save.txt");

    if (inputFile.is_open())
    {
        std::string line;

        while (std::getline(inputFile, line))
        {
            std::istringstream iss(line);
             std::string order_id;
            int year, month, day, hour, minute, second;
            std::string id_nhanvien;
            std::string sdt_cus;
            std::vector<sold> items;

            // Đọc dữ liệu từ mỗi dòng
            iss >> order_id >> year >> month >> day >> hour >> minute >> second >> id_nhanvien >> sdt_cus;

            int book_id, book_qtt;
            while (iss >> book_id >> book_qtt)
            {
                sold item;
                item.set_book_id(book_id);
                item.set_book_qtt(book_qtt);
                items.push_back(item);
            }

            // Tạo đối tượng Date
            Date date(year, month, day, hour, minute, second);

            // Tạo đối tượng Save và thêm vào vector s
            saveOrder.emplace_back(order_id, date, id_nhanvien, sdt_cus, items);
        }

        inputFile.close();

        // Bây giờ bạn đã có vector s chứa các đối tượng Save và sold từ tệp tin.
    }
    else
    {
        std::cerr << "Không thể mở tệp tin save.txt" << std::endl;
    }
}

void thay_doi_tep_books()
{

    ofstream outputFile("books.txt");
    if (outputFile.is_open())
    {
        for (int i = 0; i < books.size(); i++)
        {
            outputFile << books[i].get_id() << ","
                       << books[i].get_title() << ","
                       << books[i].get_author() << ","
                       << books[i].get_genre() << ","
                       << books[i].get_price() << ","
                       << books[i].get_quantity() << ","
                       << books[i].get_publisher() << ","
                       << books[i].get_publishingYear() << ","
                       << books[i].get_bookShelves() << ","
                       << books[i].get_language() << "\n";
        }

        outputFile.close();
    }
}

void thay_doi_tep_customers()
{
    ofstream outputFile("customers.txt");
    if (outputFile.is_open())
    {
        for (int i = 0; i < customers.size(); i++)
        {
            outputFile << customers[i].get_id() << ","
                       << customers[i].get_name() << ","
                       << customers[i].get_phone_num() << ","
                       << customers[i].get_year_of_birthday() << ","
                       << customers[i].get_point() << endl;
        }
        outputFile.close();
    }
}

void thay_doi_tep_employees()
{
    ofstream outputFile("employees.txt");
    if (outputFile.is_open())
    {
        for (int i = 0; i < employees.size(); i++)
        {
            outputFile << employees[i].get_id() << ","
                       << employees[i].get_name() << ","
                       << employees[i].get_phone_num() << ","
                       << employees[i].get_year_of_birthday() << ","
                       << employees[i].get_CI() << ","
                       << employees[i].getAddress() << ","
                       << employees[i].get_wage() << endl;
        }
        outputFile.close();
    }
}

void thay_doi_tep_save()
{

    // Điền vector s với dữ liệu

    std::ofstream outputFile("save.txt");

    if (outputFile.is_open())
    {
        for (Save temp : saveOrder)
        {
            //ghi ma hoa don
            outputFile << temp.getOrder_id() << " ";
            // Ghi thông tin ngày
            outputFile << temp.getDate().getYear() << " " << temp.getDate().getMonth() << " " << temp.getDate().getDay() << " ";
            outputFile << temp.getDate().getHour() << " " << temp.getDate().getMinute() << " " << temp.getDate().getSecond() << " ";

            // Ghi mã nhân viên
            outputFile << temp.getEmp_id() << " ";
            //ghi ma khach hang
            outputFile << temp.getSdt_cus() << " ";

            // Ghi thông tin về sách
            for (int i = 0; i < temp.getSave().size(); i++)
            {
                outputFile << temp.getSave()[i].get_book_id() << " " << temp.getSave()[i].get_book_qtt() << " ";
            }

            // Xuống dòng cho dòng tiếp theo
            outputFile << "\n";
        }

        outputFile.close();
    }
    else
    {
        std::cerr << "Không thể mở tệp tin save.txt để ghi dữ liệu." << std::endl;
    }
}