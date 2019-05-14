#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int indexOf(char c, char *str)
{

    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == c) {
            return i;
        }
    }

    return -1;
}

int main()
{
    // Create a program which asks for a string and a character and stores them
    // Create a function which takes a string and a character as a parameter and
    // if the given character is in the string, it should return the index of the
    // first appearance (in the given string) otherwise the function should return -1
    //
    // Example:
    //
    // Case 1:
    //
    // given_string = "embedded"
    // given_char = 'd'
    //
    // the function should return: 4, because this is the index of the first appearance of char 'd'
    //
    //
    // Case 2:
    //
    // given_string = "embedded"
    // given_char = 'a'
    //
    // the function should return: -1, because there is no 'a' in the word "embedded"
    //

    char c;
    char str[20];

    printf("Char: ");
    scanf("%c", &c);
    printf("String: ");
    scanf("%s", str);

    printf("%d", indexOf(c, str));


    return 0;
}