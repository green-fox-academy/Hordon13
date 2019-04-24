//
// Created by Horváth Donát on 2019-04-24.
//

#ifndef INSTRUMENTTOSTRINGEDINSTRUMENTS_ELECTRICGUITAR_H
#define INSTRUMENTTOSTRINGEDINSTRUMENTS_ELECTRICGUITAR_H

#include "StringedInstrument.h"

class ElectricGuitar : public StringedInstrument {
public:

    ElectricGuitar(int numberOfStrings = 6, std::string soundOf = "Twang");

    void play() override;

    void sound() override;

private:
    std::string _soundOf;

};


#endif //INSTRUMENTTOSTRINGEDINSTRUMENTS_ELECTRICGUITAR_H
