#ifndef Staff_h
#define Staff_h
#include "Person.h"
#include <vector>
#include <string>

class Staff : public Person {
private:
    std::string IDStaff;
    std::string CICard; // can cuoc cong dan
    std::string Address;
    std::string Email;
    float Wage; // tien cong (luong)

public:
    Staff(){};
    Staff(std::string IDStaff, std::string name, std::string sdt, int ngaysinh, std::string CICard,
        std::string Address, std::string Email, float Wage) : Person(name, sdt, ngaysinh),
                                                           IDStaff(IDStaff), CICard(CICard), Address(Address), Email(Email), Wage(Wage){};
    ~Staff(){};

    std::string get_IDStaff();
    std::string get_CICard();
    std::string get_Address();
    std::string get_Email();
    float get_Wage();

    static void Add(std::vector<Staff> &Staff_Data);
    // void Search();
    void display() const;
    static void displayAll(std::vector<Staff> Staff_Data);

    static std::string no_space(const std::string s);

    static void search(std::vector<Staff> Staff_Data);
    static void search_name(std::string abc, std::vector<Staff> Staff_Data);
    static void search_wage(float abc, std::vector<Staff> Staff_Data);

    static bool CheckID(std::string s, std::vector<Staff> Staff_Data) {
        for (int i = 0; i < Staff_Data.size(); i++) {
            if (Staff_Data[i].get_IDStaff() == s) {
                std::cout << "Ma nhan vien trung lap!!! Nhap lai.\n";
                return true;
            }
        }

        return false;
    }
};

#endif // Staff_h
