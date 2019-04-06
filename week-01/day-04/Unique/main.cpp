#include <iostream>
#include <string>

void selectionSort(int[], int);

void unique(int[], int);

void print(int[], int);

int main(int argc, char *args[]) {

    //  Create a function that takes a list of numbers as a parameter
    //  Don't forget you have pass the size of the list as a parameter as well
    //  Returns a list of numbers where every number in the list occurs only once

    int numbers[] = {1, 11, 34, 11, 52, 61, 0, 1, 34, 1, 61, 72};
    int size = sizeof(numbers) / sizeof(int);

    unique(numbers, size);

    return 0;
}

void unique(int arr[], int size) {

    selectionSort(arr, size);
    int newSize = 1;

    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] < arr[i + 1]) {
            newSize++;
        }
    }

    int newArray[newSize];

    int index = 0;
    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] < arr[i + 1]) {
            newArray[index] = arr[i];
            ++index;
        }
    }

    newArray[newSize - 1] = arr[size - 1];
    print(newArray, newSize);
}

void selectionSort(int arr[], int size) {

    for (int i = 0; i < size; i++) {
        int min = i;
        for (int j = i; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        std::swap(arr[i], arr[min]);
    }
}

void print(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}