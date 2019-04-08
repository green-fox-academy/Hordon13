#include <iostream>

int main() {
    // Create a pointer for each variable and print out the memory addresses of that variables
    // Print out the values of the pointers

    int a = 31;
    double b = 432.2;
    std::string name = "Bob";

    int *aPntr = &a;
    double *bPntr = &b;
    std::string *namePntr = &name;

    std::cout << "Variable a is at " << aPntr << " memory address, and has the value: " << *aPntr << std::endl;
    std::cout << "Variable b is at " << bPntr << ", memory address and has the value: " << *bPntr << std::endl;
    std::cout << "Variable name is at " << namePntr << ", memory address and has the value: " << *namePntr << std::endl;

    return 0;
}