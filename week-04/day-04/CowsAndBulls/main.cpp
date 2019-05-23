#include <iostream>

#include "generateSecret.h"
#include "checkUserNum.h"
#include "feedback.h"

int main()
{
    bool isPlay;
    std::cout << "*********************************" << std::endl;
    std::cout << "          COWS AND BULLS"        << std::endl;
    std::cout << "*********************************" << std::endl;
    std::cout << std::endl;

    do {

        int secretNum = generate();
        std::string userInput;
        int userNum = 0;
        int trials = 0;

        do {
            std::cout << "Enter your guess: ";
            std::cin >> userInput;
            try {
                checkUserNum(userInput);
            } catch (std::string &e) {
                std::cout << e << std::endl;
                continue;
            }

            ++trials;

            userNum = std::stoi(userInput);

            feedback(secretNum, userNum);

        } while (secretNum != userNum);

        std::cout << "Congratulation! You find out the secret number: " << secretNum << ", within " << trials
                  << " trial."
                  << std::endl;

        char answer;
        std::cout << "Do you want to play again? [Y/N]" << std::endl;
        std::cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            isPlay = true;
        } else if (answer == 'n' || answer == 'N') {
            isPlay = false;
        }

    } while (isPlay);

    return 0;
}
