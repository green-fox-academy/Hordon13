#include <iostream>

int numAdd(int);

int main() {


    std::cout << numAdd(5) << std::endl;

    return 0;
}

int numAdd(int num) {

    if (num < 1) {

        return num;

    }

    num += numAdd(num - 1);

    return num;
}