#include <stdio.h>
#include <stdlib.h>

//Read the size of a matrix(don't have to be squared matrix) from the console.
//Allocate memory dynamically for the elements of the matrix, then read the elements.
//Create a function which can calculate the n-th percentile of the elements.
//Calculate the 80-th and the 90-th percentile.

int percentile(float n, int arr[], int size)
{
    int index = (size * n / 100) - 1;

    return arr[index];
}

int main()
{
    int size;
    printf("Size of the matrix: ");
    scanf("%d", &size);

    int *ptr = (int *) malloc(size * sizeof(int));

    for (int i = 0; i < size; ++i) {
        printf("Add en element to the matrix: ");
        scanf("%d", &ptr[i]);
    }

    printf("%d", percentile(80, ptr, size));

    return 0;
}