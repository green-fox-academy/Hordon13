#include <iostream>

int main(int argc, char *args[]) {

    // Write a program that asks for 5 integers in a row,
    // then it should print the sum and the average of these numbers like:
    //
    // Sum: 22, Average: 4.4

    int int1;
    int int2;
    int int3;
    int int4;
    int int5;

    std::cout << "Number 1" << std::endl;
    std::cin >> int1;

    std::cout << "Number 2" << std::endl;
    std::cin >> int2;

    std::cout << "Number 3" << std::endl;
    std::cin >> int3;

    std::cout << "Nukber 4" << std::endl;
    std::cin >> int4;

    std::cout << "Number 5" << std::endl;
    std::cin >> int5;

    double avg = (int1 + int2 + int3 + int4 + int5) / 5;
    int sum = int1 + int2 + int3 + int4 + int5;

    std::cout << "Sum: " << sum << ", Average: " << avg << std::endl;


    return 0;
}