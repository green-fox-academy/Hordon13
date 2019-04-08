#include <iostream>

int main() {
    // Add two numbers using pointers

    int a = 20;
    int b = 17;

    int *aPointr = &a;
    int *bPointr = &b;

    std::cout << *aPointr + *bPointr << std::endl;

    return 0;
}