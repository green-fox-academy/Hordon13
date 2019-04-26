#include <iostream>
#include <vector>

#include "generateSecret.h"

int generate()
{
    int secretNum;
    do {
        srand(time(nullptr));
        secretNum = rand() % 9000 + 1000;

    } while (!check(secretNum));

    return secretNum;
}

bool check(int secret)
{
    std::vector<int> digits;

    for (int i = 0; i < 4; ++i) {
        digits.push_back(secret % 10);
        secret /= 10;
    }

    std::sort(digits.begin(), digits.end());
    auto last = std::unique(digits.begin(), digits.end());
    digits.erase(last, digits.end());

    return digits.size() == 4;
}