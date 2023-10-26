#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Person.h"
#include<iostream>
#include<vector>
using namespace std;

class customer : public person {
private:
    string address;
public:
    customer();
    customer(int id, string name, string phone_number, string address);
    ~customer();
    string get_address();
    customer &add();
    void display();
    static void display_All(vector<customer> customers);
    static void re_address(vector<customer> &customers);
    static void re_phone(vector<customer> &customers);
};
#endif