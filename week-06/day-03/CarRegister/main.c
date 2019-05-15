#include <string.h>
#include <stdio.h>

/* Write a car register!
 * You should store the following data in a structure, called "car":
 *  - the manufacturer's name (which is shorter than 256 characters)
 *  - the price of the car (in euros, stored as a floating point number)
 *  - the year of manufacture
 *  - the type of the transmission (as a custom type, see below)
 *
 * You should store the transmission type in an enumeration ("transmission"),
 * the valid types are:
 *  - manual
 *  - automatic
 *  - CVT
 *  - semi-automatic
 *  - dual-clutch
 *
 * The "car"-s are stored in an array.
 *
 * Write the following functions:
 *  - get_older_cars_than(struct car* array, int array_length, int age)
 *      - it returns the count of the older cars than "age"
 *  - get_transmission_count(struct car* array, int array_length, enum transmission trnsm)
 *      - it returns the count of cars which has "trnsm" transmission
 */

enum transmission {
    manual, automatic, CVT, semi_automatic, dual_clutch
};

typedef struct {
    char manufacturer[256];
    float price;
    int year;
    enum transmission type;
} car_t;

int get_older_cars_than(car_t arr[], int arrSize, int year)
{
    int count = 0;
    for (int i = 0; i < arrSize; ++i) {
        if (arr[i].year < year) {
            count++;
        }
    }

    return count;
}

int get_transmission_count(car_t arr[], int arrSize, enum transmission trnsm)
{
    int count = 0;
    for (int i = 0; i < arrSize; ++i) {
        if (arr[i].type == trnsm) {
            count++;
        }
    }

    return count;
}

int main()
{
    car_t car1;
    car_t car2;
    car_t car3;

    car1.year = 1995;
    car2.year = 2003;
    car3.year = 2002;

    car1.type = manual;
    car2.type = automatic;
    car3.type = automatic;

    car_t allCar[] = {car1, car2, car3};
    int size = sizeof(allCar) / sizeof(car_t);

    printf("There is %d car with automatic transmission, and there is %d car older than 19 year.",
           get_transmission_count(allCar, size, automatic), get_older_cars_than(allCar, size, 2000));

    return 0;
}