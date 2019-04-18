#include "SharpieSet.h"
#include <iostream>

SharpieSet::SharpieSet(std::vector<Sharpie> sharpieList)
{
    _sharpieList = sharpieList;
}

int SharpieSet::countUsable()
{
    int count = 0;
    for (int i = 0; i < _sharpieList.size(); ++i) {
        if (_sharpieList.at(i).getInkAmount() != 0) {
            ++count;
        }
    }

    return count;
}

void SharpieSet::removeTrash()
{
    for (int i = 0; i < _sharpieList.size(); ++i) {
        if (_sharpieList.at(i).getInkAmount() < 1) {
            _sharpieList.erase(_sharpieList.begin() + i);
        }
    }
}

void SharpieSet::useSharpieSet(int index)
{
    _sharpieList.at(index).use();
}

std::string SharpieSet::getCol(int index)
{
    return _sharpieList.at(index).getColor();
}