#include <stdio.h>
#include <stdlib.h>

// please allocate a 10 long array and fill it with even numbers
// please allocate a 10 long array and fill it with odd numbers
// select an array, and push the elements into the another array
// print the array in descending order
// delete the arrays after you don't use them

int main()
{
    int *ptrEven = NULL;
    int *ptrOdd = NULL;
    ptrEven = (int *) malloc(10 * sizeof(int));
    ptrOdd = (int *) malloc(10 * sizeof(int));

    int countEven = 0;
    int countOdd = 0;
    int i = 0;
    while (countEven != 10 || countOdd != 10) {
        if (i % 2 == 0) {
            ptrEven[countEven] = i;
            ++countEven;
        } else {
            ptrOdd[countOdd] = i;
            ++countOdd;
        }
        i++;
    }

    free(ptrOdd);
    ptrOdd = ptrEven;

    for (int j = 0; j < 10; ++j) {
        printf("%d", ptrOdd[9 - j]);
    }

    free(ptrEven);

    return 0;
}