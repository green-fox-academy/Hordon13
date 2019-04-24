//
// Created by Horváth Donát on 2019-04-24.
//

#ifndef ANIMALSINTHEZOO_BIRDS_H
#define ANIMALSINTHEZOO_BIRDS_H

#include <string>
#include "Animals.h"

class Birds : public Animals {
public:
    Birds(std::string);

    std::string getName() override;

    std::string breed() override;

private:
    std::string _breedBy;
};


#endif //ANIMALSINTHEZOO_BIRDS_H
