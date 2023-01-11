#include "employee.h"

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