#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// write a function which takes a string and an integer as a parameter.
// The function should return a string where the input string is repeating. The number of repetition is based on the value of the integer parameter.
// For example: Apple, 5 -> AppleAppleAppleAppleApple
// Try to use the least amount of memory that's possible.

char *repeat(char *string, int num)
{
    int size = num * strlen(string) + 1;
    char *str = (char *) malloc(size * sizeof(char));
    strcpy(str, string);

    for (int i = 0; i < num - 1; ++i) {
        strcat(str, string);
    }

    return str;
}

int main()
{
    printf("%s", repeat("apple", 5));

    return 0;
}