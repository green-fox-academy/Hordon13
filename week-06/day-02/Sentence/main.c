#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter,
// and splits a string to words by space
// solve the problem with the proper string.h function

void words(char *sentence)
{
    char * word = strtok(sentence, " ");
    while (word != NULL) {
        puts(word);
        word = strtok(NULL, " ");
    }
}

int main()
{
    printf("Type in a sentence:\n");
    char string[256];
    gets(string);

    words(string);

    return (0);
}