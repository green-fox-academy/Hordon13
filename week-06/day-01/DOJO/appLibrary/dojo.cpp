#include "dojo.h"

int getIndex(int num, std::vector<int> vector)
{
    auto it = std::find(vector.begin(), vector.end(), num);

    if (it != vector.end()){
        return std::distance(vector.begin(), it);
    } else {
        return -1;
    }
}