#include <iostream>
#include <string>

void unique(int[], int);
void occurrence(int[], int);

int main(int argc, char *args[]) {

    //  Create a function that takes a list of numbers as a parameter
    //  Don't forget you have pass the size of the list as a parameter as well
    //  Returns a list of numbers where every number in the list occurs only once

    //  Example
    int numbers[] = {1, 11, 34, 11, 52, 61, 0, 1, 34, 1};
    int numSize = sizeof(numbers) / sizeof(int);
    unique(numbers, numSize);

    //  should print: `[1, 11, 34, 52, 61]`

    return 0;
}

void unique(int ar[], int size) {

    int check[size];

    //int newSize = 0;

    for (int i = 0; i < size; ++i) {
        int sum = 0;

        for (int j = 0; j < size; ++j) {
            if (ar[i] == ar[j] && i != j) {
                //voltemar
                //if
                ++sum;
            }
        }
        check[i] = sum;
    }


    // Print
    for (int k = 0; k < size; ++k) {
        std::cout << check[k] << " ";
    }
    std::cout << "\n";

    for (int k = 0; k < size; ++k) {
        //std::cout << collect[k] << " ";
    }
    std::cout << "\n";
}

void occurrence(int arr[], int size){


}