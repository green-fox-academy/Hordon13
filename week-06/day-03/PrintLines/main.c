#include <stdio.h>
#include <string.h>

// Write a program that opens a file called "my-file.txt", then prints
// each line from the file.
// You will have to create the file, for that you may use C-programming, although it is not mandatory

int main()
{
    FILE *fpointer;
    fpointer = fopen("../my-file.txt", "r");
    char line[100];

    while (fgets(line, 100, fpointer) != NULL) {
        printf("%s", line);
    }

    fclose(fpointer);

    return 0;
}