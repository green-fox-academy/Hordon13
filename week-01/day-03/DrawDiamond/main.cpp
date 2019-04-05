#include <iostream>

int main(int argc, char* args[]) {

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

    if(num % 2 != 0){
        num++;
    }

    for (int i = 0; i < num/2; ++i) {

        for (int j = 0; j < (num/2 - 1) - i; ++j) {
            std::cout << " ";
        }

        for (int k = 1; k < (2 * (i + 1)); ++k) {
            std::cout << "*";
        }

        std::cout << "\n";
    }

    for (int i = 0; i < num/2; ++i) {

        for (int j = 0; j < (num/2 - 1) - i; ++j) {
            std::cout << "*";
        }

       for (int k = 1; k < (2 * (i + 1)); ++k) {
            std::cout << " ";
        }

        std::cout << "\n";
    }
    return 0;
}