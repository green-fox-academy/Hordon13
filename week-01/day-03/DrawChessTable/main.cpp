#include <iostream>

int main(int argc, char* args[]) {

    // Crate a program that draws a chess table like this
    //
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if((i + j) % 2 == 0){
                std::cout << "%";
            } else{
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}