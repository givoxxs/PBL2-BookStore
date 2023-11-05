#ifndef PERSON_H
#define PERSON_H

#include <bits/stdc++.h>
#include <string>

class Person {
protected:
    std::string Name;
    std::string PhoneNumber;
    int Year_of_birthday;

public:
    Person(){};
    Person(std::string name, std::string PhoneNumber, int Year_of_birthday) : Name(name), PhoneNumber(PhoneNumber), Year_of_birthday(Year_of_birthday){};
    Person(const Person &P);
    virtual ~Person() {}

    static std::string no_space(const std::string s);

    void setName(std::string name);
    std::string getName() const;
    void setPhoneNumber(std::string PhoneNumber);
    std::string getPhoneNumber() const;
    void setYear_of_birthday(int Year_of_birthday);
    int getYear_of_birthday() const;
};

#endif
