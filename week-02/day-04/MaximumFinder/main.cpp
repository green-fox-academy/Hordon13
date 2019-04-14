#include <iostream>

int maximumFinder(int[], int, int);

int main()
{
    int testaArray[] = {12, 3, 5, 4, 19, 11, 5, 13};
    int arrSize = sizeof(testaArray) / sizeof(int);

    std::cout << maximumFinder(testaArray, arrSize, 0) << std::endl;

    return 0;
}

int maximumFinder(int arr[], int size, int max)
{
    if (size - 1 < 0) {
        return max;
    }

    if (arr[size - 1] > max) {
        max = arr[size - 1];
    }

    return maximumFinder(arr, size - 1, max);
}