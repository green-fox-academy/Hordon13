#include <stdio.h>
#include <stdlib.h>

// Prompt the user to enter a number. -> This number will be X.
// Allocate memory for X numbers.
// Prompt the user to enter X numbers.
// Allocate memory for Y numbers, which is the sum of the X numbers.
// Fill that array with from 1 to Y, then print them.

int main()
{
    int *pointerX = NULL;
    int *pointerY = NULL;
    puts("Enter a number: ");
    int num = 0;
    scanf("%d", &num);

    pointerX = (int *) malloc(num * sizeof(int));

    int input;
    int sum = 0;
    for (int i = 0; i < num; ++i) {
        puts("Enter numbers: ");
        scanf("%d", &input);
        pointerX[i] = input;
        sum += input;
    }

    pointerY = (int *) malloc(sum * sizeof(int));
    for (int j = 0; j < sum; ++j) {
        pointerY[j] = j;
    }

    for (int k = 0; k < num; ++k) {
        printf("%d", pointerX[k]);
    }

    for (int k = 0; k < sum; ++k) {
        printf("\n%d", pointerY[k]);
    }

    free(pointerX);
    free(pointerY);

    return 0;
}