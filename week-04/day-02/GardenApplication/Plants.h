//
// Created by Horváth Donát on 2019-04-23.
//

#ifndef GARDENAPPLICATION_PLANTS_H
#define GARDENAPPLICATION_PLANTS_H

#include <string>

enum Type {
    Flower,
    Tree
};

class Plants {
public:
    Plants();

    Plants(std::string, int, double, double, bool, Type);

    std::string getTypeString();

    void haveWater(double);

    bool isStatus() const;

    const std::string &getColor() const;

private:
    std::string _color;
    int _waterNeed;
    double _waterAbsorb;
    double _waterAmount;
    bool _status;
    Type _type;
};

#endif //GARDENAPPLICATION_PLANTS_H
