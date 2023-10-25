#include "Person.h"
#include<iostream>
using namespace std;

class employee : public person {
private:
    int salary;
public:
    employee();
    employee(int id, string name, string phone_number, int salary);
    ~employee();
    int get_salary();
    employee add();
    void display() const;
    employee re_salary();
};
