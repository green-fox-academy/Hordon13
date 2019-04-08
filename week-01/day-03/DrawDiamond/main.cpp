#include <iostream>

int main(int argc, char *args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // diamond like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //  *****
    //   ***
    //    *
    //
    // The diamond should have as many lines as the number was

    int num;
    std::cout << "What is your number?" << std::endl;
    std::cin >> num;

    /*
     * Concept: diamond = 2 pyramid.
     * Even parity: The first and the second pyramid has the same size, they are symmetric.
     * Odd parity: the first pyramid size is num/2 + 1 and the second pyramid is shifted with +1 space.
     * This +1 could be assigned to a variable (parity) -» if parity = odd then add +1 to first pyramid rows
     * and add +1 space at second pyramid.
     * An if condition at decide if the parity is even or odd, and set the parity variable regarding.
     */

    // Evaluate parity

    int parity;

    if (num % 2 == 0) {
        parity = 0;
    } else {
        parity = 1;
    }


    // First pyramid

    for (int i = 0; i < num / 2 + parity; ++i) {

        for (int j = 0; j < (num / 2 + parity - 1) - i; ++j) {
            std::cout << " ";
        }

        for (int k = 1; k < (2 * (i + 1)); ++k) {
            std::cout << "*";
        }

        std::cout << std::endl;
    }

    // Second pyramid

    for (int i = 0; i < num / 2; ++i) {

        for (int j = 0; j < i + parity; ++j) {
            std::cout << " ";
        }

        for (int k = ((num / 2) * 2 - 1 - (2 * i)); k > 0; --k) {
            std::cout << "*";
        }

        std::cout << std::endl;
    }

    return 0;
}