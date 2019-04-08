#include <iostream>

void swapNums(int *, int *);

int main() {
    // Create a function which swaps the values of 'a' and 'b'
    // This time use a void funtion and pointers

    int a = 10;
    int b = 316;

    swapNums(&a, &b);

    std::cout << a << " " << b << std::endl;

    return 0;
}

void swapNums(int *a, int *b) {
    std::swap(*a, *b);
}