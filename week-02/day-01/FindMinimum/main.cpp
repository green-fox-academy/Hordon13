#include <iostream>

int *minimum(int[], int);

int main() {
    // Create a function which takes an array (and its length) as a parameter
    // and returns a pointer to its minimum value

    int numbers[] = {12, 4, 66, 101, 87, 3, 15};
    int numbersSize = sizeof(numbers) / sizeof(int);

    int *min = nullptr;

    min = minimum(numbers, numbersSize);

    std::cout << *min << std::endl;

    return 0;
}

int *minimum(int arr[], int size) {

    int min = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] < arr[min]) {
            min = i;
        }
    }

    return &arr[min];
}