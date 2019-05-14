#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int legthStrFunc(char *name)
{
    return strlen(name);
}

int legthNoStrFunc(char *name)
{
    int count = 0;
    while (*name != 0) {
        name++;
        count++;
    }

    return count;
}

int main()
{
    // Create a program which asks for the name of the user and stroes it
    // Create a function which takes a string as a parameter and returns the lenght of it
    // Solve this exercie with and without using string.h functions

    char name[20];
    printf("Name: ");
    scanf("%s", name);
    printf("%d\n", legthNoStrFunc(name));
    printf("%d\n", legthStrFunc(name));

    return 0;
}