//
// Created by Horváth Donát on 2019-04-17.
//

#ifndef PETROLSTATION_STATION_H
#define PETROLSTATION_STATION_H

#include "Car.h"

class Station {
public:
    Station(int gasAmount);

    void fill(Car);

    int getGasAmount() const;

private:
    int gasAmount;
};


#endif //PETROLSTATION_STATION_H
