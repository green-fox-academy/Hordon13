//
// Created by Horváth Donát on 2019-04-24.
//

#ifndef ANIMALSINTHEZOO_MAMMAL_H
#define ANIMALSINTHEZOO_MAMMAL_H

#include <string>
#include "Animals.h"

class Mammal : public Animals {
public:
    Mammal(std::string);

    std::string getName() override;

    std::string breed() override;

private:
    std::string _breedBy;
};

#endif //ANIMALSINTHEZOO_MAMMAL_H
