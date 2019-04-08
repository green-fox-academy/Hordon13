#include <iostream>

int valueCheck(int [], int, int);

int main() {
    // Create a function which takes an array (and it's lenght) and a number as a parameter
    // the function should return index where it found the given value
    // if it can't find the number return -1

    int numbers[] = {2, 4, 7, 12, 43, 53, 101, 24, 3};
    int numbersSize = sizeof(numbers) / sizeof(int);

    int numCheck;
    std::cout << "NUMBER TO CHECK IN ARRAY?" << std::endl;
    std::cin >> numCheck;

    std::cout << valueCheck(numbers, numbersSize, numCheck) << std::endl;

    return 0;
}

int valueCheck(int arr[], int size, int check) {
    int found = -1;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == check) {
            found = i;
        }
    }

    return found;
}