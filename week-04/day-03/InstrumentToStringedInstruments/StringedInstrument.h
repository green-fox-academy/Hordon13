//
// Created by Horváth Donát on 2019-04-24.
//

#ifndef INSTRUMENTTOSTRINGEDINSTRUMENTS_STRINGEDINSTRUMENT_H
#define INSTRUMENTTOSTRINGEDINSTRUMENTS_STRINGEDINSTRUMENT_H

#include "Instrument.h"
#include <vector>


class StringedInstrument : public Instrument {
public:
    virtual void sound() = 0;

protected:
    int _numberOfStrings;
};

#endif //INSTRUMENTTOSTRINGEDINSTRUMENTS_STRINGEDINSTRUMENT_H