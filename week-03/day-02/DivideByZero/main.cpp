#include <iostream>
#include <fstream>

int divide(int);

int main()
{
// Create a function that takes a number
// divides ten with it,
// and prints the result.
// It should print "fail" if the parameter is 0

    int num;
    std::cout << "Your number?" << std::endl;
    std::cin >> num;

    try {

        if (num == 0) {
            throw std::string("Can't divide by 0");
        }

        std::cout << divide(num) << std::endl;

    } catch (std::string &e) {
        std::cout << e << std::endl;
    }

    return 0;
}

int divide(int num)
{
    return 10 / num;
}