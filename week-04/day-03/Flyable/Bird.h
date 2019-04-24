//
// Created by Horváth Donát on 2019-04-24.
//

#ifndef FLYABLE_BIRD_H
#define FLYABLE_BIRD_H

#include "Flyable.h"
#include "Animals.h"

class Bird : public Flyable, public Animals {
public:
    std::string getName() override;

    std::string breed() override;

    void land() override;

    void fly() override;

    void takeOf() override;

};


#endif //FLYABLE_BIRD_H
