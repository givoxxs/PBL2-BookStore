#include "Person.h"
#include<iostream>
using namespace std;

class customer : public person {
private:
    string address;
public:
    customer();
    customer(int id, string name, string phone_number, string address);
    ~customer();
    string get_address();
    customer add();
    void display() const;
    customer re_address();
};
