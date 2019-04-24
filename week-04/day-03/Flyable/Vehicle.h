//
// Created by Horváth Donát on 2019-04-24.
//

#ifndef FLYABLE_VEHICLE_H
#define FLYABLE_VEHICLE_H


class Vehicle {
public:
    virtual void fillFuel() = 0;

    virtual void park() = 0;

    virtual void costPerKm() = 0;
};


#endif //FLYABLE_VEHICLE_H
