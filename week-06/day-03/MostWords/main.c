#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(char *) a - *(char *) b);
}

void sort(char *arr[], int n)
{
    qsort(arr, n, sizeof(char*), compare);
}

int countWord(char *path)
{
    FILE *fptr = fopen(path, "r");
    char line[256];

    int count = 0;
    while (fgets(line, 256, fptr) != NULL) {

        char *word = strtok(line, " \n");

        while (word != NULL) {
            word = strtok(NULL, " \n");
            count++;
        }
    }

    return count;

}

void fillWords(char *arr[], char *path)
{
    FILE *fptr = fopen(path, "r");
    char line[256];

    int count = 0;
    while (fgets(line, 256, fptr) != NULL) {

        char *word = strtok(line, " \n");

        while (word != NULL) {
            word = strtok(NULL, " \n");
            arr[count] = word;
            count++;
        }
    }
}

int main()
{
    int size = countWord("../file.txt");
    char *words[size];
    for (int i = 0; i < size; ++i) {
        words[i] = NULL;
    }

    words[0] = "hello";
    words[1] = "geza";


    //printf("%s", words[1]);


    return 0;
}