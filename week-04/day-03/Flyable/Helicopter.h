//
// Created by Horváth Donát on 2019-04-24.
//

#ifndef FLYABLE_HELICOPTER_H
#define FLYABLE_HELICOPTER_H


#include "Vehicle.h"
#include "Flyable.h"

class Helicopter : public Vehicle, public Flyable {
public:
    void land() override;

    void fly() override;

    void takeOf() override;

    void fillFuel() override;

    void park() override;

    void costPerKm() override;

};


#endif //FLYABLE_HELICOPTER_H
