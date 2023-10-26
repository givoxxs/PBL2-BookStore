#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<string>
using namespace std;
class person {
protected: 
    int id;
    string name;
    string phone_number;
    void search_id();
    void search_phone_number();
public:
    person();
    person(int id, string name, string phone_number);
    ~person();
    int get_id();
    person add();
    void display() const;
    void search();
    person re_phone_number();
};
#endif