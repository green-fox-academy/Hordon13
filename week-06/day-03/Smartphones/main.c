#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum screenSize {
    BIG, MEDIUM, SMALL
};

typedef struct {
    char name[256];
    int year;
    enum screenSize screenType;

} smarphone_t;

int countLines()
{
    FILE *fptr = fopen("../phones.txt", "r");

    char line[256];
    int count = 0;
    while (fgets(line, sizeof(line), fptr) != NULL) {
        count++;
    }

    fclose(fptr);
    return count;
}

smarphone_t addPhone(char *phoneData)
{
    smarphone_t phone;

    strcpy(phone.name, strtok(phoneData, " "));

    phone.year = atoi(strtok(NULL, " "));

    char *size = strtok(NULL, " ");

    if (atoi(size) >= 15) {
        phone.screenType = BIG;
    } else if (atoi(size) >= 12) {
        phone.screenType = MEDIUM;
    } else {
        phone.screenType = SMALL;
    }

    return phone;
}

void fillArray(smarphone_t arr[])
{
    FILE *fptr = fopen("../phones.txt", "r");

    char line[256];
    int count = 0;

    while (fgets(line, 256, fptr) != NULL) {
        arr[count] = addPhone(line);
        count++;
    }

    fclose(fptr);
}

void get_oldest_phone(smarphone_t arr[], int size)
{
    int oldestAge = 3000;
    char oldestName[100];
    for (int i = 0; i < size; ++i) {
        if (arr[i].year < oldestAge) {
            strcpy(oldestName, arr[i].name);
            oldestAge = arr[i].year;
        }
    }

    printf("The %s is the oldest device in the database.\n", oldestName);
}

void get_screen_size_count(smarphone_t arr[], int size, enum screenSize sSize)
{
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i].screenType == sSize) {
            count++;
        }
    }

    printf("There are %d phones with the given screen size.\n", count);
}

void priceList(smarphone_t arr[], int size)
{
    FILE *fptr = fopen("../prices.txt", "w");

    for (int i = 0; i < size; ++i) {

        int price = 300;

        if (arr[i].screenType == BIG) {
            price *= 2;
        } else if (arr[i].screenType == MEDIUM) {
            price += 100;
        }

        int loss = (2019 - arr[i].year) * 50;
        if (loss > 250) {
            price -= 250;
        } else {
            price -= loss;
        }

        fprintf(fptr, "%s %d \n", arr[i].name, price);
    }

    fclose(fptr);
}

int main()
{
    int size = countLines();

    smarphone_t catalog[size];
    fillArray(catalog);

    get_oldest_phone(catalog, size);
    get_screen_size_count(catalog, size, BIG);
    priceList(catalog, size);

    return 0;
}