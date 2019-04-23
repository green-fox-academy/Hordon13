#include <iostream>
#include <vector>
#import "Plants.h"
#import "Flowers.h"
#import "Trees.h"
#import "Garden.h"

int main()
{
    Garden myGarden;

    Flowers yellowFlower("yellow");
    Flowers blueFlower("blue");
    Trees purpleTree("purple");
    Trees orangeTree("orange");

    myGarden.addPlant(&yellowFlower);
    myGarden.addPlant(&blueFlower);
    myGarden.addPlant(&purpleTree);
    myGarden.addPlant(&orangeTree);

    myGarden.watering(40);
    myGarden.watering(70);

    return 0;
}