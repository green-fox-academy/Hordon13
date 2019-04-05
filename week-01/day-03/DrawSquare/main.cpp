#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // square like this:
    //
    //
    // %%%%%%
    // %    %
    // %    %
    // %    %
    // %    %
    // %%%%%%
    //
    // The square should have as many lines as the number was

    int input = 6;

    for (int i = 0; i < input; ++i) {
        for (int j = 0; j < input; ++j) {
            if(i == 0 || i == input-1 || j == 0 || j == input-1){
                std::cout << "%";
            } else{
                std::cout << " ";
            }
        }

        std::cout << "\n";
    }

    return 0;
}