#include <iostream>
#include <vector>
#include "Sharpie.h"
#include "SharpieSet.h"

int main()
{
    Sharpie penBlack("black", 3);
    Sharpie penBlue("blue", 1);
    Sharpie penRed("red", 2);

    std::vector<Sharpie> sharpieAll = {penBlack, penBlue, penRed};

    SharpieSet testSet(sharpieAll);

    std::cout << testSet.countUsable() << std::endl;

    for (int i = 0; i < 100; ++i) {
        testSet.useSharpieSet(0);
    }

    std::cout << testSet.countUsable() << std::endl;

    testSet.removeTrash();

    return 0;
}