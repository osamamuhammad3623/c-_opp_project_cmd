#include "system.h"
#include <fstream>

void display_menu(void){
    system("cls");
    cout << "1. View all cars\n";
    cout << "2. Add a car\n";
    cout << "3. Sell a car\n";
    cout << "4. Modify a car info\n";

    cout << "5. View all employees\n";
    cout << "6. Add an employee\n";
    cout << "7. Remove an employee\n";
    cout << "8. Modify an employee info\n";
    
    cout << "9. Change password\n";
    cout << "10. Exit\n";
}

void change_password(void){
    system("cls");
    cout << "Enter the new password: ";
    
    string new_pass{};
    cin >> new_pass;
    store_password(new_pass);
}

void wait_for_user(void){
    cout << "Press (b) to go back\n";
    char b;
    while((cin >> b) && (b!= 'b'));
}

string load_password(void){
    fstream file;
    file.open("user_pass");
    
    string pass{};
    if(file.is_open()){
        file >> pass;
    }

    return pass;
}

void store_password(string pass){
    fstream file;
    file.open("user_pass");
    
    if(file.is_open()){
        file << pass;
    }
}

bool user_login(void){
    system("cls");
    cout << "Enter password: ";
    string user_input;
    cin >> user_input;

    if (load_password() == user_input){
        return true; 
    }
    return false;
}

int take_user_choice(void){
    cout << "Enter your choice number: ";
    int choice;
    cin >> choice;
    return choice;
}