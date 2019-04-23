//
// Created by Horváth Donát on 2019-04-23.
//

#include "Flowers.h"

Flowers::Flowers(std::string color, int waterNeed, double waterAbsorb, double waterAmount, bool status, Type type)
        : Plants(color, waterNeed, waterAbsorb, waterAmount, status, type)
{}