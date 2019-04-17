//
// Created by Horváth Donát on 2019-04-17.
//

#include "Car.h"

Car::Car(int gasAmount, int capacity) : gasAmount(gasAmount), capacity(capacity)
{}

bool Car::isFull()
{
    if (gasAmount == capacity) {
        return true;
    } else {
        return false;
    }
}

void Car::fill()
{
    ++gasAmount;
}

int Car::getGasAmount() const
{
    return gasAmount;
}

int Car::getCapacity() const
{
    return capacity;
}
