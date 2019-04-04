#include <iostream>
#include <string>

void factorio(int, int &);

int main(int argc, char *args[]) {

    // - Create a function called `factorio`
    //   it should calculate its input's factorial.
    //   it should not return it, but take an additional integer parameter and overwrite its value.

    int input = 3;
    int output;

    factorio(input, output);
    std::cout << output << std::endl;


    return 0;
}

void factorio(int a, int &b) {
    b = 1;
    for (int i = 1; i <= a; ++i) {
        b *= i;
    }
}