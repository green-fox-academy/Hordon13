#include <iostream>
#include "Pirate.h"

int main()
{

    Pirate jack;
    Pirate buck;

    jack.brawl(buck);

    std::cout << jack.isIsLive() << std::endl;
    std::cout << buck.isIsLive() << std::endl;
    std::cout << std::endl;
    std::cout << jack.getIntoxication() << std::endl;
    std::cout << buck.getIntoxication() << std::endl;


    /*
    std::cout << jack.getIntoxication() << std::endl;
    std::cout << jack.isIsLive() << std::endl;
    jack.drinkSomeRum();
    std::cout << jack.getIntoxication() << std::endl;
    jack.howsItGoingMate();
    jack.drinkSomeRum();
    jack.drinkSomeRum();
    jack.drinkSomeRum();
    jack.howsItGoingMate();
    jack.drinkSomeRum();
    std::cout << jack.getIntoxication() << std::endl;
    jack.die();
    std::cout << jack.isIsLive() << std::endl;
    jack.drinkSomeRum();
    jack.howsItGoingMate();
    */


    return 0;
}