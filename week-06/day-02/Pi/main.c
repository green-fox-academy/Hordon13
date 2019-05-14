#include <stdio.h>
#include <stdlib.h>

// define a variable called PI with the value of 3.14
// create a function which takes the radius of a circle as a parameter
// and return the area of that cirle
// area = radius * radius * PI

int area(double pi, double r)
{
    double area = r * r * pi;
    printf("The area is: %.2f", area);
}

int main()
{
    double pi = 3.14;
    double r;

    printf("Radius: ");
    scanf("%lf", &r);

    area(pi, r);

    return 0;
}