#include <iostream>

#include "generateSecret.h"
#include "checkUserNum.h"
#include "feedback.h"

int main()
{
    int secretNum = generate();
    std::cout << secretNum << std::endl;
    std::string userInput;
    int userNum = 0;
    int trials;

    do {
        std::cout << "Enter your guess: ";
        std::cin >> userInput;
        ++trials;
        try {
            checkUserNum(userInput);
        } catch (std::string &e) {
            std::cout << e << std::endl;
            --trials;
            continue;
        }

        userNum = std::stoi(userInput);

        feedback(secretNum, userNum);

    } while (secretNum != userNum);

    std::cout << "\nCongratulation! You find out the secret number: " << secretNum << ", within " << trials << " trial."
              << std::endl;

    return 0;
}