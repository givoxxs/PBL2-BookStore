#include "Save.h"
#include "Prepare.h"
#include <iostream>
using namespace std;

Save::Save() {}

Save::Save(Date d, string id, vector<sold> s) {
    this->d = d;
    this->emp_id = id;
    this->save = s;
}

void Save::setDate(Date d) {
    this->d = d;
}

void Save::setSave(vector<sold> s ) {
    this->save = s;
}

void Save::setEmp_id(string id) {
    this->emp_id = id;
}

void Save::display() {
    cout<<"Thoi gian giao dich: ";
    d.display();
    cout<<"ID nhan vien thuc hien giao dich: "<<this->emp_id<<endl;
    cout<<"ID"<<"       "<<"So luong"<<endl;
    for(int i=0;i<save.size();i++) {
        cout<<save[i].get_book_id()<<"            "<<save[i].get_book_qtt()<<endl;
    }
    cout<<"===================================================="<<endl;
}

void Save::display_All() {
    for(int i=0;i<saveOrder.size();i++) {
        saveOrder[i].display();
   }
}

Date Save::getDate() {
    return this->d;
}
string Save::getEmp_id() {
    return this->emp_id;
}
vector<sold> Save::getSave() {
    return this->save;
}