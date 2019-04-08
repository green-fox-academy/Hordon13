#include <iostream>

void calculations(int[], int);

int main(int argc, char *args[]) {

    // Write a program that asks for a number.
    // It would ask this many times to enter an integer,
    // if all the integers are entered, it should print the sum and average of these
    // integers like:
    //
    // Sum: 22, Average: 4.4

    int repeat;
    std::cout << "Number of integers" << std::endl;
    std::cin >> repeat;

    int input[repeat];
    for (int i = 0; i < repeat; ++i) {
        std::cout << "Give me an integer (" << i + 1 << ")" << std::endl;
        std::cin >> input[i];
    }

    calculations(input, repeat);


    return 0;
}

void calculations(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    double avg = double(sum) / size;

    std::cout << "Sum: " << sum << ", Average: " << avg << std::endl;
}