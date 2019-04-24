//
// Created by Horváth Donát on 2019-04-24.
//

#include <iostream>
#include "Violin.h"

Violin::Violin(int numberOfStrings, std::string soundOf)
{
    _numberOfStrings = numberOfStrings;
    _soundOf = soundOf;
    _name = "Violin";
}

void Violin::play()
{
    sound();
}

void Violin::sound()
{
    std::cout << _name << ", a " << _numberOfStrings << "-stringed instrument that goes " << _soundOf << std::endl;
}
