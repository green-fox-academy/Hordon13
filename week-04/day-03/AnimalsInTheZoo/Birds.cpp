//
// Created by Horváth Donát on 2019-04-24.
//

#include "Birds.h"

Birds::Birds(std::string name)
{
    _name = name;
    _breedBy = "laying eggs";
}

std::string Birds::getName()
{
    return _name;
}

std::string Birds::breed()
{
    return _breedBy;
}