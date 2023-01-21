#include "employee.h"
#include <regex>

vector<Employee> Employee::employees{};

void Employee::display_all(void){
    short counter=1;
    for(Employee &employee: employees){
        cout << "Employee " << counter++ << ":-\n";
        cout << "Name: " << employee.name << endl;
        cout << "ID: " << employee.id << endl;
        cout << "Job: " << employee.job << endl;
        cout << "Salary: " << employee.salary << endl;
        cout << endl;
    }
}

void  Employee::display(vector<Employee> &emps){
    short counter=1;
    for(Employee &employee: emps){
        cout << "Employee " << counter++ << ":-\n";
        cout << "Name: " << employee.name << endl;
        cout << "ID: " << employee.id << endl;
        cout << "Job: " << employee.job << endl;
        cout << "Salary: " << employee.salary << endl;
        cout << endl;
    }
}

void Employee::add(void){
    string name,id,job;
    int salary{};

    cout << "Name: ";
    cin >> name;

    cout << "ID: ";
    cin >> id;

    cout << "Job: ";
    cin >> job;

    cout << "Salary: ";
    cin >> salary;

    Employee new_epmloyee(name,id,job,salary);
    employees.push_back(new_epmloyee);

}

void Employee::remove(int index){
    index--; // to make it zero-based index
    swap(employees[index], employees.back());
    employees.pop_back();
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

    for(Employee &emp: employees){
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