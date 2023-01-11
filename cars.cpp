#include "car.h"

vector <Car> Car::cars{};

void Car::display_all(void){
    short counter=1;
    for(Car &car: cars){
        cout << "Car " << counter++ << " :-\n";
        cout << "OEM: " << car.oem << endl;
        cout << "Model: " << car.model << endl;
        cout << "Cost: " << car.cost << endl;
        cout << "Release year: " << car.release_year << endl;
        cout << "Stock: " << car.stock << endl;
        cout << endl;
    }
}

void Car::add(void){
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

    Car new_car(oem,model,cost,release_year,stock);
    cars.push_back(new_car);

}

void Car::sell(int index){
    index--; // to make it zero-based index

    if(cars[index].stock > 1){
        cars[index].stock--;
    
    }else if (cars[index].stock == 1){
        // remove the car from the vector
        swap(cars[index], cars.back());
        cars.pop_back();
    }
}