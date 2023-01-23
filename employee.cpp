#include "employee.h"
#include <regex>

vector<Employee> Employee::all_employees{};

Employee::Employee(string _name, string _id, string _job, int _salary):
    name{_name},
    id{_id},
    job{_job},
    salary{_salary}
{};

void Employee::display_all(void){
    short counter=1;
    for(Employee &employee: all_employees){
        cout << "Employee " << counter++ << ":-\n";
        cout << "Name: " << employee.name << endl;
        cout << "ID: " << employee.id << endl;
        cout << "Job: " << employee.job << endl;
        cout << "Salary: " << employee.salary << endl;
        cout << endl;
    }
}

void Employee::display(void){
    cout << "Employee:\n";
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Job: " << job << endl;
    cout << "Salary: " << salary << endl;
    cout << endl;
}

void Employee::add(Employee &emp){

    all_employees.push_back(emp);
}

void Employee::remove(void){

    for(Employee &emp: all_employees){
        if (emp.id == this->id){
            swap(emp, all_employees.back());
            all_employees.pop_back();
        }
    }
}

void Employee::search_menu(void){
    system("clear");
    cout << "1. Search by name (full name or part of it)\n";
    cout << "2. Search by ID\n";
    cout << "3. Search by job (write part of the job title)\n";
}

vector<Employee> Employee::search(Employee_Search_Type search_by, string parameter){
    vector<Employee> result;

    regex expr("(.*)"+parameter+"(.*)");

    for(Employee &emp: all_employees){
        switch (search_by)
        {
        case Name:
            if(regex_search(emp.name, expr)){
                result.push_back(emp);
            }
            break;
        case ID:
            if(emp.id == parameter){
                result.push_back(emp);
            }
            break;
        
        case Job:
            if(regex_search(emp.job, expr)){
                result.push_back(emp);
            }
            break;
        }
    }

    return result;
}