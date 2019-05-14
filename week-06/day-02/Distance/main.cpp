#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// returns the distance between the first and last occurance of character 's'

int distance(char *str)
{
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == 's') {
            int first = i;
            int last = first;
            for (int j = i; j < strlen(str); ++j) {
                if (str[j] == 's') {
                    last = j;
                }
            }

            return last - first;
        }
    }
}

int main()
{
    char str[] = "This is a sample string";
    printf("%d", distance(str));

    return 0;
}