#include "Person.h"
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

string person::no_space(const string s) {
    string result = "";
        for (char c : s) {
            if (c != ' ') {
                result += tolower(c);
            }
        }   
    return result;
}


person::person() {}
person::person(int id, string name, string phone_number):id(id),name(name),phone_number(phone_number) {}
person::~person() {}

int person::get_id() {
    return this->id;
}

string person::get_name() {
    return this->name;
}

string person::get_phone_num() {
    return this->phone_number;
}

void person::search_name(string abc, vector<person> people) {

    for(int i=0;i<people.size();i++) {
        if(no_space(abc)==no_space(people[i].name)) {
            people[i].display();
        }
    }
}

void person::search_phone_num(string abc, vector<person> people) {

    for(int i=0;i<people.size();i++) {
        if(no_space(abc)==no_space(people[i].phone_number)) {
            people[i].display();
        }
    }
}

void person::re_phone_num() {
    getline(cin, phone_number);
}   
