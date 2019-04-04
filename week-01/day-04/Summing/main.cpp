#include <iostream>
#include <string>

int sum(int);

int main(int argc, char *args[]) {

    // Write a function called `sum` that returns the sum of numbers from zero to the given parameter

    int num;
    std::cout << "Gimme a number!" << std::endl;
    std::cin >> num;
    std::cout << sum(num) << std::endl;

    return 0;
}

int sum(int a) {
    int sum = 0;
    for (int i = 0; i < a; ++i) {
        sum += i;
    }

    return sum;
}