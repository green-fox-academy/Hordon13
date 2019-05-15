#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Create a point struct which has two float variables: x and y
Create a function that constructs a point
It should take it's x and y coordinate as parameter
Create a function that takes 2 points and returns the distance between them
Example:
int main()
{
	point_t p1 = create_point(1, 1);
	point_t p2 = create_point(1, 5.5);
	float dist = distance(p1, p2);
	printf("%f", dist);
	return 0;
}
*/

typedef struct {
    float x;
    float y;
} point_t;

point_t createPoint(float x, float y)
{
    point_t point;
    point.x = x;
    point.y = y;
    return point;
}

float distance(point_t p1, point_t p2)
{
    float a = p1.x - p2.x;
    float b = p1.y - p2.y;

    return sqrtf((a * a) + (b * b));
}

int main()
{
    point_t p1 = createPoint(1, 1);
    point_t p2 = createPoint(1, 5.5);
    float dist = distance(p1, p2);
    printf("%.2f", dist);
    return 0;
}