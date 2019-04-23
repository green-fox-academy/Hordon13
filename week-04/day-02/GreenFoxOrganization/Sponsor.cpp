//
// Created by Horváth Donát on 2019-04-23.
//

#include "Sponsor.h"

Sponsor::Sponsor() : Person()
{
    _company = "Google";
    _hiredStudents = 0;
}

Sponsor::Sponsor(std::string name, int age, Gender gender, std::string company, int hiredStudents) : Person(name, age,
                                                                                                            gender)
{
    _company = company;
    _hiredStudents = hiredStudents;
}

void Sponsor::introduce()
{
    std::cout << "Hi, I'm " << getName() << ", a " << getAge() << " year old " << getGenderString()
              << " who represents " << _company << " and hired " << _hiredStudents << " student so far." << std::endl;
}

void Sponsor::getGoal()
{
    std::cout << "My goal is: Hire brilliant junior software developers." << std::endl;
}

void Sponsor::hire()
{
    ++_hiredStudents;
}