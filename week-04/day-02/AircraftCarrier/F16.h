//
// Created by Horváth Donát on 2019-04-24.
//

#ifndef AIRCRAFTCARRIER_F16_H
#define AIRCRAFTCARRIER_F16_H

#include "Aircrafts.h"

class F16 : public Aircrafts {
public:
    F16(std::string type = "F16", int baseDamage = 30, int maxAmmo = 8);
};


#endif //AIRCRAFTCARRIER_F16_H
