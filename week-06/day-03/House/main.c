#include <stdio.h>

/*
Create a struct that represents a House
It should store:
 - The address of the house
 - The price in EUR
 - The number of rooms
 - The area of the house in square meters
The market price of the houses is 400 EUR / square meters
Create a function that takes a pointer to a house and decides if it's worth to buy
(if the price is lower than the calculated price from it's area)
Create a function that takes an array of houses (and it's length), and counts the
houses that are worth to buy.
*/

typedef struct {
    char adr[30];
    float price;
    int rooms;
    int area;
} house_t;

int worthIt(house_t *house)
{
    float priceValue = house->price / house->area;
    if (priceValue > 400)
        return 0;
    else
        return 1;
}

int numWorth(house_t market[], int arrSize)
{
    int count = 0;
    for (int i = 0; i < arrSize; ++i) {
        if (worthIt(&market[i]) == 1) {
            count++;
        }
    }

    return count;
}

int main()
{

    house_t house1;
    house_t house2;
    house_t house3;

    house1.area = 120;
    house2.area = 120;
    house3.area = 120;

    house1.price = 48000; // 400
    house2.price = 50000; // 400+
    house3.price = 20000; // 400-


    house_t rozsadomb[3] = {house1, house2, house3};
    int size = sizeof(rozsadomb) / sizeof(house_t);

    printf("There is %d buy-worthy house on the market.", numWorth(rozsadomb, size));

    return 0;
}