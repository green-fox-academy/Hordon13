#include <iostream>
#include "Animals.h"
#include "Vehicle.h"
#include "Flyable.h"
#include "Bird.h"
#include "Helicopter.h"

int main()
{
    Helicopter heli;
    heli.costPerKm();
    heli.fillFuel();
    heli.fly();
    heli.land();
    heli.takeOf();
    heli.park();

    std::cout << std::endl;

    Bird parrot;
    parrot.takeOf();
    parrot.land();
    parrot.fly();
    std::cout << parrot.getName() << std::endl;
    std::cout << parrot.breed() << std::endl;

    return 0;
}