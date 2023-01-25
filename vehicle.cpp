#include "vehicle.h"
#include <regex>

vector <Vehicle> Vehicle::all_vehicles{};

Vehicle::Vehicle(string _oem, string _model, int _cost, int _release_year, int _stock):
    oem{_oem},
    model{_model},
    cost{_cost},
    release_year{_release_year},
    stock{_stock}
{
    if(cost<0){cost =0;}
    if(release_year<2000){release_year =2000;}
    if(stock<0){stock =0;}
};

void Vehicle::display_all(void){
    short counter=1;
    for(Vehicle &car: all_vehicles){
        cout << "Vehicle " << counter++ << " :-\n";
        cout << "OEM: " << car.oem << endl;
        cout << "Model: " << car.model << endl;
        cout << "Cost: " << car.cost << endl;
        cout << "Release year: " << car.release_year << endl;
        cout << "Stock: " << car.stock << endl;
        cout << endl;
    }
}

void Vehicle::display(void){
    cout << "Vehicle:\n";
    cout << "OEM: " << oem << endl;
    cout << "Model: " << model << endl;
    cout << "Cost: " << cost << endl;
    cout << "Release year: " << release_year << endl;
    cout << "Stock: " << stock << endl;
    cout << endl;
}

void Vehicle::add(Vehicle &vehicle){
    
    all_vehicles.push_back(vehicle);
}

void Vehicle::sell(void){

    if (this->stock == 1){
        // remove vehicle from the vector
        for(Vehicle &v: all_vehicles){
            if((v.oem==oem) || (v.model==model) || (v.cost==cost)|| (v.stock==stock) || (v.release_year==release_year)){
                swap(v, all_vehicles.back());
                all_vehicles.pop_back();
                break;
            }
        }
    }
    else{
        this->stock--;
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
    
    for(Vehicle &c: all_vehicles){
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
    if((min_range<0) || (max_range<0) || (min_range>=max_range)){
        return vector<Vehicle>();
    }
    vector<Vehicle> result{};

    for(Vehicle &c: all_vehicles){
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