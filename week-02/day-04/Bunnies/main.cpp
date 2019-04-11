#include <iostream>

int bunnies(int);

int main() {

    std::cout << bunnies(7) << std::endl;

    return 0;
}

int bunnies(int num) {

    if (num == 1) {
        return 2;
    }

    return 2 + bunnies(num - 1);
}