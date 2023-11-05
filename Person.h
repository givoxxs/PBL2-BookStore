#ifndef PERSON_H
#define PERSON_H
#include <bits/stdc++.h>
#include <string>
using namespace std;
class Person {
    protected: 
        string Name;
        string PhoneNumber;
        int Year_of_birthday;
    public:
        Person(){};
        Person(string name,string PhoneNumber,int Year_of_birthday):Name(name),PhoneNumber(PhoneNumber),Year_of_birthday(Year_of_birthday){};
        Person(const Person &P);
        virtual ~Person(){}

        static string no_space(const string s);

        void setName(string name);
        string getName() const;
        void setPhoneNumber(string PhoneNumber);
        string getPhoneNumber() const;
        void setYear_of_birthday(int Year_of_birthday);
        int getYear_of_birthday() const;
};
#endif

