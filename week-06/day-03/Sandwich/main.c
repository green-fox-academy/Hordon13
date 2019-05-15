#include <stdio.h>
#include <string.h>

/*
Create a sandwich struct
It should store:
 - name
 - price (float)
 - weight (float)
Create a function which takes two parameters and returns the price of your order.
The parameters should be:
 - a sandwich struct
 - and an integer that represents how many sandwiches you want to order
*/

typedef struct {
    char name[30];
    float price;
    float weigth;
} sandwich_t;

int price(sandwich_t *sandwich, int num)
{
    return num * sandwich->price;
}

int main()
{

    sandwich_t bigmac;
    strcpy(bigmac.name, "Big Mac");
    bigmac.price = 1.8;
    bigmac.weigth = 24.5;

    printf("Your total order costs %d$.", price(&bigmac, 5));

    return 0;
}