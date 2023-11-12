#include "Order.h"
#include "Book.h"
#include "Date.h"
#include "Sold.h"
#include "Prepare.h"
#include "Save.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// ham dung
order::order() {}
order::order(int id_emp, string sdt_cus, int so_loai, int pay_money, vector<sold> book_sold, Date d)
{
    this->id_emp = id_emp;
    this->sdt_cus = sdt_cus;
    this->so_loai = so_loai;
    this->book_sold = book_sold;
    this->pay_money = pay_money;
    this->d = d;
}
order::~order() {}

// lay gia
int order::get_price(int a)
{
    for (int i = 0; i < books.size(); i++)
    {
        if (a == books[i].get_id())
        {
            return books[i].get_price();
        }
    }
    return -1;
}

// tong tien
int order::sum_total()
{
    int sum = 0;
    for (int i = 0; i < so_loai; i++)
    {
        sum += get_price(book_sold[i].get_book_id()) * book_sold[i].get_book_qtt();
    }
    return sum;
}

// tien nhan
void order::pay()
{
    cin >> this->pay_money;
}

// tien thua
void order::change(int x)
{
    this->change_money = this->pay_money - x;
}

// tao 1 hoa don moi
order order::create()
{

    cout << "Nhap vao tong so loai sach: ";
    cin >> this->so_loai;
    cout << "Nhap vao id cua tung cuon sach va so luong tuong ung: " << endl;
    for (int i = 0; i < so_loai; i++)
    {
        sold a;
        cout << "ID cuon sach thu " << i + 1 << ": ";
        int x;
        cin >> x;
        a.set_book_id(x);
        cout << "So luong: ";
        int y;
        cin >> y;
        a.set_book_qtt(y);
        book_sold.push_back(a);
    }

    return *this;
}

int order::set_info()
{
    this->order_id = "HD" + to_string(saveOrder.size() + 1);
    int chon;
    getchar();
    cout << "Nhap ID nhan vien: ";
    getline(cin, id_emp);
    cout << "Khach hang da co the thanh vien ?" << endl;
    cout << "Nhan 1 neu co, 0 neu chua: ";
    cin >> chon;
    if (chon == 1)
    {
        getchar();
        cout << "SDT khach hang: ";
        getline(cin, sdt_cus);
        return 1;
    }
    else
    {
        char chon;
        cout << "Co muon tao the thanh vien khong?" << endl;
        cout << "Nhan Y neu muon, N neu khong: ";
        cin >> chon;
        getchar();
        if (chon == 'Y' || chon == 'y')
        {
            customer::add_new_cus();
            int temp = customers.size() - 1;
            this->sdt_cus = customers[temp].get_phone_num();
            return 1;
        }
        else if (chon == 'N' || chon == 'n')
        {
            cout << "Ten khach hang: ";
            getline(cin, this->name_cus);
            cout << "SDT khach hang: ";
            getline(cin, this->sdt_cus);
        }
    }
    return 0;
}

// lua chon
void order::choose()
{
    int chosen;
    do
    {
        cout << "Ban muon: " << endl;
        cout << "1. Tinh tien" << endl
             << "2. Thay doi don hang" << endl;
        cout << "Ban chon: ";
        cin >> chosen;

        switch (chosen)
        {
        case 1:
            cout << "Tong tien: " << sum_total() << " VDN" << endl;
            cout << "Tien nhan cua khach (don vi: VDN): ";
            pay();
            break;
        case 2:
            remove();
            cout << "Tong tien con lai: " << sum_total() << " VND" << endl;
            break;
        default:
            cout << "Lua chon sai. Vui long nhap lai." << endl;
            break;
        }
    } while (chosen != 1);
}

// xoa 1 loai sach khoi don hang
order order::remove_type()
{
    int dlt_id;
    cout << "Nhap vao ID sach ban muon xoa khoi don hang: ";
    cin >> dlt_id;
    bool found = false;
    for (int i = 0; i < so_loai; i++)
    {
        if (book_sold[i].get_book_id() == dlt_id)
        {
            book_sold.erase(book_sold.begin() + i);
            so_loai--;
            found = true;
            cout << "Xoa thanh cong!!" << endl;
            break;
        }
    }

    if (!found)
    {
        cout << "Khong tim thay sach co ID " << dlt_id << " trong don hang." << endl;
    }

    return *this;
}

// giam so luong 1 cuon sach
order order::remove_qtt()
{
    int dlt_id, qtt;
    cout << "Nhap vao ID sach ban muon thay doi so luong: ";
    cin >> dlt_id;
    cout << "So luong muon giam: ";
    cin >> qtt;
    bool found = false;
    for (int i = 0; i < so_loai; i++)
    {
        if (book_sold[i].get_book_id() == dlt_id)
        {
            int qtt_old = book_sold[i].get_book_qtt();
            book_sold[i].set_book_qtt(qtt_old - qtt);
            found = true;
            cout << "Thay doi thanh cong!!" << endl;
            break;
        }
    }

    if (!found)
    {
        cout << "Khong tim thay sach co ID " << dlt_id << " trong don hang." << endl;
    }

    return *this;
}

void order::remove()
{
    int chon;
    do
    {
        cout << "1. Xoa 1 cuon sach khoi don hang" << endl;
        cout << "2. Thay doi so luong 1 cuon sach" << endl;
        cout << "Khac. Hoan thanh thay doi" << endl;
        cout << "Ban chon: ";
        cin >> chon;
        switch (chon)
        {
        case 1:
            remove_type();
            sum_total();
            break;
        case 2:
            remove_qtt();
            sum_total();
            break;
        default:
            cout << "Hoan thanh!" << endl;
            break;
        }
    } while (chon == 1 || chon == 2);
}

// xuat don hang
void order::display()
{
    int daco = set_info();
    int discount = 0;
    cout << "------------------------------------------------------------" << endl;
    cout << setw(50) << "HOA DON CUA BAN: " << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Ma hoa don: " << this->order_id << endl;
    cout << "Ngay mua: ";
    d.set_time();
    d.display();
    cout << "------------------------------------------------------------" << endl;
    cout << endl;
    cout << setw(20) << left << "Ma nhan vien:  " << this->id_emp << endl;
    if (daco == 1)
    {
        cout << setw(20) << left << "Ma khach hang: "
             << "KH" << this->sdt_cus << endl;
    }
    else
    {
        cout << setw(20) << left << "Ten khach hang: " << this->name_cus << endl;
        cout << setw(20) << left << "SDT khach hang: " << this->sdt_cus << endl
             << endl;
    }
    cout << setw(20) << "So loai sach: " << so_loai << endl;
    cout << setw(20) << "ID"
         << "So luong" << endl;
    for (int i = 0; i < so_loai; i++)
    {
        cout << setw(20) << book_sold[i].get_book_id() << book_sold[i].get_book_qtt() << endl;
    }

    Save s;
    s.setOrder_id(order_id);
    s.setDate(d);
    s.setSave(book_sold);
    s.settSdt_cus(sdt_cus);
    s.setEmp_id(id_emp);
    saveOrder.push_back(s);

    int sum = sum_total();

    if (daco == 1)
    {
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].get_phone_num() == sdt_cus)
            {
                if (customers[i].get_point() >= 50)
                {
                    discount = sum * 0.05;
                }
                customers[i].re_point(sum / 100000);
                break;
            }
        }
    }
    change(sum - discount);

    cout << setw(20) << "Tong tien: " << sum << "VND" << endl;
    cout << setw(20) << "Tien nhan: " << pay_money << "VND" << endl;
    if (discount > 0)
    {
        cout << setw(20) << "Giam gia: " << discount << "VND" << endl;
    }
    cout << setw(20) << "Tien thua: " << change_money << "VND" << endl;
    cout << setw(20) << "XIN CAM ON <3" << endl;
}

void order::allthing()
{
    while (true)
    {
        // system("cls");
        order o;
        int chon;
        cout << "Tao don hang moi" << endl;
        o.create();
        o.choose();
        o.display();

        for (int i = 0; i < o.so_loai; i++)
        {
            solds[o.book_sold[i].get_book_id()] = o.book_sold[i].get_book_qtt();
        }

        cout << endl
             << "Ban muon tao 1 don hang moi khong??" << endl;
        cout << "Chon 1 de tao, phim bat ki ket thuc" << endl;
        cout << "Ban chon: ";
        cin >> chon;
        if (chon != 1)
        {
            break;
        }
    }
    decrease_store();

    thay_doi_tep_save();
    thay_doi_tep_books();
}

void order::decrease_store()
{
    for (int i = 0; i < books.size(); i++)
    {
        int qtt_old = books[i].get_quantity();
        int qtt_new = qtt_old - solds[books[i].get_id()];
        books[i].set_quantity(qtt_new);
    }
}
