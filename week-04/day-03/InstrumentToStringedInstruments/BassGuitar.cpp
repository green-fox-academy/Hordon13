//
// Created by Horváth Donát on 2019-04-24.
//

#include <iostream>
#include "BassGuitar.h"

BassGuitar::BassGuitar(int numberOfStrings, std::string soundOf)
{
    _numberOfStrings = numberOfStrings;
    _soundOf = soundOf;
    _name = "Bass Guitar";
}

void BassGuitar::play()
{
    sound();
}

void BassGuitar::sound()
{
    std::cout << _name << ", a " << _numberOfStrings << "-stringed instrument that goes " << _soundOf << std::endl;
}