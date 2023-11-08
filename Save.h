#ifndef SAVE_H
#define SAVE_H
#include "Date.h"
#include "Sold.h"
#include<iostream>
#include<vector>

class Save {
    private:    
        Date d;
        std::string emp_id;
        std::vector<sold> save;
    public:
        Save();
        Save(Date d, std::string id, std::vector<sold> );
        void setDate(Date );
        void setSave(std::vector<sold> );
        void setEmp_id(std::string );
        Date getDate();
        std::string getEmp_id();
        std::vector<sold> getSave();
        void display();
        static void display_All();
};
#endif