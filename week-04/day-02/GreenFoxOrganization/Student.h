//
// Created by Horváth Donát on 2019-04-23.
//

#ifndef GREENFOXORGANIZATION_STUDENT_H
#define GREENFOXORGANIZATION_STUDENT_H

#import "Person.h"


class Student : public Person {
public:
    Student();

    Student(std::string, int, Gender, std::string, int skipedDays = 0);

    void introduce() override ;

    void getGoal() override ;

    void skipDays(int);

private:
    std::string _previousOrganization;
    int _skippedDays;
};

#endif //GREENFOXORGANIZATION_STUDENT_H
