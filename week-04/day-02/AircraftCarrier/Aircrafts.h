//
// Created by Horváth Donát on 2019-04-24.
//

#ifndef AIRCRAFTCARRIER_AIRCRAFTS_H
#define AIRCRAFTCARRIER_AIRCRAFTS_H

#include <string>

class Aircrafts {
public:
    Aircrafts(std::string, int, int, int ammo = 0);

    int fight();

    int refill(int);

    std::string getType();

    std::string getStatus();

    bool isPriority();

protected:
    std::string _type;
    int _ammo;
    int _maxAmmo;
    int _baseDamage;
};


#endif //AIRCRAFTCARRIER_AIRCRAFTS_H
