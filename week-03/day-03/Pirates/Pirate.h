#ifndef PIRATES_PIRATE_H
#define PIRATES_PIRATE_H

#include <string>
#include <iostream>

class Pirate {
public:
    Pirate(int intoxication = 0, bool isLive = true);

    void drinkSomeRum();

    void howsItGoingMate();

    void die();

    void brawl(Pirate);

    int getIntoxication() const;

    void setIsLive(bool isLive);

    bool isIsLive() const;

    void setIntoxication(int intoxication);

private:
    int _intoxication;
    bool _isLive;

};


#endif
