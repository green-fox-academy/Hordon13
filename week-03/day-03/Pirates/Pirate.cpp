#include "Pirate.h"
#include <iostream>

Pirate::Pirate(int intoxication, bool isLive, bool isPassedOut)
{
    _intoxication = intoxication;
    _isLive = isLive;
    _isPassedOut = isPassedOut;
}

void Pirate::drinkSomeRum()
{
    if (_isLive && _intoxication < 3) {
        ++_intoxication;
    } else if (_isLive && _intoxication >= 3) {
        setIsPassedOut(true);
        setIntoxication(4);
    } else if (!_isLive) {
        std::cout << "he's dead" << std::endl;
    }
}

void Pirate::howsItGoingMate()
{
    if (_isLive && _intoxication < 4) {
        std::cout << "Pour me anudder!" << std::endl;
    } else if (_isLive && _isPassedOut) {
        std::cout << "Arghh, I'ma Pirate. How d'ya d'ink its goin?" << std::endl;
    } else if (!_isLive) {
        std::cout << "he's dead" << std::endl;
    }
}

void Pirate::brawl(Pirate &enemy)
{
    if (_isLive && enemy.isIsLive() && !enemy._isPassedOut && !_isPassedOut) {

        srand(time(nullptr));
        int fight = rand() % 3;

        if (fight == 0) {
            die();
        } else if (fight == 1) {
            enemy.die();
        } else if (fight == 2) {
            setIsPassedOut(true);
            enemy.setIsPassedOut(true);
        }
    } else {
        std::cout << "Who is passed, can't fight anymore..." << std::endl;
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

void Pirate::setIsPassedOut(bool isPassedOut)
{
    _isPassedOut = isPassedOut;
}

bool Pirate::isIsPassedOut() const
{
    return _isPassedOut;
}
