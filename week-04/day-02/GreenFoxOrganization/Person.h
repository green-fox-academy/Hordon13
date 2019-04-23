//
// Created by Horváth Donát on 2019-04-23.
//

#ifndef GREENFOXORGANIZATION_PERSON_H
#define GREENFOXORGANIZATION_PERSON_H

#include <iostream>

enum Gender {
    Male,
    Female,
    Other
};

class Person {
public:
    Person();

    Person(std::string, int, Gender);

    std::string getGenderString();

    virtual void introduce();

    virtual void getGoal();

    const std::string &getName() const;

    int getAge() const;

    Gender getGender() const;

private:
    std::string _name;
    int _age;
    Gender _gender;
};


#endif //GREENFOXORGANIZATION_PERSON_H
