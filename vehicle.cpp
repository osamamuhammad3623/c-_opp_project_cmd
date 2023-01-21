#include "vehicle.h"
#include <regex>

vector <Vehicle> Vehicle::cars{};

void Vehicle::display_all(void){
    short counter=1;
    for(Vehicle &car: cars){
        cout << "Vehicle " << counter++ << " :-\n";
        cout << "OEM: " << car.oem << endl;
        cout << "Model: " << car.model << endl;
        cout << "Cost: " << car.cost << endl;
        cout << "Release year: " << car.release_year << endl;
        cout << "Stock: " << car.stock << endl;
        cout << endl;
    }
}

void Vehicle::display(vector<Vehicle> &vehicles){
    short counter=1;
    for(Vehicle &v: vehicles){
        cout << "Vehicle " << counter++ << " :-\n";
        cout << "OEM: " << v.oem << endl;
        cout << "Model: " << v.model << endl;
        cout << "Cost: " << v.cost << endl;
        cout << "Release year: " << v.release_year << endl;
        cout << "Stock: " << v.stock << endl;
        cout << endl;
    }
}

void Vehicle::add(void){
    string oem,model;
    int stock{};
    int release_year{};
    int cost{};
    
    cout << "OEM: ";
    cin >> oem;

    cout << "Model: ";
    cin >> model;

    cout << "Cost: ";
    cin >> cost;

    cout << "Release year: ";
    cin >> release_year;

    cout << "Stock: ";
    cin >> stock;

    Vehicle new_car(oem,model,cost,release_year,stock);
    cars.push_back(new_car);

}

void Vehicle::sell(int index){
    index--; // to make it zero-based index

    if(cars[index].stock > 1){
        cars[index].stock--;
    
    }else if (cars[index].stock == 1){
        // remove the car from the vector
        swap(cars[index], cars.back());
        cars.pop_back();
    }
}

void Vehicle::search_menu(void){
    system("clear");
    cout << "1. Search by OEM\n";
    cout << "2. Search by model\n";
    cout << "3. Search by cost range\n";
    cout << "4. Search by release year range\n";
}


vector<Vehicle> Vehicle::search_str(Vehicle_Search_Type search_by, string parameter){

    vector<Vehicle> result{};
    regex expr("(.*)"+parameter+"(.*)");
    
    for(Vehicle &c: cars){
        switch (search_by)
        {
        case OEM:
            if(regex_search(c.oem, expr)){
                result.push_back(c);
            }
        case Model:
            if(regex_search(c.model, expr)){
                result.push_back(c);
            }
            break;
        }
    }

    return result;
}

vector<Vehicle> Vehicle::search_range(Vehicle_Search_Type search_by, int min_range, int max_range){
    vector<Vehicle> result{};

    for(Vehicle &c: cars){
        switch (search_by)
        {
        case Cost:
            if((c.cost >= min_range) && (c.cost <= max_range)){
                result.push_back(c);
            }
        case Release_Year:
            if((c.release_year >= min_range) && (c.release_year <= max_range)){
                result.push_back(c);
            }
            break;
        }
    }

    return result;
}