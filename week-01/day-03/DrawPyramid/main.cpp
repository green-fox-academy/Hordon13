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
        for (int j = 0; j < (2 * num) - 1; ++j) {
            for (int k = 0; k < num-1; ++k) {
                std::cout << " ";
            }
            for (int l = 0; l < 2 * num; ++l) {
                std::cout << "*";
            }
            std::cout << "\n";
        }
    }

    return 0;
}
