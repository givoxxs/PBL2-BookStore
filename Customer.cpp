#include "Customer.h"
#include "Prepare.h"
#include "MyLib.h"
#include "CustomerLib_Menu.h"
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

customer::customer() {}

customer::customer(string id, string name, string phone_number, int year_of_birthday, int point) : person(id, name, phone_number, year_of_birthday)
{
    this->point = point;
}

customer::~customer() {}

int customer::get_point()
{
    return point;
}

void customer::set_point(int x) {
    this->point = x;
}

customer customer::add()
{
    int max =  customers.size()+1;
    string temp = "KH" + to_string(max);
    this->id = temp;
    int x = 80, y = 5, h =2;
    system("cls");
    bar_Add_Customer();
    gotoXY(x + 8, y + 1);   cout << temp;
    getchar();
    gotoXY(x + 12, y + 3);  
    getline(cin, name);
    gotoXY(x + 16, y + 5);
    getline(cin, phone_number);
    gotoXY(x + 11, y + 7);
    cin>>year_of_birthday;
    this->point = 0;
    gotoXY(x , y + 13);
    return *this;
}

void customer::add_new_cus()
{
    customer newcus;
    newcus.add();
    customers.push_back(newcus);

    ofstream inventoryFile("customers.txt", ios::app);

    if (!inventoryFile)
    {
        cerr << "Khong the mo customers.txt de ghi du lieu." << endl;
        return;
    }
    inventoryFile << newcus.get_id() << ","
                  << newcus.get_name() << ","
                  << newcus.get_phone_num() << ","
                  << newcus.get_year_of_birthday() << ","
                  << newcus.get_point()<<endl;
    inventoryFile.close();
    cout << "Khach hang da duoc them vao." << endl;
    gotoXY(80 , 5 + 15);
    system("pause");
}

void customer::display()
{
    cout << setiosflags(ios::left) << setw(8) << id;
    cout << setw(30) << name;
    cout << setw(20) << phone_number;
    cout << setw(13) << year_of_birthday;
    cout << setw(10) << point << endl;
}

void customer::display_All()
{
    cout << setiosflags(ios::left) << setw(8) << "ID";
    cout << setw(30) << "Ten Khach hang";
    cout << setw(20) << "So dien thoai";
    cout << setw(10) << "Nam sinh";
    cout << setw(13) << "Diem tich luy";
    cout << endl << endl;

    for (int i = 0; i < customers.size(); i++)
    {
        customers[i].display();
        cout << endl;
    }
}

void customer::re_phone()
{   
    int x = 70, y = 14;
    bar_Change();
    string thay_doi = "";
    gotoXY(x + 15, y + 1);
    cin >> thay_doi;

    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].id == thay_doi)
        {   
            gotoXY(x + 9, y + 3);
            customers[i].re_phone_num();
            gotoXY(x, y + 7);
            cout << "Thay doi thanh cong!!!" << endl;
            gotoXY(x, y + 8);
            return;
        }
    }
    thay_doi = "";
    gotoXY(x, y + 7);
    cout << "Thay doi chua thanh cong!!!" << endl;
    gotoXY(x, y + 8);
}

void customer::search()
{
    int choose, n  = 3;
    string nd[n], nd1;
    nd[0] = "Tim voi TEN / Search by Name";
    nd[1] = "Tim voi So dien thoai / Search by Phone Number";
    nd[2] = "THOAT / EXIT";
    nd1 = "         TUY CHON TIM KIEM / CHANGE OPTIONS";

    do {
        system("cls");
        box(70 - 2, 5 - 2, 50 + 4, 2 + 12, 11, 75, nd1);
        choose = Menu(70, 5, 50, 2, 11, 75, nd, n);
        std::string searching = "";
        switch (choose) {
            case 0:
                searching = bar_Search_Customer("Ten Khach hang");
                for (int i = 0; i < customers.size(); i++)
                {
                    customers[i].search_name(searching);
                }
                system("pause");
                break;
            case 1:
                searching = bar_Search_Customer("So dien thoai");
                for (int i = 0; i < customers.size(); i++)
                {
                    customers[i].search_phone(searching);
                }
                system("pause");
                break;
            case 2:
                break;
        }
    }   while (n - choose - 1);
}
void customer::search_phone(string abc)
{
    if (get_phone_num().find(abc) != string::npos)
    {
        this->display();
        cout << endl;
    }
}
void customer::change() {
    // int choose, n = 2;
    // string 
    int chon = 0;
    string abc;
    cout << "1. Thay doi diem tich luy" << endl;
    cout << "2. Thay doi so dien thoai" << endl;
    cout << "Nhap lua chon cua ban: ";
    cin >> chon;
    getchar();
    
    switch (chon)
    {
    case 1:
        // customer::re_point();
        break;
    case 2:
        customer::re_phone();
        break;
    default:
        cout << "Lua chon sai!!!";
        break;
    }

}

void customer::re_point(int new_point)
{
    this->point += new_point;
}


void customer::order_history() {
    string check;
    bool co = false;
    cout<<"SDT khach hang: ";
    // getchar();
    cin>>check;
    cout<<"==================================================="<<endl;
    int size = saveOrder.size() - 1;
    for(int i=0;i<size;i++) {
        if(saveOrder[i].getSdt_cus() == check) {
            saveOrder[i].display();
            co = true;
        }
    }
    if(!co) {
        cout<<"Khong tim thay lich su giao dich!!!"<<endl;
    }
}