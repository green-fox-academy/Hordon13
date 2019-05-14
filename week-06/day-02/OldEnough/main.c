#include <stdio.h>
#include <stdlib.h>

void ageCheck(int age)
{
    if (age >= 18) {
        printf("Old enough");
    } else {
        printf("Too young");
    }
}

int main()
{
    // Create a program which asks for the age of the user and stores it
    // Create a function which takes that age as a parameter and returns if the user is
    // old enough to buy himself alcohol in Hungary

    int age;
    printf("Your age: ");
    scanf("%d", &age);

    ageCheck(age);

    return 0;
}
