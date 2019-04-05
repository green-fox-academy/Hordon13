#include <iostream>

int main(int argc, char *args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // pyramid like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //
    // The pyramid should have as many lines as the number was

    int num;
    std::cout << "What is your number?" << std::endl;
    std::cin >> num;

    for (int i = 0; i < num; ++i) {

        for (int j = 0; j < (num - 1) - i; ++j) {
            std::cout << " ";
        }

        for (int k = 1; k < (2 * (i + 1)); ++k) {
            std::cout << "*";
        }

        std::cout << "\n";
    }

    return 0;
}

