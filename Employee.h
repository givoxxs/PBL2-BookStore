#ifndef EMP_H
#define EMP_H
#include "Person.h"
#include <iostream>

class employee : public person
{
private:
    std::string CICard;
    std::string address;
    int wage;

public:
    employee();
    employee(std::string id, std::string name, std::string phone_number, int wage, std::string cic, std::string address, int yob);
    ~employee();

    std::string get_CI();
    std::string getAddress();
    float get_wage();

    void set_wage(float wage);
    void set_address(std::string address);
    static void re_wage();
    static void re_phone();
    static void re_address();

    employee add();
    static void add_new_emp();

    void display();
    static void display_All();

    void search_wage(float abc);
    static void search();
    static void change();

};
#endif
