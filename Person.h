#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include <vector>

class person
{
protected:
    std::string id;
    std::string name;
    std::string phone_number;
    int year_of_birthday;

public:
    person();
    person(std::string id, std::string name, std::string phone_num, int year_of_birth);
    ~person();
    std::string no_space(std::string s);

    std::string get_id();
    std::string get_name();
    std::string get_phone_num();
    int get_year_of_birthday();

    void search_name(std::string abc);
    virtual void re_phone_num();

    virtual void display() = 0;
};
#endif