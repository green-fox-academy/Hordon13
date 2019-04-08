#include <iostream>

int *biggest(int[], int);

int main() {
    // Create a program which first asks for a number
    // this number indicates how many integers we want to store in an array
    // and than asks for numbers till the user fills the array
    // It should print out the biggest number in the given array and the memory address of it

    int size;
    std::cout << "Arrays size:" << std::endl;
    std::cin >> size;

    int array[size];

    for (int i = 0; i < size; ++i) {
        std::cout << "Number (" << i + 1 << ")" << std::endl;
        std::cin >> array[i];
    }

    int *high = nullptr;
    high = biggest(array, size);

    std::cout << "The biggest number in the array is " << *high << ", it's memory address is: " << high << std::endl;

    return 0;
}

int *biggest(int arr[], int size) {
    int biggest = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > arr[biggest]) {
            biggest = i;
        }
    }

    return &arr[biggest];
}