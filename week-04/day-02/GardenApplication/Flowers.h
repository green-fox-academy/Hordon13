//
// Created by Horváth Donát on 2019-04-23.
//

#ifndef GARDENAPPLICATION_FLOWERS_H
#define GARDENAPPLICATION_FLOWERS_H

#include <string>
#import "Plants.h"


class Flowers : public Plants {
public:
    Flowers(std::string, int waterNeed = 5, double waterAbsorb = 0.75, double waterAmount = 0, bool status = false,
            Type type = Flower);
};


#endif //GARDENAPPLICATION_FLOWERS_H