//
// Created by Horváth Donát on 2019-04-23.
//

#include "Student.h"

Student::Student() : Person()
{
    _previousOrganization = "The School of Life";
    _skippedDays = 0;
}

Student::Student(std::string name, int age, Gender gender, std::string previousOrganization, int skipedDays) : Person(
        name, age, gender)
{
    _previousOrganization = previousOrganization;
    _skippedDays = skipedDays;
}

void Student::introduce()
{
    std::cout << "Hi, I'm " << getName() << ", a " << getAge() << " year old " << getGenderString() << " from "
              << _previousOrganization << " who skipped " << _skippedDays << " from the course already." << std::endl;
}

void Student::getGoal()
{
    std::cout << "My goal is: Be a junior software developer." << std::endl;
}

void Student::skipDays(int day)
{
    _skippedDays += day;
}