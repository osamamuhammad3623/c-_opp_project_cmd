#include <iostream>
#include "system.h"
#include "vehicle.h"
#include "employee.h"
#include <vector>
using namespace std;

int main(){

    while(!user_login());
    while (1)
    {
        display_menu();
        
        short user_choice = take_user_choice();
        switch(user_choice){
            case 1:{
                system("clear");
                if(Vehicle::cars.empty()){
                    cout << "No cars to show\n";
                }
                else{
                    Vehicle::display_all();
                }

                wait_for_user();
                break;
            }

            case 2:{
                system("clear");
                Vehicle::add();
                system("clear");
                cout << "A new car is added successfully!\n";

                wait_for_user();
                break;
            }

            case 3:{
                system("clear");
                if(Vehicle::cars.empty()){
                    cout << "No cars to sell!\n";
                }else{
                    Vehicle::display_all();
                    
                    short index{};
                    while (index <=0 || index>Vehicle::cars.size()){
                        cout << "Enter car number: ";
                        cin >> index;
                    }

                    Vehicle::sell(index);
                    system("clear");
                    cout << "The car is sold successfully!\n";
                }
                wait_for_user();
                break;
            }

            case 4:{
                system("clear");
                if(Vehicle::cars.empty()){
                    cout << "No cars to modify!\n";
                
                }else{
                    Vehicle::display_all();
                    cout << "Enter car number: ";
                    int index;
                    cin >> index;

                    // make the stock =1 then sell it (to delete it from cars vector)
                    Vehicle::cars[index-1].stock=1;
                    Vehicle::sell(index);

                    Vehicle::add();

                    system("clear");
                    cout << "The car is modified successfully\n";
                }
                wait_for_user();
                break;
            }

            case 5:{
                system("clear");
                if(Vehicle::cars.empty()){
                    cout << "No cars to search!\n";
                
                }else{
                    Vehicle::search_menu();
                    cout << "Enter search type: ";
                    int search_type;
                    cin >> search_type;

                    cout << "Enter what do you want to search for: ";
                    string parameter;
                    cin >> parameter;
                    
                    cout << "Search result:\n";

                    int temp_min{},temp_max{};
                    vector<Vehicle> result;
                    switch(search_type){
                        case OEM:
                        case Model:
                            result = Vehicle::search_str((Vehicle_Search_Type)search_type, parameter);
                            break;

                        case Cost:
                        case Release_Year: 
                            cout << "Enter minimum range: ";
                            cin >> temp_min;
                            cout << "Enter maximum range: ";
                            cin >> temp_max;
                            result = Vehicle::search_range((Vehicle_Search_Type)search_type, temp_min,temp_max);
                            break;
                    }

                    Vehicle::display(result);
                }
                wait_for_user();
                break;
            }

            case 6:{
                system("clear");
                if(Employee::employees.empty()){
                    cout << "No employees to show\n";
                }
                else{
                    Employee::display_all();
                }

                wait_for_user();
                break;
            }

            case 7:{
                system("clear");
                Employee::add();
                system("clear");
                cout << "A new employee is added successfully!\n";

                wait_for_user();
                break;
            }

            case 8:{
                system("clear");
                if(Employee::employees.empty()){
                    cout << "No employees to remove!\n";
                }else{        
                    Employee::display_all();
                    
                    short index{};
                    while (index <=0 || index>Employee::employees.size()){
                        cout << "Enter employee number: ";
                        cin >> index;
                    }

                    Employee::remove(index);
                    system("clear");
                    cout << "The employee is removed successfully!\n";
                }
                wait_for_user();

                break;
            }

            case 9:{
                system("clear");
                if(Employee::employees.empty()){
                    cout << "No employees to modify!\n";
                
                }else{
                    Employee::display_all();
                    cout << "Enter employee number: ";
                    int index;
                    cin >> index;

                    Employee::remove(index);

                    Employee::add();

                    system("clear");
                    cout << "The car is modified successfully\n";
                }
                wait_for_user();

                break;
            }

            case 10:{
                system("clear");
                if(Employee::employees.empty()){
                    cout << "No employees to search!\n";
                
                }else{
                    Employee::search_menu();
                    cout << "Enter search type: ";
                    int search_type;
                    cin >> search_type;

                    cout << "Enter what do you want to search for: ";
                    string parameter;
                    cin >> parameter;
                    
                    cout << "Search result:\n";

                    vector<Employee> result = Employee::search((Employee_Search_Type)search_type, parameter);
                    Employee::display(result);
                }

                wait_for_user();
                break;
            }


            case 11:{
                change_password();
                break;
            }

            case 12:{
                exit(0);
                break;
            }
        }
    }
}