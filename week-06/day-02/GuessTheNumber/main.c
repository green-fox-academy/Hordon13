#include <stdio.h>

int main()
{

    // Write a program that stores a number, and the user has to figure it out.
    // The user can input guesses, after each guess the program would tell one
    // of the following:
    //
    // The stored number is higher
    // The stried number is lower
    // You found the number: 8

    int number = 9;
    int guess;

    do {
        printf("Guess a number: ");
        scanf("%d", &guess);
        if (guess > number) {
            printf("The stored number is higher\n");
        } else if (guess < number) {
            printf("The stored number is lower\n");
        }

    } while (guess != number);

    printf("You found the number: %d\n", number);

    return 0;
}