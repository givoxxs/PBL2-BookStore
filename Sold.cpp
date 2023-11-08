#include "Sold.h"
#include <iostream>
using namespace std;

sold::sold() {}

sold::sold(int book_id, int book_qtt)
{
    this->book_id = book_id;
    this->book_qtt = book_qtt;
}

sold::~sold() {}

int sold::get_book_id()
{
    return this->book_id;
}

int sold::get_book_qtt()
{
    return this->book_qtt;
}

void sold::set_book_id(int book_id)
{
    this->book_id=book_id;
}

void sold::set_book_qtt(int book_qtt)
{
    this->book_qtt = book_qtt;
}
