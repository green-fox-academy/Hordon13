#include <stdio.h>
#include "area.h"

int area(double pi, double r)
{
    double area = r * r * pi;
    printf("The area is: %.2f", area);
}