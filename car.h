#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Car{
public:
    string oem{};
    string model{};
    int cost{};
    int release_year{};
    int stock{};
    static vector<Car> cars;

    Car(string _oem, string _model, int _cost, int _release_year, int _stock):
        oem{_oem},
        model{_model},
        cost{_cost},
        release_year{_release_year},
        stock{_stock}
    {};

    void static display_all(void);
    void static add(void);
    void static sell(int index);
};
