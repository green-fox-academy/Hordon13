//
// Created by Horváth Donát on 2019-04-24.
//

#include <iostream>
#include "ElectricGuitar.h"

ElectricGuitar::ElectricGuitar(int numberOfStrings, std::string soundOf)
{
    _numberOfStrings = numberOfStrings;
    _soundOf = soundOf;
    _name = "Electric Guitar";
}

void ElectricGuitar::play()
{
    sound();
}

void ElectricGuitar::sound()
{
    std::cout << _name << ", a " << _numberOfStrings << "-stringed instrument that goes " << _soundOf << std::endl;
}
