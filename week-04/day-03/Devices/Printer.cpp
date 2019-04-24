//
// Created by Horváth Donát on 2019-04-24.
//

#include <iostream>
#include "Printer.h"

void Printer::print()
{
    std::cout << "I'm printing something that's " << getSize() << " cm." << std::endl;
}
