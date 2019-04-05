#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two integers
    // The first represents the number of chickens the farmer has
    // The second represents the number of pigs owned by the farmer
    // It should print how many legs all the animals have

    int chicken;
    int pig;

    std::cout << "How many chicken do you have?" << std::endl;
    std::cin >> chicken;

    std::cout << "How many pigs do you have?" << std::endl;
    std::cin >> pig;

    int legs = chicken * 2 + pig * 4;
    std::cout << legs << std::endl;

    return 0;
}