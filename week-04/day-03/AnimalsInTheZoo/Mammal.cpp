//
// Created by Horváth Donát on 2019-04-24.
//

#include "Mammal.h"

Mammal::Mammal(std::string name)
{
    _name = name;
    _breedBy = "pushing miniature versions out.";
}

std::string Mammal::getName()
{
    return _name;
}

std::string Mammal::breed()
{
    return _breedBy;
}