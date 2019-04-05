#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000

    double a = 12;
    double b = 21;
    double c = 13;

    double surface = 2 * (a*b + a*c + b*c);
    double volume = a*b*c;

    std::cout << "Surface Area: " << surface << std::endl;
    std::cout << "Volume: " << volume << std::endl;

    return 0;
}