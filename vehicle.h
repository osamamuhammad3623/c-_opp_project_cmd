#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
    static vector<Vehicle> cars;

    Vehicle(string _oem, string _model, int _cost, int _release_year, int _stock):
        oem{_oem},
        model{_model},
        cost{_cost},
        release_year{_release_year},
        stock{_stock}
    {};

    void static display_all(void);
    void static display(vector<Vehicle> &vehicles);
    void static add(void);
    void static sell(int index);
    void static search_menu(void);

    vector<Vehicle> static search_str(Vehicle_Search_Type search_by, string parameter);

    vector<Vehicle> static search_range(Vehicle_Search_Type search_by, int min_range, int max_range);
    
};
