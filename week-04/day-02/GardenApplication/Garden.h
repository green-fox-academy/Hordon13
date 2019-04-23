//
// Created by Horváth Donát on 2019-04-23.
//

#ifndef GARDENAPPLICATION_GARDEN_H
#define GARDENAPPLICATION_GARDEN_H

#include <vector>
#import "Flowers.h"
#import "Trees.h"

class Garden {
public:
    Garden();

    void watering(int);

    void addPlant(Plants *);

    void info();

private:
    std::vector<Plants> _allPlant;
};


#endif //GARDENAPPLICATION_GARDEN_H
