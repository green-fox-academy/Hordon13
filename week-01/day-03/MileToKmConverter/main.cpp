#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for an integer that is a distance in kilometers,
    // then it converts that value to miles and prints it

    double distance;
    std::cout << "Distance in kilometer?" << std::endl;
    std::cin >> distance;

    distance *= 0.621371;

    std::cout << "The distance in miles is: " << distance << std::endl;
    return 0;
}