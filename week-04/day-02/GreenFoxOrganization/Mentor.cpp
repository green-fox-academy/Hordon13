//
// Created by Horváth Donát on 2019-04-23.
//

#include "Mentor.h"

Mentor::Mentor() : Person()
{
    _exp = Intermediate;
}

Mentor::Mentor(std::string name, int age, Gender gender, Level exp) : Person(name, age, gender)
{
    _exp = exp;
}

std::string Mentor::getLevelString()
{
    switch (_exp) {
        case Junior:
            return "Junior";
        case Intermediate:
            return "Intermediate";
        case Senior:
            return "Senior";
    }
}

void Mentor::introduce()
{
    std::cout << "Hi, I'm " << getName() << ", a " << getAge() << " year old " << getGenderString() << " "
              << getLevelString() << " mentor." << std::endl;
}

void Mentor::getGoal()
{
    std::cout << "My goal is: Educate brilliant junior software developers." << std::endl;
}