#include <iostream>
#include <string>

    //  Create a function that takes a list of numbers as parameter
    //  Don't forget you have to pass the size of the list as a parameter as well
    //  Returns a list where the elements are sorted in ascending numerical order by using bubble sort
    //  Make a second boolean parameter, if it's `true` sort that list descending

void bubble (int[], int);

int main(int argc, char* args[])
{

    int list[]{5, 1, 4, 2, 8, 9, 3, 7, 6};
    int listSize = sizeof(list) / sizeof(int);

    bubble(list, listSize);

    for (int i = 0; i < listSize; ++i) {
        std::cout << list[i] << std::endl;
    }

    return 0;
}

void bubble (int input[], int size){

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (input[j] > input[j+1]){
                std::swap(input[j], input[j+1]);
            }
        }

    }
}