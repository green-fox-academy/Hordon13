//
// Created by Horváth Donát on 2019-04-24.
//

#ifndef ANIMALSINTHEZOO_ANIMALS_H
#define ANIMALSINTHEZOO_ANIMALS_H


#include <string>

class Animals {
public:
    virtual std::string getName() = 0;

    virtual std::string breed() = 0;

protected:
    std::string _name;
    int _age;
};


#endif //ANIMALSINTHEZOO_ANIMALS_H