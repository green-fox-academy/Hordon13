//
// Created by Horváth Donát on 2019-04-23.
//

#include <iostream>
#include "Garden.h"
#include "Plants.h"

Garden::Garden()
{
    _allPlant = {};
}

void Garden::watering(int givenWater)
{
    int thirsty = 0;
    for (int i = 0; i < _allPlant.size(); ++i) {
        if (_allPlant.at(i).isStatus() == 0) {
            ++thirsty;
        }
    }

    double waterPortion = givenWater / thirsty;

    for (int i = 0; i < _allPlant.size(); ++i) {
        if (_allPlant.at(i).isStatus() == 0) {
            _allPlant.at(i).haveWater(waterPortion);
        }
    }

    info();
}

void Garden::addPlant(Plants *plant)
{
    _allPlant.push_back(*plant);
}

void Garden::info()
{
    std::cout << std::endl;
    for (int i = 0; i < _allPlant.size(); ++i) {
        if (_allPlant.at(i).isStatus() == 0) {
            std::cout << "This " << _allPlant.at(i).getColor() << " " << _allPlant.at(i).getTypeString()
                      << " needs water" << std::endl;
        } else {
            std::cout << "This " << _allPlant.at(i).getColor() << " " << _allPlant.at(i).getTypeString()
                      << " doesn't need water" << std::endl;
        }
    }
}