#include <iostream>
#include "Sharpie.h"

int main()
{
    Sharpie penBlack("black", 3);
    Sharpie penBlue("blue", 1);
    Sharpie penRed("red", 2);

    for (int i = 0; i < 20; ++i) {
        penBlack.use();
    }

    for (int j = 0; j < 30; ++j) {
        penBlue.use();
    }

    for (int k = 0; k < 10; ++k) {
        penRed.use();
    }

    std::cout << penBlack.getColor() << std::endl;
    std::cout << penBlack.getWidth() << std::endl;
    std::cout << penBlack.getInkAmount() << std::endl;
    std::cout << penRed.getInkAmount() << std::endl;
    std::cout << penBlue.getInkAmount() << std::endl;

    return 0;
}