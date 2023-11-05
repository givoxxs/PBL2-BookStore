#include <bits/stdc++.h>
#include "Person.h"
#include "Day.h"

Person::Person(const Person &P) {
    this->Name = P.Name;
    this->PhoneNumber = P.PhoneNumber;
    this->Year_of_birthday = P.Year_of_birthday;
}

// virtual Person::~Person() {}

void Person::setName(std::string name) {
    this->Name = name;
}

std::string Person::getName() const {
    return Name;
}

void Person::setPhoneNumber(std::string PhoneNumber) {
    this->PhoneNumber = PhoneNumber;
}

std::string Person::getPhoneNumber() const {
    return PhoneNumber;
}

void Person::setYear_of_birthday(int Year_of_birthday) {
    this->Year_of_birthday = Year_of_birthday;
}

int Person::getYear_of_birthday() const {
    return Year_of_birthday;
}
