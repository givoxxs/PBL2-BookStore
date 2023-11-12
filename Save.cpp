#include "Save.h"
#include "Prepare.h"
#include <iostream>
using namespace std;

Save::Save() {}

Save::Save(string order_id, Date d, string id, string sdt_cus, vector<sold> s)
{
    this->order_id = order_id;
    this->d = d;
    this->emp_id = id;
    this->sdt_cus = sdt_cus;
    this->save = s;
}
void Save::setOrder_id(std::string order_id) {
    this->order_id = order_id;
}

void Save::setDate(Date d)
{
    this->d = d;
}

void Save::setSave(vector<sold> s)
{
    this->save = s;
}

void Save::setEmp_id(string id)
{
    this->emp_id = id;
}
void Save::settSdt_cus(std::string sdt)
{
    this->sdt_cus = sdt;
}

void Save::display()
{
    cout << "Ma hoa don: " << this->order_id << endl;
    cout << "Thoi gian giao dich: ";
    d.display();
    cout << "ID nhan vien thuc hien giao dich: " << this->emp_id << endl;
    cout << "SDT khach hang: " << this->sdt_cus << endl;
    cout << "ID"
         << "       "
         << "So luong" << endl;
    for (int i = 0; i < save.size(); i++)
    {
        cout << save[i].get_book_id() << "            " << save[i].get_book_qtt() << endl;
    }
    cout << "====================================================" << endl;
}

void Save::display_All()
{
    for (int i = 0; i < saveOrder.size(); i++)
    {
        saveOrder[i].display();
    }
}

Date Save::getDate()
{
    return this->d;
}
string Save::getEmp_id()
{
    return this->emp_id;
}

string Save::getSdt_cus()
{
    return this->sdt_cus;
}

vector<sold> Save::getSave()
{
    return this->save;
}

string Save::getOrder_id()
{
    return this->order_id;
}