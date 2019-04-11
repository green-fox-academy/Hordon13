#include <iostream>

int bunnies(int);

int main() {

    std::cout << bunnies(1) << std::endl;

    return 0;
}

int bunnies(int num) {

    if (num == 1) {
        return 2;
    }

    if (num % 2 == 1) {
        return 2 + bunnies(num - 1);
    } else {
        return 3 + bunnies(num - 1);
    }
}