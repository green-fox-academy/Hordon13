#include <stdio.h>
#include <stdlib.h>

#include "area.h"

int main()
{
    double pi = 3.14;
    double r;

    printf("Radius: ");
    scanf("%lf", &r);

    area(pi, r);

    return 0;
}