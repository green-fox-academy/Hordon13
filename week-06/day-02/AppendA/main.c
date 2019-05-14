#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *append(char *str)
{
    char a[2] = "a";
    return strcat(str, a);
}

int main()
{
    // Create a program which asks for a string and stores it
    // Create a function which takes a string as a parameter and
    // appends a character 'a' to the end of it and returns the new string

    char str[20];
    printf("String: ");
    scanf("%s", str);
    printf("%s", append(str));

    return 0;
}