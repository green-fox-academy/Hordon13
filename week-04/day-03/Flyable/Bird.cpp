//
// Created by Horváth Donát on 2019-04-24.
//

#include "Bird.h"
#include <iostream>

std::string Bird::getName()
{
    return "Slim shady";
}

std::string Bird::breed()
{
    return "Breeding";
}

void Bird::land()
{
    std::cout << "Landing..." << std::endl;
}

void Bird::fly()
{
    std::cout << "Flying..." << std::endl;
}

void Bird::takeOf()
{
    std::cout << "Taking of..." << std::endl;
}