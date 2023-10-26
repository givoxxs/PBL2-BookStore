#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class person {
protected: 
    int id;
    string name;
    string phone_number;
public:
    person();
    person(int id, string name, string phone_num);
    ~person();
    static string no_space(const string s);

    int get_id();
    string get_name();
    string get_phone_num();

    static void search_name(string abc, vector<person> people);
    static void search_phone_num(string abc, vector<person> people);
    void re_phone_num();

    virtual void display() = 0;
    // virtual void search() = 0;
};
#endif