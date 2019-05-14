#include <stdio.h>

int main()
{

// Write a program that stores 3 sides of a cuboid as variables (doubles)
// You should get these variables via console input
// The program should write the surface area and volume of the cuboid like:
//
// Surface Area: 600
// Volume: 1000

    double a;
    double b;
    double c;

    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    double surface = a * b * c;
    double area = 2 * (a * b) + 2 * (a * c) + 2 * (b * c);

    printf("%.2f\n", surface);
    printf("%.2f\n", area);

    return 0;
}