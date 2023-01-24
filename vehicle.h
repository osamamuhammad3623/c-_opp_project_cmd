#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef VEHICLE_HEADER
#define VEHICLE_HEADER

typedef enum{
    OEM=1, Model, Cost, Release_Year
}Vehicle_Search_Type;


class Vehicle{
public:
    string oem{};
    string model{};
    int cost{};
    int release_year{};
    int stock{};
    static vector<Vehicle> all_vehicles;

    Vehicle(string _oem, string _model, int _cost, int _release_year, int _stock);

    void static display_all(void);
    void static add(Vehicle &vehicle);
    void static search_menu(void);
    vector<Vehicle> static search_str(Vehicle_Search_Type search_by, string parameter);
    vector<Vehicle> static search_range(Vehicle_Search_Type search_by, int min_range, int max_range);
    
    void display(void);
    void sell(void);
};

#endif /*VEHICLE_HEADER*/