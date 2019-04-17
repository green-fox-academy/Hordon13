#include <iostream>

#include "fleet.h"

int main(int argc, char *args[])
{
    Fleet fleet;
    // Create a fleet of things to have this output:
    // 1. [ ] Get milk
    // 2. [ ] Remove the obstacles
    // 3. [x] Stand up
    // 4. [x] Eat lunch

    Thing milk("Get milk");
    Thing obstacles("Remove the obstacles");
    Thing stand("Stand up");
    Thing eat("Eat lunch");

    stand.complete();
    eat.complete();

    fleet.add(milk);
    fleet.add(obstacles);
    fleet.add(stand);
    fleet.add(eat);

    std::cout << fleet.toString() << std::endl;
    return 0;
}