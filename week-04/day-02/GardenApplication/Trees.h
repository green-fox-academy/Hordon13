//
// Created by Horváth Donát on 2019-04-23.
//

#ifndef GARDENAPPLICATION_TREES_H
#define GARDENAPPLICATION_TREES_H

#include <string>
#import "Plants.h"


class Trees : public Plants {
public:
    Trees(std::string, int waterNeed = 10, double waterAbsorb = 0.4, double waterAmount = 0, bool status = false,
            Type type = Tree);
};


#endif //GARDENAPPLICATION_TREES_H
