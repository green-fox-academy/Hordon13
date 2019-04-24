//
// Created by Horváth Donát on 2019-04-24.
//

#include "Reptile.h"

Reptile::Reptile(std::string name)
{
    _name = name;
    _breedBy = "laying eggs";
}

std::string Reptile::getName()
{
    return _name;
}

std::string Reptile::breed()
{
    return _breedBy;
}