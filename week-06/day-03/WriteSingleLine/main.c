#include <stdio.h>
#include <string.h>

// Open a file called "my-file.txt"
// Write your name in it as a single line

int main()
{

    FILE *fpointer = fopen("../my-file.txt", "w");

    fputs("Horvath Donat", fpointer);

    fclose(fpointer);

    return 0;
}