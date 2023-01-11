#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee{
public:
    string name{};
    string id{};
    string job{};
    int salary{};
    static vector<Employee> employees;

    Employee(string _name, string _id, string _job, int _salary):
        name{_name},
        id{_id},
        job{_job},
        salary{_salary}
    {};

    void static display_all(void);
    void static add(void);
    void static remove(int index);
    
};
