//
// Created by Horváth Donát on 2019-04-24.
//

#ifndef INSTRUMENTTOSTRINGEDINSTRUMENTS_VIOLIN_H
#define INSTRUMENTTOSTRINGEDINSTRUMENTS_VIOLIN_H

#include "StringedInstrument.h"

class Violin : public StringedInstrument {
public:

    Violin(int numberOfStrings = 4, std::string soundOf = "Screech");

    void play() override;

    void sound() override;

private:
    std::string _soundOf;

};


#endif //INSTRUMENTTOSTRINGEDINSTRUMENTS_VIOLIN_H
