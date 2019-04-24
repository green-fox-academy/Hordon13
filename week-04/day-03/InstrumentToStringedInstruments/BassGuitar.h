//
// Created by Horváth Donát on 2019-04-24.
//

#ifndef INSTRUMENTTOSTRINGEDINSTRUMENTS_BASSGUITAR_H
#define INSTRUMENTTOSTRINGEDINSTRUMENTS_BASSGUITAR_H

#include "StringedInstrument.h"

class BassGuitar : public StringedInstrument {
public:

    BassGuitar(int numberOfStrings = 4, std::string soundOf = "Duum-duum-duum");

    void play() override;

    void sound() override;

private:
    std::string _soundOf;

};


#endif //INSTRUMENTTOSTRINGEDINSTRUMENTS_BASSGUITAR_H
