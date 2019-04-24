//
// Created by Horváth Donát on 2019-04-24.
//

#include "Copier.h"
#include <iostream>

Copier::Copier(int sizeX, int sizeY, int speed) : Printer2D(sizeX, sizeY), Scanner(speed)
{}

void Copier::copy()
{
    scan();
    std::cout << "and ";
    print();
}