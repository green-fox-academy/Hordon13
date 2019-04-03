#include <iostream>

int main(int argc, char *args[]) {
    // Write a program that stores a number, and the user has to figure it out.
    // The user can input guesses, after each guess the program would tell one
    // of the following:
    //
    // The stored number is higher
    // The stried number is lower
    // You found the number: 8

    int num = 8;
    int guess;

    do {
        std::cout << "What is your guess?" << std::endl;
        std::cin >> guess;
        if (num > guess) {
            std::cout << "The stored number is higher" << std::endl;
        } else if (num < guess) {
            std::cout << "The stored number is lower" << std::endl;
        }
    } while (num != guess);

    std::cout << "You found the number: " << num << std::endl;

    return 0;
}