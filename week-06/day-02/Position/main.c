#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// lists all position where character 'i' is found

void positions(char *str)
{
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == 'i') {
            printf("%d\n", i);
        }
    }
}

int main()
{
    char string[55] = "This is a string for testing";
    positions(string);

    return 0;
}