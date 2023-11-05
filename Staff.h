#ifndef Staff_h
#define Staff_h
#include "Person.h"

using namespace std;

class Staff : public Person{
    private:
        string IDStaff;
        string CICard; // can cuoc cong dan
        string Address;
        string Email;
        float Wage; // tien cong (luong)
    public:
        Staff(){};
        Staff(string IDStaff,string name,string sdt,int ngaysinh,string CICard,
    string Address,string Email,float Wage):Person(name,sdt,ngaysinh)
    ,IDStaff(IDStaff),CICard(CICard),Address(Address),Email(Email),Wage(Wage){};
        ~Staff(){};

        string get_IDStaff();
        string get_CICard();
        string get_Address();
        string get_Email();
        float get_Wage();

        static void Add(vector<Staff> &Staff_Data);
        // void Search();
        void display() const;
        static void displayAll(vector<Staff> Staff_Data);

        static string no_space(const string s);

        static void search(vector<Staff> Staff_Data);
        static void search_name(string abc, vector<Staff> Staff_Data);
        static void search_wage(float abc, vector<Staff> Staff_Data);

        static bool CheckID(string s, vector<Staff> Staff_Data) {
            for (int i=0; i<Staff_Data.size(); i++) {
                    if (Staff_Data[i].get_IDStaff() == s) {
                        cout << "Ma nhan vien trung lap!!! Nhap lai.\n";
                        return true;
                    };
                }

                return false;
        }
};

#endif // Staff_h

