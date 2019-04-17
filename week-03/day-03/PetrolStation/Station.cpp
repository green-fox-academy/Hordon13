//
// Created by Horváth Donát on 2019-04-17.
//

#include "Station.h"
#include "Car.h"
#include <iostream>

Station::Station(int gasAmount) : gasAmount(gasAmount)
{}

void Station::fill(Car actualCar)
{
    if (!actualCar.isFull()) {

        while (actualCar.getCapacity() != actualCar.getGasAmount()) {
            std::cout << "Filling car!" << std::endl;
            actualCar.fill();
            --gasAmount;
        }

        std::cout << "Gas left at the station: " << gasAmount << std::endl;

    } else {
        std::cout << "The car is already full." << std::endl;
    }
}

int Station::getGasAmount() const
{
    return gasAmount;
}
