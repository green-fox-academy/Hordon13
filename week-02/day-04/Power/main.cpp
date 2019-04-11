#include <iostream>

int power(int, int);

int main() {

    std::cout << power(2, 4) << std::endl;

    return 0;
}

int power(int base, int n) {

    if (n == 1) {
        return base;
    }

    return base * power(base, n - 1);
}