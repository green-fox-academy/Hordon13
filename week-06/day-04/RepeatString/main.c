#include <stdio.h>
#include <stdlib.h>

// write a function which takes a string and an integer as a parameter.
// The function should return a string where the input string is repeating. The number of repetition is based on the value of the integer parameter.
// For example: Apple, 5 -> AppleAppleAppleAppleApple
// Try to use the least amount of memory that's possible.

char *repeat(char *string, int num)
{
    char *str = (char *) malloc(num + 1 * sizeof(string));

    for (int i = 0; i < num; ++i) {

    }

    return str;
}

int main()
{

    fprintf("%s", repeat("apple", 5));
    return 0;
}