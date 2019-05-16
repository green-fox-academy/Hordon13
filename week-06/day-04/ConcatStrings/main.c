#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// write a function which takes 2 strings as parameter, concatenates them together and returns it back.
// Test it for long and empty strings as well.
// Try to use the least amount of memory that's possible.

char *concatenate(char *str1, char *str2)
{
    int size = strlen(str1) + strlen(str2) + 1;

    char *ptr = (char *) malloc(size * sizeof(char));

    strcpy(ptr, str1);
    strcat(ptr, str2);

    return ptr;
}

int main()
{
    char str1[256];
    char str2[256];
    printf("Enter a string: ");
    scanf("%s", str1);
    printf("Enter an another string: ");
    scanf("%s", str2);

    printf("%s", concatenate(str1, str2));

    return 0;
}