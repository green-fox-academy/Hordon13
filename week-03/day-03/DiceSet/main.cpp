#include <iostream>

#include "DiceSet.h"

int main(int argc, char *args[])
{
    // You have a `DiceSet` class which has a list for 6 dices
    // You can roll all of them with roll()
    // Check the current rolled numbers with getCurrent()
    // You can reroll with roll()
    // Your task is to roll the dices until all of the dices are 6

    DiceSet diceSet;
    diceSet.roll();

    int numOfTrials = 0;
    for (int i = 0; i < diceSet.getCurrent().size(); ++i) {
        while (diceSet.getCurrent(i) != 6) {
            diceSet.roll(i);
            ++numOfTrials;
        }
    }

    for (int j = 0; j < diceSet.getCurrent().size(); ++j) {
        std::cout << diceSet.getCurrent(j);
    }
    std::cout << std::endl;

    std::cout << "Sucess within " << numOfTrials << " roll." << std::endl;

    return 0;
}