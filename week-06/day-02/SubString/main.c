#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int substr(char *a, char *b)
{
    if (strlen(a) == strlen(b)) {
        return -1;
    } else {
        if (strstr(a, b) != NULL || strstr(b, a) != NULL) {
            return 1;
        }
    }

    return 0;
}

int main()
{
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the shorter string is a substring of the longer one and
    // returns 0 otherwise
    // If the two strings has the same lenght than the function should return -1

    char str1[20];
    char str2[20];

    printf("String1: ");
    scanf("%s", str1);
    printf("String2: ");
    scanf("%s", str2);

    printf("%d", substr(str1, str2));

    return 0;
}