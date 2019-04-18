#include "Pirate.h"
#include <iostream>

Pirate::Pirate(int intoxication, bool isLive)
{
    _intoxication = intoxication;
    _isLive = isLive;
}

void Pirate::drinkSomeRum()
{
    if (_isLive && _intoxication < 4) {
        ++_intoxication;
    } else if (!_isLive) {
        std::cout << "he's dead" << std::endl;
    }

}

void Pirate::howsItGoingMate()
{
    if (_isLive && _intoxication < 4) {
        std::cout << "Pour me anudder!" << std::endl;
    } else if (_isLive && _intoxication == 4) {
        std::cout << "Arghh, I'ma Pirate. How d'ya d'ink its goin?" << std::endl;
    } else if (!_isLive) {
        std::cout << "he's dead" << std::endl;
    }
}

//todo: enemy ertekeit nem tudja felulirni

void Pirate::brawl(Pirate enemy)
{
    srand(time(NULL));
    int fight = rand() % 3;

    std::cout << fight << std::endl;

    if (fight == 0) {
        setIsLive(false);
    } else if (fight == 1) {
        enemy.setIsLive(false);
    } else if (fight == 2) {
        setIntoxication(4);
        enemy.setIntoxication(4);
    }
}

void Pirate::die()
{
    setIsLive(false);
}

void Pirate::setIsLive(bool isLive)
{
    _isLive = isLive;
}

int Pirate::getIntoxication() const
{
    return _intoxication;
}

bool Pirate::isIsLive() const
{
    return _isLive;
}

void Pirate::setIntoxication(int intoxication)
{
    _intoxication = intoxication;
}