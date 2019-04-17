#include <iostream>
#include "Station.h"
#include "Car.h"
#include <vector>

int main()
{

    Station mol(100);

    Car volvo(4, 4);
    Car bmw(7, 9);
    Car pegout(6, 12);
    Car suzuki(2, 5);
    Car toyota(7, 7);

    std::vector<Car> cars{volvo, bmw, pegout, suzuki, toyota};

    for (int i = 0; i < cars.size(); ++i) {
        if (mol.getGasAmount() > cars.at(i).getCapacity() - cars.at(i).getGasAmount()) {
            mol.fill(cars.at(i));
        } else {
            std::cout << "Not enough gas at the station!" << std::endl;
            break;
        }
    }

    return 0;
}