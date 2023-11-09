#include "Person.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string person::no_space(const string s)
{
    string result = "";
    for (char c : s)
    {
        if (c != ' ')
        {
            result += tolower(c);
        }
    }
    return result;
}

person::person() {}
person::person(string id, string name, string phone_number, int yob) : id(id), name(name), phone_number(phone_number),year_of_birthday(yob) {}
person::~person() {}

string person::get_id()
{
    return this->id;
}

string person::get_name()
{
    return this->name;
}

string person::get_phone_num()
{
    return this->phone_number;
}

int person::get_year_of_birthday()  {
    return year_of_birthday;
}

void person::search_name(string abc)
{
    if (no_space(get_name()).find(no_space(abc)) != string::npos) 
    {
        this->display();
        cout << endl;
    }
}



void person::re_phone_num()
{   
    getchar();
    getline(cin, phone_number);
}
