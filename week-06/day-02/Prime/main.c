#include <stdio.h>
#include <stdlib.h>

int prime(long int num){

    for (long int i = 2; i < num; ++i) {
        if (num % i == 0){
            return 0;
        }
    }

    return 1;
}

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter
    // and returns 1 if the number is a prime number and 0 otherwise
    // (in this case 0 is not considered as a prime number)

    long int num;
    //printf("%d\n", sizeof(num));
    printf("Number: ");
    scanf("%ld", &num);

    printf("%d", prime(num));

    return 0;
}