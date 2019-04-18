#ifndef FARM_FARM_H
#define FARM_FARM_H

#include "Animal.h"
#include <vector>


class Farm {
public:
    Farm(std::vector<Animal>, int slots = 50);

    void breed();

    void slaughter();

    int getSlots();

    const std::vector<Animal> &getAnimalList() const;

private:
    std::vector<Animal> _animalList;
    int _slots;
};

#endif
