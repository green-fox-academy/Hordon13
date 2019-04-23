//
// Created by Horváth Donát on 2019-04-23.
//

#ifndef GREENFOXORGANIZATION_SPONSOR_H
#define GREENFOXORGANIZATION_SPONSOR_H

#include "Person.h"

class Sponsor : public Person {
public:
    Sponsor();

    Sponsor(std::string, int, Gender, std::string, int hiredStudents = 0);

    void introduce() override ;

    void getGoal() override ;

    void hire();

private:
    std::string _company;
    int _hiredStudents;
};


#endif //GREENFOXORGANIZATION_SPONSOR_H
