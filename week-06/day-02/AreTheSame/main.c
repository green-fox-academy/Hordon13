#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int equal(char *a, char *b)
{
    if (*a == *b) {
        return 1;
    }

    return 0;
}

int main()
{
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the two strings are the same and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    char a[20];
    char b[20];

    printf("Strings: ");
    scanf("%s %s", a, b);
    printf("%d", equal(a, b));

    return 0;
}