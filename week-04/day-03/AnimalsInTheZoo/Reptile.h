//
// Created by Horváth Donát on 2019-04-24.
//

#ifndef ANIMALSINTHEZOO_REPTILE_H
#define ANIMALSINTHEZOO_REPTILE_H

#include <string>
#include "Animals.h"

class Reptile : public Animals {
public:
    Reptile(std::string);

    std::string getName() override;

    std::string breed() override;

private:
    std::string _breedBy;
};

#endif //ANIMALSINTHEZOO_REPTILE_H
