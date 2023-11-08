#include "Order.h"
#include "Book.h"
#include "Date.h"
#include "Sold.h"
#include "Prepare.h"
#include "Save.h"
#include <iostream>
#include<iomanip>
#include<string>
#include <vector>
using namespace std;

// ham dung
order::order() {}
order::order(int id_emp, string id_cus, int so_loai, int pay_money, vector<sold> book_sold, Date d)
{
    this->id_emp=id_emp;
    this->id_cus = id_cus;
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
    change();
}

// tien thua
void order::change()
{
    this->change_money = this->pay_money - sum_total();
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
        cin >>x;
        a.set_book_id(x);
        cout << "So luong: ";
        int y;
        cin >> y;
        a.set_book_qtt(y);
        book_sold.push_back(a);
    }

    return *this;
}

int order::set_info() {
    int chon;
    getchar();
    cout<<"Nhap ID nhan vien: ";
    getline(cin,id_emp);
    cout<<"Khach hang da co the thanh vien ?"<<endl;
    cout<<"Nhan 1 neu co, 0 neu chua: ";
    cin>>chon;
    if(chon==1) {
        getchar();
        cout<<"Nhap vao ID cua ban: ";
        getline(cin,id_cus);
        return 1;
    } else {
        char chon;
        cout<<"Co muon tao the thanh vien khong?"<<endl;
        cout<<"Nhan Y neu muon, N neu khong: ";
        cin>>chon;
        getchar();
        if(chon == 'Y' || chon == 'y') {
            customer::add_new_cus();  
            int temp= customers.size()-1; 
            this->id_cus = customers[temp].get_id();
            return 1; 
        } else if(chon == 'N' || chon =='n') {
            cout<<"Ten khach hang: ";
            getline(cin, this->name_cus);
            cout<<"SDT khach hang: ";
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
        cout<<"Tong tien: "<<sum_total()<<endl;
            cout << "Tien nhan cua khach: ";
            pay();
            break;
        case 2:
            remove();
            cout << "Tong tien con lai: " << sum_total() << endl;
            break;
        default:
            cout << "Lua chon sai. Vui long nhap lai." << endl;
            break;
        }
    } while (chosen !=1);
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
    cout << "Ban muon xoa bao nhieu quyen: ";
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
    cout<<"------------------------------------------------------------"<<endl;
    cout <<setw(50)<<"HOA DON CUA BAN: " << endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout << "Ngay mua: ";
    d.set_time();
    d.display();
    cout<<"------------------------------------------------------------"<<endl;
    cout << endl;
    cout<<"ID nhan vien: "<<setw(20)<<this->id_emp<<endl;
    if(daco==1) {
        cout<<"ID khach hang: "<<setw(20)<<this->id_cus<<endl;
    } else {
        cout<<"Ten khach hang: "<<setw(20)<<this->name_cus<<endl;
        cout<<"SDT khach hang: "<<setw(20)<<this->sdt_cus<<endl<<endl;
    }
    cout << "So loai sach: "<<setw(20)<< so_loai << endl;
    cout<<"ID"<<setw(20)<<"So luong"<<endl;
    for (int i = 0; i < so_loai; i++)
    {
        cout << book_sold[i].get_book_id() <<setw(20)<< book_sold[i].get_book_qtt()<< endl;
    }
    
    Save s;
    s.setDate(d);
    s.setSave(book_sold);
    s.setEmp_id(id_emp);
    saveOrder.push_back(s);

    int sum = sum_total();
    cout << "Tong tien: " << sum << endl;
    cout << "Tien nhan: " << pay_money << endl;
    cout << "Tien thua: " << change_money << endl;
    cout << "XIN CAM ON <3" << endl;
}

void order::allthing() {
    while (true) {
        // system("cls");
        order o;
        int chon;
        cout << "Tao don hang moi" << endl;
        o.create();
        o.choose();
        o.display();
       
        for(int i=0;i<o.so_loai;i++) {
            solds[o.book_sold[i].get_book_id()] = o.book_sold[i].get_book_qtt();
        }
        
        cout <<endl<< "Ban muon tao 1 don hang moi khong??" << endl;
        cout << "Chon 1 de tao, phim bat ki ket thuc" << endl;
        cout << "Ban chon: ";
        cin >> chon;
        if (chon != 1) {
            break; 
        }
    }
    decrease_store();

}

void order::decrease_store() {
    for(int i=0;i<books.size();i++) {
        int qtt_old = books[i].get_quantity();
        int qtt_new = qtt_old - solds[books[i].get_id()];
        books[i].set_quantity(qtt_new);
    }
}