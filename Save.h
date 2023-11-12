#ifndef SAVE_H
#define SAVE_H
#include "Date.h"
#include "Sold.h"
#include<iostream>
#include<vector>

class Save {
    private:   
        std::string order_id; 
        Date d;
        std::string emp_id;
        std::string sdt_cus;
        std::vector<sold> save;
    public:
        Save();
        Save(std::string order_id, Date d, std::string id, std::string sdt_cus, std::vector<sold> );
        void setOrder_id(std::string );
        void setDate(Date );
        void setSave(std::vector<sold> );
        void setEmp_id(std::string );
        void settSdt_cus(std::string );
        Date getDate();
        std::string getEmp_id();
        std::string getSdt_cus();
        std::string getOrder_id();
        std::vector<sold> getSave();
        void display();
        static void display_All();
};
#endif