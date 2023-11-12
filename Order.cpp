#include "Order.h"
#include "Book.h"
#include "Date.h"
#include "Sold.h"
#include "Prepare.h"
#include "Save.h"
#include "Mylib.h"
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
    int x = 20;
    int y = whereY();
    box(x,y,20,2,11, 75, "So loai sach: "); 
    SetColor(15);
    gotoXY(x + 15, y + 1);  cin >> this->so_loai;
    int n = this->so_loai;
    y = y + 3;
    string nd[n];
    for (int i =0 ;i < n; i++)  nd[i] = "Book";
    MulBox(x, y, 40, 2, 7, 15,nd, n);
    // Tạo bảng mẫu
    for (int i = 0; i<n ; i++) {
        gotoXY(x + 6, y + 2*i + 1);     cout << i + 1 << " : ";
        gotoXY(x + 10, y + 2*i + 1);    cout << "ID = ";
        gotoXY(x + 20, y + 2*i + 1);    cout << "| So luong = ";
    }
    // Điền thông tin
    for (int i = 0; i<n ; i++) {
        SetColor(15);
        sold a;
        int id, qtt;
        gotoXY(x + 10 + 6, y + 2*i + 1);    cin >> id;
        a.set_book_id(id);
        gotoXY(x + 20 + 13, y + 2*i + 1);   cin >> qtt;
        a.set_book_qtt(qtt);
        book_sold.push_back(a);
    }
    gotoXY(x, y + 2*n + 1);

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
    int x = 20; 
    int y = whereY();
    int choose, n = 2;
    string nd[n];
    nd[0] = "Tinh tien";
    nd[1] = "Thay doi gio hang";
    

    do {
        //system("cls");
        gotoXY(20, 3);
        box(x, y, 30 + 4, 2 + 5, 11, 75, "\tBan chon?") ;
        choose = Menu(x + 2, y + 2, 30, 2, 11, 75, nd, n);
        gotoXY(x, y + 7);
        cout << endl;
        switch (choose) {
            case 0: 
                SetColor(15);
                y = whereY();
                gotoXY(x, y+2);
                cout << "Tong tien: " << sum_total() << " VND";
                gotoXY(x ,y+3);
                cout << "Tien nhan cua khach (don vi: VND): ";          
                pay();
                y = y + 4;
                gotoXY(x, y);
                break;
            case 1:
                SetColor(15);
                y = whereY();
                gotoXY(x, y+1);
                remove();
                y = whereY() + 1;
                gotoXY(x, y);
                cout << "Tong tien con lai: " << sum_total() << " VND" << endl;
                y++;
                gotoXY(x, y);
                break;
        }
    } while (choose != 0);
}

// xoa 1 loai sach khoi don hang
order order::remove_type()
{
    int dlt_id;
    cout << "---------------------------------------------" << endl;
    cout << "\tNhap vao ID sach ban muon xoa khoi don hang: ";
    cin >> dlt_id;
    bool found = false;
    for (int i = 0; i < so_loai; i++)
    {
        if (book_sold[i].get_book_id() == dlt_id)
        {
            book_sold.erase(book_sold.begin() + i);
            so_loai--;
            found = true;
            cout << "\tXoa thanh cong!!" << endl;
            cout << "---------------------------------------------" << endl;
            break;
        }
    }

    if (!found)
    {   
        cout << "\tKhong tim thay sach co ID " << dlt_id << " trong don hang." << endl;
        cout << "---------------------------------------------" << endl;
    }

    return *this;
}

// giam so luong 1 cuon sach
order order::remove_qtt()
{   
    int dlt_id, qtt;
    cout << "---------------------------------------------" << endl;
    cout << "\tNhap vao ID sach ban muon thay doi so luong: ";
    cin >> dlt_id;
    cout << "\tSo luong muon giam: ";
    cin >> qtt;
    bool found = false;
    for (int i = 0; i < so_loai; i++)
    {
        if (book_sold[i].get_book_id() == dlt_id)
        {
            int qtt_old = book_sold[i].get_book_qtt();
            book_sold[i].set_book_qtt(qtt_old - qtt);
            found = true;
            cout << "\tThay doi thanh cong!!" << endl;
            cout << "---------------------------------------------" << endl;
            break;
        }
    }

    if (!found)
    {
        cout << "\tKhong tim thay sach co ID " << dlt_id << " trong don hang." << endl;
        cout << "---------------------------------------------" << endl;
    }

    return *this;
}

void order::remove()
{
    int chon, n = 3;
    int x = 20;
    int y = whereY();
    string nd[n] ;
    nd[0] = "Xoa 1 cuon sach khoi don hang";
    nd[1] = "Thay doi so luong 1 cuon sach";
    nd[2] = "Thoat!";
    do
    {   
        // system("cls");
        chon = Menu(x + 2, y + 1, 30, 2, 11, 75, nd, n);
        gotoXY(x, y + 1 + 7);
        cout << endl;
        switch (chon)
        {
        case 0:
            y = whereY();
            gotoXY(x,y);
            remove_type();
            y = whereY() + 1;
            gotoXY(x, y);
            sum_total();
            y = whereY() + 1;
            gotoXY(x, y);
            break;
        case 1:
            y = whereY();
            gotoXY(x,y);
            remove_qtt();
            y = whereY() + 1;
            gotoXY(x, y);
            sum_total();
            y = whereY() + 1;
            gotoXY(x, y);
            break;
        case 2:
            break;
        }
    } while (n - chon - 1);
}

// xuat don hang
void order::display()
{   
    int x = 20;
    int y = whereY() + 2;
    gotoXY(x,y);
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
        //cout << "Tao don hang moi" << endl;
        o.create(); // done
        o.choose(); // pending
        o.display();
        int x = 20;
        int y = whereY() + 2;
        gotoXY(x,y);
        for (int i = 0; i < o.so_loai; i++)
        {
            solds[o.book_sold[i].get_book_id()] = o.book_sold[i].get_book_qtt();
        }
        cout << "---------------------------------------------" << endl;
        cout << endl
             << "Ban muon tao 1 don hang moi khong??" << endl << endl;
        cout << "Chon 1 de tao, phim bat ki ket thuc" << endl << endl; 
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
