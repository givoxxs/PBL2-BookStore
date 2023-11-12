#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Person.h"
#include <iostream>
#include <vector>

class customer : public person
{
private:
    int point;

public:
    customer();
    customer(std::string id, std::string name, std::string phone_number, int get_year_of_birthday, int point);
    ~customer();
    int get_point();
    void set_point(int x);
    customer add();
    static void add_new_cus();
    void display();
    static void display_All();
    static void re_point();
    static void re_phone();
    void search_phone(std::string abc);
    static void search();
    static void change();
};
#endif
