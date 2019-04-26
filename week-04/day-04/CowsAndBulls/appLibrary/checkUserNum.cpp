#include <iostream>
#include <ctype.h>

#include "checkUserNum.h"
#include "generateSecret.h"

void checkUserNum(std::string userInput)
{
    for (int i = 0; i < userInput.length(); ++i) {
        if (!isdigit(userInput.at(i))) {
            throw std::string("Only numbers are allowed as input!");
        }
    }

    int userNum = std::stoi(userInput);

    if (userNum < 1000 || userNum > 9999) {
        throw std::string("Number must have 4 digit!");
    } else if (!check(userNum)) {
        throw std::string("All digit has to be different!");
    }
}