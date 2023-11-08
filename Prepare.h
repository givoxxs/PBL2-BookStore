#ifndef PRE_H
#define PRE_H
#include "Book.h"
#include "Person.h"
#include "Customer.h"
#include "Employee.h"
#include "Sold.h"
#include "Save.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <sstream>

extern std::vector<Book> books;
extern std::vector<customer> customers;
extern std::vector<employee> employees;
extern int solds[100];
extern std::vector<Save> saveOrder;

void create_book_list();
void create_cus_list();
void create_emp_list();
void create_sold_list();
void create_save_list();
void thay_doi_tep_books();
void thay_doi_tep_customers();
void thay_doi_tep_employees();
void thay_doi_tep_save();
#endif
