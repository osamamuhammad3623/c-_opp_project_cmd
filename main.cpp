#include <iostream>
#include "system.h"
#include "car.h"
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
                system("cls");
                if(Car::cars.empty()){
                    cout << "No cars to show\n";
                }
                else{
                    Car::display_all();
                }

                wait_for_user();
                break;
            }

            case 2:{
                system("cls");
                Car::add();
                system("cls");
                cout << "A new car is added successfully!\n";

                wait_for_user();
                break;
            }

            case 3:{
                system("cls");
                if(Car::cars.empty()){
                    cout << "No cars to sell!\n";
                }else{
                    Car::display_all();
                    
                    short index{};
                    while (index <=0 || index>Car::cars.size()){
                        cout << "Enter car number: ";
                        cin >> index;
                    }

                    Car::sell(index);
                    system("cls");
                    cout << "The car is sold successfully!\n";
                }
                wait_for_user();
                break;
            }

            case 4:{
                system("cls");
                if(Car::cars.empty()){
                    cout << "No cars to modify!\n";
                
                }else{
                    Car::display_all();
                    cout << "Enter car number: ";
                    int index;
                    cin >> index;

                    // make the stock =1 then sell it (to delete it from cars vector)
                    Car::cars[index-1].stock=1;
                    Car::sell(index);

                    Car::add();

                    system("cls");
                    cout << "The car is modified successfully\n";
                }
                wait_for_user();
                break;
            }

            case 5:{
                system("cls");
                if(Employee::employees.empty()){
                    cout << "No employees to show\n";
                }
                else{
                    Employee::display_all();
                }

                wait_for_user();
                break;
            }

            case 6:{
                system("cls");
                Employee::add();
                system("cls");
                cout << "A new employee is added successfully!\n";

                wait_for_user();
                break;
            }

            case 7:{
                system("cls");
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
                    system("cls");
                    cout << "The employee is removed successfully!\n";
                }
                wait_for_user();

                break;
            }

            case 8:{
                system("cls");
                if(Employee::employees.empty()){
                    cout << "No employees to modify!\n";
                
                }else{
                    Employee::display_all();
                    cout << "Enter employee number: ";
                    int index;
                    cin >> index;

                    Employee::remove(index);

                    Employee::add();

                    system("cls");
                    cout << "The car is modified successfully\n";
                }
                wait_for_user();

                break;
            }

            case 9:{
                change_password();
                break;
            }

            case 10:{
                exit(0);
                break;
            }
        }
    }
}