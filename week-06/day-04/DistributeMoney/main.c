#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The money you have to distribute is $1024
// Generate a random number between 20 and 50 = relative number.
// Allocate an array for them. Each element of the array will represent a relative.
// You need to generate a random number between 0 and the number of relatives to decide which one is the winner.
// The winner always gets the half of the remaining money. You need to generate random numbers until all the money is gone.
// Print the amount of money each relative got on the party. Print 0 for the unlucky ones.

//For example: 0,0,0,0,128,4,0,0,2,0,512,0,0,0,0,0,0,32,0,64,0,0,1,8,0,0,16,256

typedef struct {
    int money;
} relatives_t;

void distribute(relatives_t *relatives, int size)
{
    int heritage = 1024;
    int index;

    int iSize = 0;
    int *indexes = (int *) realloc(indexes,iSize * sizeof(int));

    while (heritage > 1) {
        index = rand() % size + 1;
        ++iSize;

        relatives[index].money = heritage / 2;
        heritage -= heritage / 2;
    }
}

int main()
{
    srand(time(NULL));

    int num = rand() % 31 + 20;
    relatives_t *ptr = (relatives_t *) calloc(num, sizeof(relatives_t));
    distribute(ptr, num);

    for (int i = 0; i < num; ++i) {
        printf("%d, ", ptr[i].money);
    }


    return 0;
}