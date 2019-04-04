#include <iostream>
#include <string>

void unique(int[], int);

int main(int argc, char* args[]) {

    //  Create a function that takes a list of numbers as a parameter
    //  Don't forget you have pass the size of the list as a parameter as well
    //  Returns a list of numbers where every number in the list occurs only once

    //  Example
    int numbers[] = {1, 11, 34, 11, 52, 61, 1, 34};
    int numSize = sizeof(numbers) / sizeof(int);
    unique(numbers, numSize);



    //  should print: `[1, 11, 34, 52, 61]`

    return 0;
}

void unique(int ar[], int size){

    int newArray[8]{};

    for (int i = 0; i < size; ++i) {
        int temp1 = ar[i];
        for (int j = 0; j < size; ++j) {
            int temp2 = ar[j];
            if (temp1 != temp2){
                newArray[i] = temp1;
            } else if (temp1 == temp2 && j > i ) {
                newArray[i] = temp1;
            }
        }

    }

    for (int i = 0; i < 8; ++i) {
        std::cout << newArray[i] << std::endl;
    }
}