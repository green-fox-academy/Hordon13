#include <iostream>
#include "Animal.h"
#include "Farm.h"
#include <string>
#include <vector>

int main()
{
    Animal monkey;
    monkey.setHunger(20);
    Animal donkey;
    donkey.setHunger(20);
    Animal tiger;
    tiger.setHunger(20);
    Animal turtle;
    turtle.setHunger(25);

    std::vector<Animal> zoo = {monkey, donkey, tiger, turtle};

    Farm zooBp(zoo);

    for (int i = 0; i < zooBp.getAnimalList().size(); ++i) {
        std::cout << zooBp.getAnimalList().at(i).getHunger() << std::endl;
    }

    zooBp.slaughter();

    for (int i = 0; i < zooBp.getAnimalList().size(); ++i) {
        std::cout << zooBp.getAnimalList().at(i).getHunger() << std::endl;
    }


    return 0;
}