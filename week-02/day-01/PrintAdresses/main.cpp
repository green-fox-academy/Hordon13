#include <iostream>

void printArray(int[], int);

int main() {
    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the memory addresses of the elements in the array

    int input[5];

    for (int i = 0; i < 5; ++i) {
        std::cout << "Give me a number (" << i + 1 << "): " << std::endl;
        std::cin >> input[i];
    }

    printArray(input, 5);

    return 0;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << &arr[i] << " ";
    }
    std::cout << "\n";
}