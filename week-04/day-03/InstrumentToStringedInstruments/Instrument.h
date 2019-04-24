//
// Created by Horváth Donát on 2019-04-24.
//

#ifndef INSTRUMENTTOSTRINGEDINSTRUMENTS_INSTRUMENT_H
#define INSTRUMENTTOSTRINGEDINSTRUMENTS_INSTRUMENT_H

#include <string>

class Instrument {
public:
    virtual void play() = 0;

protected:
    std::string _name;
};


#endif //INSTRUMENTTOSTRINGEDINSTRUMENTS_INSTRUMENT_H
