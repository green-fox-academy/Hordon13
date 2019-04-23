//
// Created by Horváth Donát on 2019-04-23.
//

#include "Person.h"

Person::Person()
{
    _name = "Jane Doe";
    _age = 30;
    _gender = Female;
}

Person::Person(std::string name, int age, Gender gender)
{
    _name = name;
    _age = age;
    _gender = gender;
}

std::string Person::getGenderString()
{
    switch (_gender) {
        case Female:
            return "Female";
        case Male:
            return "Male";
        case Other:
            return "Other";
    }
}

void Person::introduce()
{
    std::cout << "Hi, I'm " << _name << ", a " << _age << " year old " << getGenderString() << "." << std::endl;
}

void Person::getGoal()
{
    std::cout << "My goal is: Live for the moment!" << std::endl;
}

const std::string &Person::getName() const
{
    return _name;
}

int Person::getAge() const
{
    return _age;
}

Gender Person::getGender() const
{
    return _gender;
}
