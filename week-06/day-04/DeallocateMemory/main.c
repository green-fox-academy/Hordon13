
#include <stdio.h>
#include <stdlib.h>

// with malloc
// please allocate a 10 long array and fill it with even numbers then print the whole array
// please deallocate memory without using free


int main()
{
    int *pointer = NULL;
    pointer = (int *) malloc(10 * sizeof(int));

    int count = 0;
    int i = 0;
    while (count != 10) {
        if (i % 2 == 0) {
            pointer[count] = i;
            count++;
        }
        i++;
    }

    for (int j = 0; j < 10; ++j) {
        printf("%d\n", pointer[j]);
    }

    realloc(pointer, 0);

    return 0;
}