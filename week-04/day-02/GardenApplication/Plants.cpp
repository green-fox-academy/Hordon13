//
// Created by Horváth Donát on 2019-04-23.
//

#include "Plants.h"
#include <iostream>

Plants::Plants()
{
    _color = "undefined";
    _waterNeed = 0;
    _waterAbsorb = 0;
    _waterAmount = 0;
    _status = false;
    _type = Tree;

    std::cout << "This " << _color << " " << getTypeString() << " needs a definition" << std::endl;
}

Plants::Plants(std::string color, int waterNeed, double waterAbsorb, double waterAmount, bool status, Type type)
{
    _color = color;
    _waterNeed = waterNeed;
    _waterAbsorb = waterAbsorb;
    _waterAmount = waterAmount;
    _status = status;
    _type = type;

    std::cout << "This " << _color << " " << getTypeString() << " needs water" << std::endl;
}

std::string Plants::getTypeString()
{
    switch (_type) {
        case Flower:
            return "Flower";
        case Tree:
            return "Tree";
    }
}

void Plants::haveWater(double water)
{
    _waterAmount += water * _waterAbsorb;

    if (_waterAmount > _waterNeed) {
        _status = true;
    };
}

bool Plants::isStatus() const
{
    return _status;
}

const std::string &Plants::getColor() const
{
    return _color;
}