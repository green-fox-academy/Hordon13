#include <iostream>
#include <vector>
#include <string>
#include "sum.h"

std::string getApple()
{
    return "apple";
}

int sum(std::vector<int> vectorIn)
{
    int sum = 0;
    for (unsigned int i = 0; i < vectorIn.size(); ++i) {
        sum += vectorIn[i];
    }

    return sum;
}
