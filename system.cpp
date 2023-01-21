#include "system.h"
#include <fstream>

void display_menu(void){
    system("clear");
    cout << "1. View all vehicles\n";
    cout << "2. Add a vehicle\n";
    cout << "3. Sell a vehicle\n";
    cout << "4. Modify a vehicle info\n";
    cout << "5. Search for a vehicle\n";

    cout << "6. View all employees\n";
    cout << "7. Add an employee\n";
    cout << "8. Remove an employee\n";
    cout << "9. Modify an employee info\n";
    cout << "10. Search for an employee\n";
    
    cout << "11. Change password\n";
    cout << "12. Exit\n";
}

void change_password(void){
    system("clear");
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
    system("clear");
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