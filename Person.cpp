#include <bits/stdc++.h>
#include "Person.h"
#include "Day.h"

using namespace std;

Person::Person(const Person &P)
{
    this->Name=P.Name;
    this->PhoneNumber=P.PhoneNumber;
    this->Year_of_birthday=P.Year_of_birthday;
}
// virtual Person::~Person() {}
void Person::setName(string name)
{
    this->Name=name;
}
string Person::getName() const
{
    return Name;
}
void Person::setPhoneNumber(string PhoneNumber)
{
    this->PhoneNumber=PhoneNumber;
}
string Person::getPhoneNumber() const
{
    return PhoneNumber;
}
void Person::setYear_of_birthday(int Year_of_birthday) {
    this->Year_of_birthday = Year_of_birthday;
}
int Person::getYear_of_birthday() const {
    return Year_of_birthday;
}
