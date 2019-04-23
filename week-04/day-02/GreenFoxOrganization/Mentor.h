//
// Created by Horváth Donát on 2019-04-23.
//

#ifndef GREENFOXORGANIZATION_MENTOR_H
#define GREENFOXORGANIZATION_MENTOR_H

#include "Person.h"

enum Level {
    Junior,
    Intermediate,
    Senior
};

class Mentor : public Person {
public:
    Mentor();

    Mentor(std::string, int, Gender, Level);

    std::string getLevelString();

    void introduce() override;

    void getGoal() override;


private:
    Level _exp;
};


#endif //GREENFOXORGANIZATION_MENTOR_H
