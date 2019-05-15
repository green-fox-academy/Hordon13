#include <stdio.h>
#include <string.h>

// Write a function that takes a filename as string,
// then returns the number of lines the file contains.
// It should return zero if it can't open the file

int countLine(char *path)
{
    FILE *filePointer = fopen(path, "r");

    if (filePointer == NULL) {
        return 0;
    }

    char line[256];
    int count = 0;
    while (fgets(line, 256, filePointer) != NULL) {
        count++;
    }

    return count;
};

int main()
{
    printf("%d\n", countLine("../empty.txt"));
    printf("%d\n", countLine("../hello.txt"));

    return 0;
}