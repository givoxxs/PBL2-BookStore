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
    int get_wage();

    void set_wage(int wage);
    void set_address(std::string address);
    static void re_wage();
    static void re_phone();
    static void re_address();

    employee add();
    static void add_new_emp();

    void display();
    static void display_All();

    void search_wage(int abc);
    static void search();
    static void change();
    static void delete_emp();
    int get_number(std::string );

};
#endif
