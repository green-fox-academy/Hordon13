//
// Created by Horváth Donát on 2019-04-24.
//

#ifndef AIRCRAFTCARRIER_F35_H
#define AIRCRAFTCARRIER_F35_H

#include "Aircrafts.h"

class F35 : public Aircrafts {
public:
    F35(std::string type = "F35", int baseDamage = 50, int maxAmmo = 12);
};


#endif //AIRCRAFTCARRIER_F35_H
