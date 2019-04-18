#include "Farm.h"
#include <iostream>

Farm::Farm(std::vector<Animal> animalList, int slots)
{
    _animalList = animalList;
    _slots = slots;
}

void Farm::breed()
{
    if (_slots > 0) {
        --_slots;
    } else {
        std::cout << "The Zoo is full!" << std::endl;
    }
}

void Farm::slaughter()
{
    int minHunger = 0;
    int index;
    for (int i = 0; i < _animalList.size(); ++i) {
        if (_animalList.at(i).getHunger() > minHunger) {
            minHunger = _animalList.at(i).getHunger();
            index = i;
        }
    }

    _animalList.erase(_animalList.begin() + index);
    ++_slots;
}

int Farm::getSlots()
{
    return _slots;
}

const std::vector<Animal> &Farm::getAnimalList() const
{
    return _animalList;
}
