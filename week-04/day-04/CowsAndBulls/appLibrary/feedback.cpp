#include <iostream>
#include <vector>

#include "feedback.h"

void feedback(int secret, int user)
{
    int bull = 0, cow = 0;
    std::vector<int> secretDigits, userDigits;

    for (int i = 0; i < 4; ++i) {
        secretDigits.push_back(secret % 10);
        userDigits.push_back(user % 10);
        secret /= 10;
        user /= 10;
    }

    for (int j = 0; j < 4; ++j) {
        for (int k = 0; k < 4; ++k) {
            if (secretDigits[j] == userDigits[k] && j == k) {
                ++bull;
            } else if (secretDigits[j] == userDigits[k] && j != k) {
                ++cow;
            }
        }
    }

    if (cow == 0 && bull == 0) {
        std::cout << "You have nothing, looser." << std::endl;
    } else if (cow == 0 && bull != 4) {
        std::cout << "You have " << bull << " bull." << std::endl;
    } else if (bull == 0) {
        std::cout << "You have " << cow << " cow." << std::endl;
    } else if (bull != 4) {
        std::cout << "You have " << bull << " bull and " << cow << " cow." << std::endl;
    }

    std::cout << std::endl;
}
