#include <stdio.h>

// Write a function that takes a car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

enum car_type {
    VOLVO, TOYOTA, LAND_ROVER, TESLA
};

struct car {
    enum car_type type;
    double km;
    double gas;
};

char *switchCar(enum car_type car)
{
    switch (car) {
        case TOYOTA:
            return "Toyota";
        case TESLA:
            return "Tesla";
        case LAND_ROVER:
            return "Land Rover";
        case VOLVO:
            return "Volvo";
        default:
            return "";
    }
}

void carStat(struct car *car)
{
    if (car->type != TESLA)
        printf("Type: %s, km: %.lf, gas: %.lf\n", switchCar(car->type), car->km, car->gas);
    else
        printf("Type: %s, km: %.lf\n", switchCar(car->type), car->km);
}

int main()
{

    struct car volvo;
    struct car tesla;

    volvo.type = VOLVO;
    volvo.km = 321123;
    volvo.gas = 34;

    tesla.type = TESLA;
    tesla.km = 123000;

    carStat(&volvo);
    carStat(&tesla);

    return 0;
}