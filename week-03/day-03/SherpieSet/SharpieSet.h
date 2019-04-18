#ifndef SHERPIESET_SHARPIESET_H
#define SHERPIESET_SHARPIESET_H

#include <vector>
#include "Sharpie.h"

class SharpieSet {
public:
    SharpieSet(std::vector<Sharpie>);
    int countUsable();

    void removeTrash();

    void useSharpieSet(int);
    std::string getCol(int);

private:
    std::vector<Sharpie> _sharpieList;
};

#endif
